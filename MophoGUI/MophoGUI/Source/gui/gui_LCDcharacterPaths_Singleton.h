#pragma once

#include <JuceHeader.h>



class LCDcharacterPaths
{
	Array<Path> characterPaths;
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

	const std::vector<uint8> pathDataForPixel_Row1Col1;
	const std::vector<uint8> pathDataForPixel_Row1Col2;
	const std::vector<uint8> pathDataForPixel_Row1Col3;
	const std::vector<uint8> pathDataForPixel_Row1Col4;
	const std::vector<uint8> pathDataForPixel_Row1Col5;

	const std::vector<uint8> pathDataForPixel_Row2Col1;
	const std::vector<uint8> pathDataForPixel_Row2Col2;
	const std::vector<uint8> pathDataForPixel_Row2Col3;
	const std::vector<uint8> pathDataForPixel_Row2Col4;
	const std::vector<uint8> pathDataForPixel_Row2Col5;

	const std::vector<uint8> pathDataForPixel_Row3Col1;
	const std::vector<uint8> pathDataForPixel_Row3Col2;
	const std::vector<uint8> pathDataForPixel_Row3Col3;
	const std::vector<uint8> pathDataForPixel_Row3Col4;
	const std::vector<uint8> pathDataForPixel_Row3Col5;

	const std::vector<uint8> pathDataForPixel_Row4Col1;
	const std::vector<uint8> pathDataForPixel_Row4Col2;
	const std::vector<uint8> pathDataForPixel_Row4Col3;
	const std::vector<uint8> pathDataForPixel_Row4Col4;
	const std::vector<uint8> pathDataForPixel_Row4Col5;

	const std::vector<uint8> pathDataForPixel_Row5Col1;
	const std::vector<uint8> pathDataForPixel_Row5Col2;
	const std::vector<uint8> pathDataForPixel_Row5Col3;
	const std::vector<uint8> pathDataForPixel_Row5Col4;
	const std::vector<uint8> pathDataForPixel_Row5Col5;

	const std::vector<uint8> pathDataForPixel_Row6Col1;
	const std::vector<uint8> pathDataForPixel_Row6Col2;
	const std::vector<uint8> pathDataForPixel_Row6Col3;
	const std::vector<uint8> pathDataForPixel_Row6Col4;
	const std::vector<uint8> pathDataForPixel_Row6Col5;

	const std::vector<uint8> pathDataForPixel_Row7Col1;
	const std::vector<uint8> pathDataForPixel_Row7Col2;
	const std::vector<uint8> pathDataForPixel_Row7Col3;
	const std::vector<uint8> pathDataForPixel_Row7Col4;
	const std::vector<uint8> pathDataForPixel_Row7Col5;

	LCDcharacterPaths();
	void fillCharacterPaths();
	Path createPathForChar33_ExclamationPoint();
	Path createPathForChar34_DoubleQuote();
	Path createPathForChar35_HashSymbol();
	Path createPathForChar36_$();
	Path createPathForChar37_PercentageSymbol();
	Path createPathForChar38_Ampersand();
	Path createPathForChar39_SingleQuote();
	Path createPathForChar40_OpenParenthesis();
	Path createPathForChar41_CloseParenthesis();
	Path createPathForChar42_Asterisk();
	Path createPathForChar43_PlusSymbol();
	Path createPathForChar44_Comma();
	Path createPathForChar45_Hyphen();
	Path createPathForChar46_Period();
	Path createPathForChar47_Slash();
	Path createPathForChar48_0();
	Path createPathForChar49_1();
	Path createPathForChar50_2();
	Path createPathForChar51_3();
	Path createPathForChar52_4();
	Path createPathForChar53_5();
	Path createPathForChar54_6();
	Path createPathForChar55_7();
	Path createPathForChar56_8();
	Path createPathForChar57_9();
	Path createPathForChar58_Colon();
	Path createPathForChar59_Semicolon();
	Path createPathForChar60_OpenAngledBracket();
	Path createPathForChar61_Equals();
	Path createPathForChar62_CloseAngledBracket();
	Path createPathForChar63_QuestionMark();
	Path createPathForChar64_AtSymbol();
	Path createPathForChar65_A();
	Path createPathForChar66_B();

public:
	LCDcharacterPaths(LCDcharacterPaths&&) = delete;
	LCDcharacterPaths& operator=(LCDcharacterPaths&&) = delete;

	static LCDcharacterPaths& get() noexcept;
	Path getPathForChar(uint8 charNum);
	
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDcharacterPaths)
};