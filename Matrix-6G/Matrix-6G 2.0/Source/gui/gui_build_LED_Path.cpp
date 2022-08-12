#include "gui_build_LED_Path.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_PathData.h"

using namespace Matrix_6G_Constants;

Path LED_Path::buildForChar(const uint8 charNum) {
	jassert(charNum < EP::numberOfChoicesForVoiceNameChar);
	auto charNumForSpace{ (uint8)32 };
	if (charNum <= charNumForSpace)
		return Path{};
	if (charNum > 95) {
		Path pathBar;
		pathBar.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		pathBar.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		return pathBar;
	}
	switch (charNum)
	{
	case 33: {
		Path path_ExclamationPoint;
		path_ExclamationPoint.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_ExclamationPoint.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_ExclamationPoint.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_ExclamationPoint.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		return path_ExclamationPoint;
	}
	case 34: {
		Path path_DoubleQuote;
		path_DoubleQuote.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_DoubleQuote.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		return path_DoubleQuote;
	}
	case 35: {
		Path path_HashSymbol;
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		path_HashSymbol.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_HashSymbol;
	}
	case 36: {
		Path path_$;
		path_$.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		path_$.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_$;
	}
	case 37: {
		Path path_PercentageSymbol;
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		path_PercentageSymbol.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_PercentageSymbol;
	}
	case 38: {
		Path path_Ampersand;
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_Ampersand.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_Ampersand;
	}
	case 39: {
		Path path_SingleQuote;
		path_SingleQuote.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		return path_SingleQuote;
	}
	case 40: {
		Path path_OpenParenthesis;
		path_OpenParenthesis.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_OpenParenthesis.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		return path_OpenParenthesis;
	}
	case 41: {
		Path path_CloseParenthesis;
		path_CloseParenthesis.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_CloseParenthesis.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_CloseParenthesis;
	}
	case 42: {
		Path path_Asterisk;
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		path_Asterisk.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_Asterisk;
	}
	case 43: {
		Path path_PlusSymbol;
		path_PlusSymbol.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_PlusSymbol.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_PlusSymbol.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		path_PlusSymbol.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_PlusSymbol;
	}
	case 44: {
		Path path_Comma;
		path_Comma.loadPathFromData(GUI::pathDataForSegment_O.data(), GUI::pathDataForSegment_O.size());
		path_Comma.loadPathFromData(GUI::pathDataForSegment_P.data(), GUI::pathDataForSegment_P.size());
		return path_Comma;
	}
	case 45: {
		Path path_Hyphen;
		path_Hyphen.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_Hyphen.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_Hyphen;
	}
	case 46: {
		Path path_Period;
		path_Period.loadPathFromData(GUI::pathDataForSegment_O.data(), GUI::pathDataForSegment_O.size());
		return path_Period;
	}
	case 47: {
		Path path_Slash;
		path_Slash.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_Slash.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_Slash;
	}
	case 48: {
		Path path_0;
		path_0.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_0.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_0;
	}
	case 49: {
		Path path_1;
		path_1.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_1.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_1;
	}
	case 50: {
		Path path_2;
		path_2.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_2.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_2.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_2.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_2.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_2.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_2;
	}
	case 51: {
		Path path_3;
		path_3.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_3.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_3.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_3.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_3.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_3.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_3;
	}
	case 52: {
		Path path_4;
		path_4.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_4.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_4.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_4.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_4.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_4;
	}
	case 53: {
		Path path_5;
		path_5.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_5.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_5.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_5.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_5.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_5.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_5;
	}
	case 54: {
		Path path_6;
		path_6.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_6.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_6.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_6.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_6.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_6.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_6.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_6;
	}
	case 55: {
		Path path_7;
		path_7.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_7.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_7.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		return path_7;
	}
	case 56: {
		Path path_8;
		path_8.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_8.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_8;
	}
	case 57: {
		Path path_9;
		path_9.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_9.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_9.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_9.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_9.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_9.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_9.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_9;
	}
	case 58: {
		Path path_Colon;
		path_Colon.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_Colon.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		return path_Colon;
	}
	case 59: {
		Path path_Semicolon;
		path_Semicolon.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_Semicolon.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_Semicolon;
	}
	case 60: {
		Path path_OpenAngledBracket;
		path_OpenAngledBracket.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_OpenAngledBracket.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_OpenAngledBracket.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_OpenAngledBracket;
	}
	case 61: {
		Path path_Equals;
		path_Equals.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_Equals.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_Equals.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_Equals;
	}
	case 62: {
		Path path_CloseAngledBracket;
		path_CloseAngledBracket.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_CloseAngledBracket.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_CloseAngledBracket.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		return path_CloseAngledBracket;
	}
	case 63: {
		Path path_QuestionMark;
		path_QuestionMark.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_QuestionMark.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_QuestionMark.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_QuestionMark.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_QuestionMark;
	}
	case 65: {
		Path path_A;
		path_A.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_A.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_A.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_A.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_A.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_A.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_A.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_A;
	}
	case 66: {
		Path path_B;
		path_B.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_B.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_B.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_B.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_B.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_B.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_B.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_B;
	}
	case 67: {
		Path path_C;
		path_C.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_C.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_C.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_C.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		return path_C;
	}
	case 68: {
		Path path_D;
		path_D.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_D.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_D.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_D.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_D.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_D.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_D;
	}
	case 69: {
		Path path_E;
		path_E.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_E.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_E.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_E.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_E.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_E;
	}
	case 70: {
		Path path_F;
		path_F.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_F.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_F.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_F.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_F;
	}
	case 71: {
		Path path_G;
		path_G.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_G.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_G.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_G.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_G.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_G.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		return path_G;
	}
	case 72: {
		Path path_H;
		path_H.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_H.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_H.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_H.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_H.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_H.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_H;
	}
	case 73: {
		Path path_I;
		path_I.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_I.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_I.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_I.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_I;
	}
	case 74: {
		Path path_J;
		path_J.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_J.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_J.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_J.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		return path_J;
	}
	case 75: {
		Path path_K;
		path_K.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_K.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_K.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_K.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_K.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_K;
	}
	case 76: {
		Path path_L;
		path_L.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_L.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_L.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		return path_L;
	}
	case 77: {
		Path path_M;
		path_M.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_M.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_M.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_M.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_M.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_M.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		return path_M;
	}
	case 78: {
		Path path_N;
		path_N.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_N.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_N.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_N.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_N.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_N.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		return path_N;
	}
	case 79: {
		Path path_O;
		path_O.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_O.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_O.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_O.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_O.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_O.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		return path_O;
	}
	case 80: {
		Path path_P;
		path_P.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_P.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_P.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_P.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_P.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_P.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_P;
	}
	case 81: {
		Path path_Q;
		path_Q.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_Q.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_Q.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_Q.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_Q.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_Q.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_Q.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		return path_Q;
	}
	case 82: {
		Path path_R;
		path_R.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_R.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_R.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_R.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_R.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_R.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_R.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_R;
	}
	case 83: {
		Path path_S;
		path_S.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_S.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_S.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_S.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_S.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
		path_S.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
		return path_S;
	}
	case 84: {
		Path path_T;
		path_T.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_T.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
		path_T.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_T;
	}
	case 85: {
		Path path_U;
		path_U.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_U.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_U.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_U.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_U.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		return path_U;
	}
	case 86: {
		Path path_V;
		path_V.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_V.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_V.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_V.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_V;
	}
	case 87: {
		Path path_W;
		path_W.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
		path_W.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
		path_W.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_W.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		path_W.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_W.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_W;
	}
	case 88: {
		Path path_X;
		path_X.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_X.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_X.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_X.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_X;
	}
	case 89: {
		Path path_Y;
		path_Y.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_Y.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_Y.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
		return path_Y;
	}
	case 90: {
		Path path_Z;
		path_Z.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_Z.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_Z.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
		path_Z.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_Z;
	}
	case 91: {
		Path path_OpenBracket;
		path_OpenBracket.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
		path_OpenBracket.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		path_OpenBracket.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
		path_OpenBracket.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
		return path_OpenBracket;
	}
	case 92: {
		Path path_Backslash;
		path_Backslash.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
		path_Backslash.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		return path_Backslash;
	}
	case 94: {
		Path path_Caret;
		path_Caret.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
		path_Caret.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
		return path_Caret;
	}
	case 95: {
		Path path_Underscore;
		path_Underscore.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
		return path_Underscore;
	}
	default:
		return Path{};
	}
}

