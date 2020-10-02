#pragma once

#include <JuceHeader.h>



class LCDcharacterPaths
{
	Array<Path> characterPaths;
	const std::vector<uint8> pathDataForChar33_ExclamationPoint;
	const std::vector<uint8> pathDataForChar34_DoubleQuote;
	const std::vector<uint8> pathDataForChar35_HashSymbol;
	const std::vector<uint8> pathDataForChar36_$;
	const std::vector<uint8> pathDataForChar37_PercentageSymbol;
	const std::vector<uint8> pathDataForChar38_Ampersand;
	const std::vector<uint8> pathDataForChar39_SingleQuote;
	const std::vector<uint8> pathDataForChar40_OpenParenthesis;
	const std::vector<uint8> pathDataForChar41_CloseParenthesis;
	const std::vector<uint8> pathDataForChar42_Asterisk;
	const std::vector<uint8> pathDataForChar43_PlusSymbol;
	const std::vector<uint8> pathDataForChar44_Comma;
	const std::vector<uint8> pathDataForChar45_Hyphen;
	const std::vector<uint8> pathDataForChar46_Period;
	const std::vector<uint8> pathDataForChar47_Slash;
	const std::vector<uint8> pathDataForChar48_0;
	const std::vector<uint8> pathDataForChar49_1;
	const std::vector<uint8> pathDataForChar50_2;
	const std::vector<uint8> pathDataForChar51_3;
	const std::vector<uint8> pathDataForChar52_4;
	const std::vector<uint8> pathDataForChar53_5;
	const std::vector<uint8> pathDataForChar54_6;
	const std::vector<uint8> pathDataForChar55_7;
	const std::vector<uint8> pathDataForChar56_8;
	const std::vector<uint8> pathDataForChar57_9;
	const std::vector<uint8> pathDataForChar58_Colon;
	const std::vector<uint8> pathDataForChar59_Semicolon;
	const std::vector<uint8> pathDataForChar60_OpenAngledBracket;
	const std::vector<uint8> pathDataForChar61_Equals;
	const std::vector<uint8> pathDataForChar62_CloseAngledBracket;
	const std::vector<uint8> pathDataForChar63_QuestionMark;
	const std::vector<uint8> pathDataForChar64_AtSymbol;
	const std::vector<uint8> pathDataForChar65_A;
	const std::vector<uint8> pathDataForChar66_B;
	const std::vector<uint8> pathDataForChar67_C;
	const std::vector<uint8> pathDataForChar68_D;
	const std::vector<uint8> pathDataForChar69_E;
	const std::vector<uint8> pathDataForChar70_F;
	const std::vector<uint8> pathDataForChar71_G;
	const std::vector<uint8> pathDataForChar72_H;
	const std::vector<uint8> pathDataForChar73_I;
	const std::vector<uint8> pathDataForChar74_J;
	const std::vector<uint8> pathDataForChar75_K;
	const std::vector<uint8> pathDataForChar76_L;
	const std::vector<uint8> pathDataForChar77_M;
	const std::vector<uint8> pathDataForChar78_N;
	const std::vector<uint8> pathDataForChar79_O;
	const std::vector<uint8> pathDataForChar80_P;
	const std::vector<uint8> pathDataForChar81_Q;
	const std::vector<uint8> pathDataForChar82_R;
	const std::vector<uint8> pathDataForChar83_S;
	const std::vector<uint8> pathDataForChar84_T;
	const std::vector<uint8> pathDataForChar85_U;
	const std::vector<uint8> pathDataForChar86_V;
	const std::vector<uint8> pathDataForChar87_W;
	const std::vector<uint8> pathDataForChar88_X;
	const std::vector<uint8> pathDataForChar89_Y;
	const std::vector<uint8> pathDataForChar90_Z;
	const std::vector<uint8> pathDataForChar91_OpenBracket;
	const std::vector<uint8> pathDataForChar92_YenSymbol;
	const std::vector<uint8> pathDataForChar93_CloseBracket;
	const std::vector<uint8> pathDataForChar94_Caret;
	const std::vector<uint8> pathDataForChar95_Underscore;
	const std::vector<uint8> pathDataForChar96_GraveAccent;
	const std::vector<uint8> pathDataForChar97_a;
	const std::vector<uint8> pathDataForChar98_b;
	const std::vector<uint8> pathDataForChar99_c;
	const std::vector<uint8> pathDataForChar100_d;
	const std::vector<uint8> pathDataForChar101_e;
	const std::vector<uint8> pathDataForChar102_f;
	const std::vector<uint8> pathDataForChar103_g;
	const std::vector<uint8> pathDataForChar104_h;
	const std::vector<uint8> pathDataForChar105_i;
	const std::vector<uint8> pathDataForChar106_j;
	const std::vector<uint8> pathDataForChar107_k;
	const std::vector<uint8> pathDataForChar108_l;
	const std::vector<uint8> pathDataForChar109_m;
	const std::vector<uint8> pathDataForChar110_n;
	const std::vector<uint8> pathDataForChar111_o;
	const std::vector<uint8> pathDataForChar112_p;
	const std::vector<uint8> pathDataForChar113_q;
	const std::vector<uint8> pathDataForChar114_r;
	const std::vector<uint8> pathDataForChar115_s;
	const std::vector<uint8> pathDataForChar116_t;
	const std::vector<uint8> pathDataForChar117_u;
	const std::vector<uint8> pathDataForChar118_v;
	const std::vector<uint8> pathDataForChar119_w;
	const std::vector<uint8> pathDataForChar120_x;
	const std::vector<uint8> pathDataForChar121_y;
	const std::vector<uint8> pathDataForChar122_z;
	const std::vector<uint8> pathDataForChar123_OpenBrace;
	const std::vector<uint8> pathDataForChar124_Bar;
	const std::vector<uint8> pathDataForChar125_CloseBrace;
	const std::vector<uint8> pathDataForChar126_RightArrow;
	const std::vector<uint8> pathDataForChar127_LeftArrow;

	LCDcharacterPaths();
	void fillCharacterPaths();

public:
	LCDcharacterPaths(LCDcharacterPaths&&) = delete;
	LCDcharacterPaths& operator=(LCDcharacterPaths&&) = delete;

	static LCDcharacterPaths& get() noexcept;
	Path getPathForChar(uint8 charNum);
	
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDcharacterPaths)
};