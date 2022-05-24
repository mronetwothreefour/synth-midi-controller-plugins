#pragma once

#include <JuceHeader.h>

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_PathData.h"

using namespace MophoConstants;



struct LCD_CharacterPath
{
	static Path buildForChar(uint8 charNum) {
		jassert(charNum < EP::numberOfChoicesForVoiceNameChar);
		auto charNumForSpace{ (uint8)32 };
		if (charNum <= charNumForSpace)
			return Path{};
		switch (charNum)
		{
		case (uint8)33: {
			Path path_ExclamationPoint;
			path_ExclamationPoint.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_ExclamationPoint.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_ExclamationPoint.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_ExclamationPoint.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_ExclamationPoint.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_ExclamationPoint;
		}
		case (uint8)34: {
			Path path_DoubleQuote;
			path_DoubleQuote.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_DoubleQuote.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_DoubleQuote.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_DoubleQuote.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_DoubleQuote.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_DoubleQuote.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			return path_DoubleQuote;
		}
		case (uint8)35: {
			Path path_HashSymbol;
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_HashSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_HashSymbol;
		}
		case (uint8)36: {
			Path path_$;
			path_$.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_$.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_$;
		}
		case (uint8)37: {
			Path path_PercentageSymbol;
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_PercentageSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_PercentageSymbol;
		}
		case (uint8)38: {
			Path path_Ampersand;
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_Ampersand.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_Ampersand;
		}
		case (uint8)39: {
			Path path_SingleQuote;
			path_SingleQuote.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_SingleQuote.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_SingleQuote.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_SingleQuote.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			return path_SingleQuote;
		}
		case (uint8)40: {
			Path path_OpenParenthesis;
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_OpenParenthesis.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_OpenParenthesis;
		}
		case (uint8)41: {
			Path path_CloseParenthesis;
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_CloseParenthesis.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_CloseParenthesis;
		}
		case (uint8)42: {
			Path path_Asterisk;
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_Asterisk.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			return path_Asterisk;
		}
		case (uint8)43: {
			Path path_PlusSymbol;
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_PlusSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			return path_PlusSymbol;
		}
		case (uint8)44: {
			Path path_Comma;
			path_Comma.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_Comma.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Comma.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_Comma.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_Comma;
		}
		case (uint8)45: {
			Path path_Hyphen;
			path_Hyphen.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_Hyphen.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_Hyphen.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_Hyphen.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_Hyphen.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			return path_Hyphen;
		}
		case (uint8)46: {
			Path path_Period;
			path_Period.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_Period.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_Period.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_Period.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_Period;
		}
		case (uint8)47: {
			Path path_Slash;
			path_Slash.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_Slash.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_Slash.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_Slash.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_Slash.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			return path_Slash;
		}
		case (uint8)48: {
			Path path_0;
			path_0.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_0.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_0;
		}
		case (uint8)49: {
			Path path_1;
			path_1.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_1.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_1;
		}
		case (uint8)50: {
			Path path_2;
			path_2.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_2.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_2;
		}
		case (uint8)51: {
			Path path_3;
			path_3.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_3.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_3;
		}
		case (uint8)52: {
			Path path_4;
			path_4.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_4.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_4;
		}
		case (uint8)53: {
			Path path_5;
			path_5.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_5.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_5;
		}
		case (uint8)54: {
			Path path_6;
			path_6.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_6.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_6;
		}
		case (uint8)55: {
			Path path_7;
			path_7.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_7.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_7;
		}
		case (uint8)56: {
			Path path_8;
			path_8.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_8.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_8;
		}
		case (uint8)57: {
			Path path_9;
			path_9.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_9.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_9;
		}
		case (uint8)58: {
			Path path_Colon;
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_Colon.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			return path_Colon;
		}
		case (uint8)59: {
			Path path_Semicolon;
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_Semicolon.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_Semicolon;
		}
		case (uint8)60: {
			Path path_OpenAngledBracket;
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_OpenAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_OpenAngledBracket;
		}
		case (uint8)61: {
			Path path_Equals;
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_Equals.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			return path_Equals;
		}
		case (uint8)62: {
			Path path_CloseAngledBracket;
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_CloseAngledBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_CloseAngledBracket;
		}
		case (uint8)63: {
			Path path_QuestionMark;
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_QuestionMark.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_QuestionMark;
		}
		case (uint8)64: {
			Path path_AtSymbol;
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_AtSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_AtSymbol;
		}
		case (uint8)65: {
			Path path_A;
			path_A.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_A.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_A;
		}
		case (uint8)66: {
			Path path_B;
			path_B.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_B.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			return path_B;
		}
		case (uint8)67: {
			Path path_C;
			path_C.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_C.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_C;
		}
		case (uint8)68: {
			Path path_D;
			path_D.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_D.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_D;
		}
		case (uint8)69: {
			Path path_E;
			path_E.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_E.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_E;
		}
		case (uint8)70: {
			Path path_F;
			path_F.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_F.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			return path_F;
		}
		case (uint8)71: {
			Path path_G;
			path_G.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_G.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_G;
		}
		case (uint8)72: {
			Path path_H;
			path_H.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_H.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_H;
		}
		case (uint8)73: {
			Path path_I;
			path_I.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_I.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_I;
		}
		case (uint8)74: {
			Path path_J;
			path_J.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_J.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_J;
		}
		case (uint8)75: {
			Path path_K;
			path_K.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_K.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_K;
		}
		case (uint8)76: {
			Path path_L;
			path_L.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_L.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_L;
		}
		case (uint8)77: {
			Path path_M;
			path_M.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_M.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_M;
		}
		case (uint8)78: {
			Path path_N;
			path_N.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_N.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_N;
		}
		case (uint8)79: {
			Path path_O;
			path_O.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_O.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_O;
		}
		case (uint8)80: {
			Path path_P;
			path_P.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_P.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			return path_P;
		}
		case (uint8)81: {
			Path path_Q;
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_Q.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_Q;
		}
		case (uint8)82: {
			Path path_R;
			path_R.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_R.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_R;
		}
		case (uint8)83: {
			Path path_S;
			path_S.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_S.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_S;
		}
		case (uint8)84: {
			Path path_T;
			path_T.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_T.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_T;
		}
		case (uint8)85: {
			Path path_U;
			path_U.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_U.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_U;
		}
		case (uint8)86: {
			Path path_V;
			path_V.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_V.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_V;
		}
		case (uint8)87: {
			Path path_W;
			path_W.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_W.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_W;
		}
		case (uint8)88: {
			Path path_X;
			path_X.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_X.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_X;
		}
		case (uint8)89: {
			Path path_Y;
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_Y.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_Y;
		}
		case (uint8)90: {
			Path path_Z;
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_Z.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_Z;
		}
		case (uint8)91: {
			Path path_OpenBracket;
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_OpenBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_OpenBracket;
		}
		case (uint8)92: {
			Path path_YenSymbol;
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_YenSymbol.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_YenSymbol;
		}
		case (uint8)93: {
			Path path_CloseBracket;
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_CloseBracket.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_CloseBracket;
		}
		case (uint8)94: {
			Path path_Caret;
			path_Caret.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_Caret.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_Caret.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_Caret.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_Caret.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			return path_Caret;
		}
		case (uint8)95: {
			Path path_Underscore;
			path_Underscore.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_Underscore.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_Underscore.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_Underscore.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_Underscore.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_Underscore;
		}
		case (uint8)96: {
			Path path_GraveAccent;
			path_GraveAccent.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_GraveAccent.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_GraveAccent.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			return path_GraveAccent;
		}
		case (uint8)97: {
			Path path_a;
			path_a.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_a.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_a;
		}
		case (uint8)98: {
			Path path_b;
			path_b.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_b.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_b;
		}
		case (uint8)99: {
			Path path_c;
			path_c.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_c.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_c;
		}
		case (uint8)100: {
			Path path_d;
			path_d.loadPathFromData(GUI::pathDataForPixel_Row1Col5.data(), GUI::pathDataForPixel_Row1Col5.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_d.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_d;
		}
		case (uint8)101: {
			Path path_e;
			path_e.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_e.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_e;
		}
		case (uint8)102: {
			Path path_f;
			path_f.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_f.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_f;
		}
		case (uint8)103: {
			Path path_g;
			path_g.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row2Col4.data(), GUI::pathDataForPixel_Row2Col4.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row2Col5.data(), GUI::pathDataForPixel_Row2Col5.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_g.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_g;
		}
		case (uint8)104: {
			Path path_h;
			path_h.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_h.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_h;
		}
		case (uint8)105: {
			Path path_i;
			path_i.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_i.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_i.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_i.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_i.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_i.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_i.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_i;
		}
		case (uint8)106: {
			Path path_j;
			path_j.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_j.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_j;
		}
		case (uint8)107: {
			Path path_k;
			path_k.loadPathFromData(GUI::pathDataForPixel_Row1Col1.data(), GUI::pathDataForPixel_Row1Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row2Col1.data(), GUI::pathDataForPixel_Row2Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_k.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_k;
		}
		case (uint8)108: {
			Path path_l;
			path_l.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_l.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_l;
		}
		case (uint8)109: {
			Path path_m;
			path_m.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_m.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_m;
		}
		case (uint8)110: {
			Path path_n;
			path_n.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_n.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_n;
		}
		case (uint8)111: {
			Path path_o;
			path_o.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_o.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_o;
		}
		case (uint8)112: {
			Path path_p;
			path_p.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_p.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			return path_p;
		}
		case (uint8)113: {
			Path path_q;
			path_q.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_q.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_q;
		}
		case (uint8)114: {
			Path path_r;
			path_r.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_r.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			return path_r;
		}
		case (uint8)115: {
			Path path_s;
			path_s.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_s.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_s;
		}
		case (uint8)116: {
			Path path_t;
			path_t.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row2Col2.data(), GUI::pathDataForPixel_Row2Col2.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_t.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_t;
		}
		case (uint8)117: {
			Path path_u;
			path_u.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_u.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_u;
		}
		case (uint8)118: {
			Path path_v;
			path_v.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_v.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_v;
		}
		case (uint8)119: {
			Path path_w;
			path_w.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row5Col1.data(), GUI::pathDataForPixel_Row5Col1.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row6Col1.data(), GUI::pathDataForPixel_Row6Col1.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_w.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_w;
		}
		case (uint8)120: {
			Path path_x;
			path_x.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row6Col4.data(), GUI::pathDataForPixel_Row6Col4.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_x.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_x;
		}
		case (uint8)121: {
			Path path_y;
			path_y.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row5Col5.data(), GUI::pathDataForPixel_Row5Col5.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row6Col5.data(), GUI::pathDataForPixel_Row6Col5.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_y.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_y;
		}
		case (uint8)122: {
			Path path_z;
			path_z.loadPathFromData(GUI::pathDataForPixel_Row3Col1.data(), GUI::pathDataForPixel_Row3Col1.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row3Col5.data(), GUI::pathDataForPixel_Row3Col5.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row6Col2.data(), GUI::pathDataForPixel_Row6Col2.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row7Col1.data(), GUI::pathDataForPixel_Row7Col1.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			path_z.loadPathFromData(GUI::pathDataForPixel_Row7Col5.data(), GUI::pathDataForPixel_Row7Col5.size());
			return path_z;
		}
		case (uint8)123: {
			Path path_OpenBrace;
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row1Col4.data(), GUI::pathDataForPixel_Row1Col4.size());
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_OpenBrace.loadPathFromData(GUI::pathDataForPixel_Row7Col4.data(), GUI::pathDataForPixel_Row7Col4.size());
			return path_OpenBrace;
		}
		case (uint8)124: {
			Path path_Bar;
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row1Col3.data(), GUI::pathDataForPixel_Row1Col3.size());
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_Bar.loadPathFromData(GUI::pathDataForPixel_Row7Col3.data(), GUI::pathDataForPixel_Row7Col3.size());
			return path_Bar;
		}
		case (uint8)125: {
			Path path_CloseBrace;
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row1Col2.data(), GUI::pathDataForPixel_Row1Col2.size());
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row3Col3.data(), GUI::pathDataForPixel_Row3Col3.size());
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row5Col3.data(), GUI::pathDataForPixel_Row5Col3.size());
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			path_CloseBrace.loadPathFromData(GUI::pathDataForPixel_Row7Col2.data(), GUI::pathDataForPixel_Row7Col2.size());
			return path_CloseBrace;
		}
		case (uint8)126: {
			Path path_RightArrow;
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row3Col4.data(), GUI::pathDataForPixel_Row3Col4.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row5Col4.data(), GUI::pathDataForPixel_Row5Col4.size());
			path_RightArrow.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			return path_RightArrow;
		}
		case (uint8)127: {
			Path path_LeftArrow;
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row2Col3.data(), GUI::pathDataForPixel_Row2Col3.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row3Col2.data(), GUI::pathDataForPixel_Row3Col2.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col1.data(), GUI::pathDataForPixel_Row4Col1.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col2.data(), GUI::pathDataForPixel_Row4Col2.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col3.data(), GUI::pathDataForPixel_Row4Col3.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col4.data(), GUI::pathDataForPixel_Row4Col4.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row4Col5.data(), GUI::pathDataForPixel_Row4Col5.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row5Col2.data(), GUI::pathDataForPixel_Row5Col2.size());
			path_LeftArrow.loadPathFromData(GUI::pathDataForPixel_Row6Col3.data(), GUI::pathDataForPixel_Row6Col3.size());
			return path_LeftArrow;
		}
		default:
			return Path{};
		}
	};
};
