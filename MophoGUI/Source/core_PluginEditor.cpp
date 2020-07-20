#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    mophoguiLogo.reset(new MainWindowDivision_Logo());
    addAndMakeVisible(mophoguiLogo.get());

    auto& controls{ ControlsForExposedParameters::get() };
    controls.rebuildControls();
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(InfoForExposedParameters::get().ctrlCenterPointFor(param));
    }

    envelopeRenderer_LPF.reset(new EnvelopeRenderer("lpf", exposedParams));
    envelopeRenderer_VCA.reset(new EnvelopeRenderer("vca", exposedParams));
    envelopeRenderer_Env3.reset(new EnvelopeRenderer("env3", exposedParams));
    addAndMakeVisible(envelopeRenderer_LPF.get());
    addAndMakeVisible(envelopeRenderer_VCA.get());
    addAndMakeVisible(envelopeRenderer_Env3.get());

    pgmNameEditor.reset(new Label("pgmNameEditor", getPgmName()));
    pgmNameEditor->setInterceptsMouseClicks(false, true);
    pgmNameEditor->setComponentID("pgmNameEditor");
    pgmNameEditor->setJustificationType(Justification::centredLeft);
    pgmNameEditor->setColour(Label::backgroundColourId, Colours::transparentBlack);
    pgmNameEditor->setColour(Label::outlineColourId, Colours::transparentBlack);
    pgmNameEditor->setColour(Label::textWhenEditingColourId, Color::controlText);
    pgmNameEditor->setColour(Label::backgroundWhenEditingColourId, Color::black);
    pgmNameEditor->setColour(Label::outlineWhenEditingColourId, Color::black);
    pgmNameEditor->addListener(this);
    addAndMakeVisible(pgmNameEditor.get());

    button_EditPgmName.reset(new TextButton("EDIT"));
    addAndMakeVisible(button_EditPgmName.get());
    String tooltipString;
    tooltipString =  "Opens an editor where you can\n";
    tooltipString += "type in a new program name.\n";
    button_EditPgmName->setTooltip(tooltipString);
    button_EditPgmName->onClick = [this] { showPgmNameEditor(); };

    auto& tooltipOptions{ TooltipOptions_Singleton::get() };
    tooltipOptions.addListener(this);
    auto tooltipsDelay{ (int)tooltipOptions.getProperty(ID::tooltips_DelayInMilliseconds) };
    tooltipWindow.setMillisecondsBeforeTipAppears(tooltipsDelay);
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
    setResizable(false, false);
}

PluginEditor::~PluginEditor() {
    auto& tooltipOptions{ TooltipOptions_Singleton::get() };
    tooltipOptions.removeListener(this);

    pgmNameEditor->removeListener(this);

    button_EditPgmName = nullptr;
    pgmNameEditor = nullptr;
    envelopeRenderer_Env3 = nullptr;
    envelopeRenderer_VCA = nullptr;
    envelopeRenderer_LPF = nullptr;

    auto& controls{ ControlsForExposedParameters::get() };
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        control->deleteAttachment();
    }

    controls.clear();

    mophoguiLogo = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
}

String PluginEditor::getPgmName() {
    auto& info{ InfoForExposedParameters::get() };
    std::string pgmName{ "" };
    for (auto i = 1; i != 17; ++i) {
        auto paramIndex{ info.indexFor("nameChar" + (String)i) };
        auto param{ processor.getParameters()[paramIndex] };
        pgmName += std::string(1, char(roundToInt(param->getValue() * 127)));
    }
    return pgmName;
}

void PluginEditor::showPgmNameEditor() {
    pgmNameEditor->showEditor();
    // restrict editor input to maximum 16 basic ASCII characters
    pgmNameEditor->getCurrentTextEditor()->setInputRestrictions(16,
        " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    String nameEditorTooltip;
    nameEditorTooltip =  "Type in a new name for the program (max. 16 characters) and hit Enter to apply it.\n";
    nameEditorTooltip += "Hit Esc to cancel. The Mopho's hardware LCD characters use the basic ASCII\n";
    nameEditorTooltip += "character set, with a few exceptions: 'backslash' becomes a yen sign and 'tilde'\n";
    nameEditorTooltip += "becomes a right arrow. The 'delete' character becomes a left arrow; obviously,\n";
    nameEditorTooltip += "you can't type that in the editor. However, you can access it by changing a\n";
    nameEditorTooltip += "character in the GUI's name display with the mouse. The hardware name display\n";
    nameEditorTooltip += "will not update immediately - press the Program Mode button to see the new name.";
    pgmNameEditor->getCurrentTextEditor()->setTooltip(nameEditorTooltip);
}

void PluginEditor::paint(Graphics& g) {
    g.fillAll(Color::device);
    g.setColour(Color::controlLabelText);
    auto& info{ InfoForMainWindowLabels::get() };
    for (uint16 label = 0; label != info.labelOutOfRange(); ++label) {
        Font font{ FontsDB::family_Global, FontsDB::style_ForControlLabels, info.fontSizeFor(label) };
        g.setFont(font);
        Rectangle<int> labelArea{ info.widthFor(label), info.heightFor(label) };
        labelArea.setCentre(info.centerPointFor(label));
        g.drawFittedText(info.textFor(label), labelArea, info.justificationFlagFor(label), 1, 1.0f);
    }
    g.drawHorizontalLine(85, 15.0f, 295.0f);
    Rectangle<int> pgmNameBackground{ 580, 33, 242, 37 };
    g.fillRect(pgmNameBackground);
}

void PluginEditor::resized() {
    mophoguiLogo->setBounds(836, 0, mophoguiLogo->getWidth(), mophoguiLogo->getHeight());
    auto envelopeRenderers_x{ 168 };
    envelopeRenderer_LPF->setBounds(envelopeRenderers_x, 154, envelopeRenderer_LPF->getWidth(), envelopeRenderer_LPF->getHeight());
    envelopeRenderer_VCA->setBounds(envelopeRenderers_x, 312, envelopeRenderer_VCA->getWidth(), envelopeRenderer_VCA->getHeight());
    envelopeRenderer_Env3->setBounds(envelopeRenderers_x, 470, envelopeRenderer_Env3->getWidth(), envelopeRenderer_Env3->getHeight());
    pgmNameEditor->setBounds(590, 43, 222, 18);
    button_EditPgmName->setBounds(705, 11, 42, 16);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property)
{
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto& tooltipOptions{ TooltipOptions_Singleton::get() };
        auto tooltipsDelay{ (int)tooltipOptions.getProperty(property) };
        tooltipWindow.setMillisecondsBeforeTipAppears(tooltipsDelay);
    }
}

void PluginEditor::labelTextChanged(Label* labelThatHasChanged) {
    if (labelThatHasChanged == pgmNameEditor.get())
    {
        String newName{ labelThatHasChanged->getText() };
        // if newName is less than 16 characters long, append
        // enough space characters to make the total length 16. 
        for (auto i = newName.length(); i < 16; ++i)
            newName += " ";
        processor.updateProgramName(newName);
    }
}
