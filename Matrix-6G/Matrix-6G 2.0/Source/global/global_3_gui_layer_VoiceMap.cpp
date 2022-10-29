#include "global_3_gui_layer_VoiceMap.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_VoiceMap::GUI_Layer_VoiceMap(UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	btn_Close{ BorderColor::orange, unexposedParams }
{
	btn_Close.setTopRightPosition(borderBounds.getRight(), borderBounds.getY());
	addAndMakeVisible(btn_Close);

	btn_Reset.setComponentID(ID::btn_Reset.toString());
	btn_Reset.onClick = [this, unexposedParams] { unexposedParams->getGlobalOptions()->resetVoiceMap(); };
	btn_Reset.setBounds(1013, 144, 40, 14);
	if (unexposedParams->getTooltipsOptions()->shouldShowDescription()) {
		String tip{ "" };
		tip += "Resets the Patch Map to the default state.\n";
		tip += "NOTE: Changes to the Patch Map will not\n";
		tip += "be updated on the hardware until the PUSH\n";
		tip += "button in the Master window is clicked.\n";
		btn_Reset.setTooltip(tip);
	}
	addAndMakeVisible(btn_Reset);

	for (uint8 slotNum = 0; slotNum != VCS::numberOfSlotsInVoicesBank; ++slotNum) {
		voiceMapSlots.push_back(std::make_unique<VoiceMapSlot>(slotNum, unexposedParams, undoManager));
		auto col_x{ 213 + ((slotNum / 10) * 87) };
		auto row_y{ 184 + ((slotNum % 10) * 28) };
		voiceMapSlots[slotNum]->setTopLeftPosition(col_x, row_y);
		addAndMakeVisible(voiceMapSlots[slotNum].get());
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_VoiceMap::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_VoiceMap_png, BinaryData::bkgrnd_VoiceMap_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, borderBounds.getX(), borderBounds.getY());
}

GUI_Layer_VoiceMap::~GUI_Layer_VoiceMap() {
	voiceMapSlots.clear();
}
