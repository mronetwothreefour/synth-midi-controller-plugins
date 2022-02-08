#pragma once

#include <JuceHeader.h>



class LCDcharacterPaths
{
	Array<Path> characterPaths;

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
	Path createPathForChar67_C();
	Path createPathForChar68_D();
	Path createPathForChar69_E();
	Path createPathForChar70_F();
	Path createPathForChar71_G();
	Path createPathForChar72_H();
	Path createPathForChar73_I();
	Path createPathForChar74_J();
	Path createPathForChar75_K();
	Path createPathForChar76_L();
	Path createPathForChar77_M();
	Path createPathForChar78_N();
	Path createPathForChar79_O();
	Path createPathForChar80_P();
	Path createPathForChar81_Q();
	Path createPathForChar82_R();
	Path createPathForChar83_S();
	Path createPathForChar84_T();
	Path createPathForChar85_U();
	Path createPathForChar86_V();
	Path createPathForChar87_W();
	Path createPathForChar88_X();
	Path createPathForChar89_Y();
	Path createPathForChar90_Z();
	Path createPathForChar91_OpenBracket();
	Path createPathForChar92_YenSymbol();
	Path createPathForChar93_CloseBracket();
	Path createPathForChar94_Caret();
	Path createPathForChar95_Underscore();
	Path createPathForChar96_GraveAccent();
	Path createPathForChar97_a();
	Path createPathForChar98_b();
	Path createPathForChar99_c();
	Path createPathForChar100_d();
	Path createPathForChar101_e();
	Path createPathForChar102_f();
	Path createPathForChar103_g();
	Path createPathForChar104_h();
	Path createPathForChar105_i();
	Path createPathForChar106_j();
	Path createPathForChar107_k();
	Path createPathForChar108_l();
	Path createPathForChar109_m();
	Path createPathForChar110_n();
	Path createPathForChar111_o();
	Path createPathForChar112_p();
	Path createPathForChar113_q();
	Path createPathForChar114_r();
	Path createPathForChar115_s();
	Path createPathForChar116_t();
	Path createPathForChar117_u();
	Path createPathForChar118_v();
	Path createPathForChar119_w();
	Path createPathForChar120_x();
	Path createPathForChar121_y();
	Path createPathForChar122_z();
	Path createPathForChar123_OpenBrace();
	Path createPathForChar124_Bar();
	Path createPathForChar125_CloseBrace();
	Path createPathForChar126_RightArrow();
	Path createPathForChar127_LeftArrow();

public:
	LCDcharacterPaths(LCDcharacterPaths&&) = delete;
	LCDcharacterPaths& operator=(LCDcharacterPaths&&) = delete;

	static LCDcharacterPaths& get() noexcept;
	Path getPathForChar(uint8 charNum);
	
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDcharacterPaths)
};