Path LED_Path::buildChoiceNameForControl(const String choiceName, const int control_w) {
	Path choiceNamePath;
	auto lastCharacter_x{ control_w - GUI::ledDisplayRightSideInset - GUI::ledDisplayCharacter_w };
	auto lastCharacterIndex{ (int)choiceName.toStdString().size() - 1 };
	for (auto i = lastCharacterIndex; i != -1; --i) {
		auto charNum{ (uint8)choiceName[i] };
		auto character_x{ lastCharacter_x - (GUI::ledDisplayCharacter_w * (lastCharacterIndex - i)) };
		choiceNamePath.addPath(LED_Path::buildForChar(charNum), AffineTransform::translation((float)character_x, (float)GUI::ledDisplay_y));
	}
	return choiceNamePath;
}

Path LED_Path::buildForVertBar() {
	Path path_VertBar;
	path_VertBar.loadPathFromData(GUI::verticalBarPathData.data(), GUI::verticalBarPathData.size());
	return path_VertBar;
}

Path LED_Path::buildForSliderTab() {
	auto path_VertBar{ buildForVertBar() };
	Path tabPath;
	for (auto i = 0; i != 6; ++i) {
		tabPath.addPath(path_VertBar, AffineTransform::translation(i * 3.0f, 0.0f));
	}
	return tabPath;
}
