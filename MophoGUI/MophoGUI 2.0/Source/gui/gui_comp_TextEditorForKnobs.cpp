#include "gui_comp_TextEditorForKnobs.h"

TextEditorForKnobs::TextEditorForKnobs(RangeType rangeType, uint8 currentChoiceNum) :
	rangeType{ rangeType }
{
	switch (rangeType)
	{
	case RangeType::fineTune:
		break;
	case RangeType::globalFineTune:
		break;
	case RangeType::lfoFrequencies:
		break;
	case RangeType::oscShapes:
		break;
	case RangeType::oscSlop:
		maxValue = 5;
		onEditorShow = [this, currentChoiceNum] {
			auto editor{ getCurrentTextEditor() };
			editor->setInputRestrictions(1, "012345");
			editor->setText((String)currentChoiceNum);
		};
		break;
	case RangeType::pitches:
		break;
	case RangeType::posNeg_127:
		break;
	case RangeType::posNumbers:
		break;
	default:
		break;
	}
}
