#include "gui_LCDcharacterPaths_Singleton.h"



LCDcharacterPaths::LCDcharacterPaths() :
	pathDataForPixel_Row1Col1{ 110,109,0,0,0,64,0,0,0,64,108,0,0,0,0,0,0,0,64,108,0,0,0,0,0,0,0,0,108,0,0,0,64,0,0,0,0,108,0,0,0,64,0,0,0,64,99,101,0,0 },
	pathDataForPixel_Row1Col2{ 110,109,0,0,144,64,0,0,0,64,108,0,0,32,64,0,0,0,64,108,0,0,32,64,0,0,0,0,108,0,0,144,64,0,0,0,0,108,0,0,144,64,0,0,0,64,99,101,0,0 },
	pathDataForPixel_Row1Col3{ 110,109,0,0,224,64,0,0,0,64,108,0,0,160,64,0,0,0,64,108,0,0,160,64,0,0,0,0,108,0,0,224,64,0,0,0,0,108,0,0,224,64,0,0,0,64,99,101,0,0 },
	pathDataForPixel_Row1Col4{ 110,109,0,0,24,65,0,0,0,64,108,0,0,240,64,0,0,0,64,108,0,0,240,64,0,0,0,0,108,0,0,24,65,0,0,0,0,108,0,0,24,65,0,0,0,64,99,101,0,0 },
	pathDataForPixel_Row1Col5{ 110,109,0,0,64,65,0,0,0,64,108,0,0,32,65,0,0,0,64,108,0,0,32,65,0,0,0,0,108,0,0,64,65,0,0,0,0,108,0,0,64,65,0,0,0,64,99,101,0,0 },

	pathDataForPixel_Row2Col1{ 110,109,0,0,0,64,0,0,144,64,108,0,0,0,0,0,0,144,64,108,0,0,0,0,0,0,32,64,108,0,0,0,64,0,0,32,64,108,0,0,0,64,0,0,144,64,99,101,0,0 },
	pathDataForPixel_Row2Col2{ 110,109,0,0,144,64,0,0,144,64,108,0,0,32,64,0,0,144,64,108,0,0,32,64,0,0,32,64,108,0,0,144,64,0,0,32,64,108,0,0,144,64,0,0,144,64,99,101,0,0 },
	pathDataForPixel_Row2Col3{ 110,109,0,0,224,64,0,0,144,64,108,0,0,160,64,0,0,144,64,108,0,0,160,64,0,0,32,64,108,0,0,224,64,0,0,32,64,108,0,0,224,64,0,0,144,64,99,101,0,0 },
	pathDataForPixel_Row2Col4{ 110,109,0,0,24,65,0,0,144,64,108,0,0,240,64,0,0,144,64,108,0,0,240,64,0,0,32,64,108,0,0,24,65,0,0,32,64,108,0,0,24,65,0,0,144,64,99,101,0,0 },
	pathDataForPixel_Row2Col5{ 110,109,0,0,64,65,0,0,144,64,108,0,0,32,65,0,0,144,64,108,0,0,32,65,0,0,32,64,108,0,0,64,65,0,0,32,64,108,0,0,64,65,0,0,144,64,99,101,0,0 },

	pathDataForPixel_Row3Col1{ 110,109,0,0,0,64,0,0,224,64,108,0,0,0,0,0,0,224,64,108,0,0,0,0,0,0,160,64,108,0,0,0,64,0,0,160,64,108,0,0,0,64,0,0,224,64,99,101,0,0 },
	pathDataForPixel_Row3Col2{ 110,109,0,0,144,64,0,0,224,64,108,0,0,32,64,0,0,224,64,108,0,0,32,64,0,0,160,64,108,0,0,144,64,0,0,160,64,108,0,0,144,64,0,0,224,64,99,101,0,0 },
	pathDataForPixel_Row3Col3{ 110,109,0,0,224,64,0,0,224,64,108,0,0,160,64,0,0,224,64,108,0,0,160,64,0,0,160,64,108,0,0,224,64,0,0,160,64,108,0,0,224,64,0,0,224,64,99,101,0,0 },
	pathDataForPixel_Row3Col4{ 110,109,0,0,24,65,0,0,224,64,108,0,0,240,64,0,0,224,64,108,0,0,240,64,0,0,160,64,108,0,0,24,65,0,0,160,64,108,0,0,24,65,0,0,224,64,99,101,0,0 },
	pathDataForPixel_Row3Col5{ 110,109,0,0,64,65,0,0,224,64,108,0,0,32,65,0,0,224,64,108,0,0,32,65,0,0,160,64,108,0,0,64,65,0,0,160,64,108,0,0,64,65,0,0,224,64,99,101,0,0 },

	pathDataForPixel_Row4Col1{ 110,109,0,0,0,64,0,0,24,65,108,0,0,0,0,0,0,24,65,108,0,0,0,0,0,0,240,64,108,0,0,0,64,0,0,240,64,108,0,0,0,64,0,0,24,65,99,101,0,0 },
	pathDataForPixel_Row4Col2{ 110,109,0,0,144,64,0,0,24,65,108,0,0,32,64,0,0,24,65,108,0,0,32,64,0,0,240,64,108,0,0,144,64,0,0,240,64,108,0,0,144,64,0,0,24,65,99,101,0,0 },
	pathDataForPixel_Row4Col3{ 110,109,0,0,224,64,0,0,24,65,108,0,0,160,64,0,0,24,65,108,0,0,160,64,0,0,240,64,108,0,0,224,64,0,0,240,64,108,0,0,224,64,0,0,24,65,99,101,0,0 },
	pathDataForPixel_Row4Col4{ 110,109,0,0,24,65,0,0,24,65,108,0,0,240,64,0,0,24,65,108,0,0,240,64,0,0,240,64,108,0,0,24,65,0,0,240,64,108,0,0,24,65,0,0,24,65,99,101,0,0 },
	pathDataForPixel_Row4Col5{ 110,109,0,0,64,65,0,0,24,65,108,0,0,32,65,0,0,24,65,108,0,0,32,65,0,0,240,64,108,0,0,64,65,0,0,240,64,108,0,0,64,65,0,0,24,65,99,101,0,0 },

	pathDataForPixel_Row5Col1{ 110,109,0,0,0,64,0,0,64,65,108,0,0,0,0,0,0,64,65,108,0,0,0,0,0,0,32,65,108,0,0,0,64,0,0,32,65,108,0,0,0,64,0,0,64,65,99,101,0,0 },
	pathDataForPixel_Row5Col2{ 110,109,0,0,144,64,0,0,64,65,108,0,0,32,64,0,0,64,65,108,0,0,32,64,0,0,32,65,108,0,0,144,64,0,0,32,65,108,0,0,144,64,0,0,64,65,99,101,0,0 },
	pathDataForPixel_Row5Col3{ 110,109,0,0,224,64,0,0,64,65,108,0,0,160,64,0,0,64,65,108,0,0,160,64,0,0,32,65,108,0,0,224,64,0,0,32,65,108,0,0,224,64,0,0,64,65,99,101,0,0 },
	pathDataForPixel_Row5Col4{ 110,109,0,0,24,65,0,0,64,65,108,0,0,240,64,0,0,64,65,108,0,0,240,64,0,0,32,65,108,0,0,24,65,0,0,32,65,108,0,0,24,65,0,0,64,65,99,101,0,0 },
	pathDataForPixel_Row5Col5{ 110,109,0,0,64,65,0,0,64,65,108,0,0,32,65,0,0,64,65,108,0,0,32,65,0,0,32,65,108,0,0,64,65,0,0,32,65,108,0,0,64,65,0,0,64,65,99,101,0,0 },

	pathDataForPixel_Row6Col1{ 110,109,0,0,0,64,0,0,104,65,108,0,0,0,0,0,0,104,65,108,0,0,0,0,0,0,72,65,108,0,0,0,64,0,0,72,65,108,0,0,0,64,0,0,104,65,99,101,0,0 },
	pathDataForPixel_Row6Col2{ 110,109,0,0,144,64,0,0,104,65,108,0,0,32,64,0,0,104,65,108,0,0,32,64,0,0,72,65,108,0,0,144,64,0,0,72,65,108,0,0,144,64,0,0,104,65,99,101,0,0 },
	pathDataForPixel_Row6Col3{ 110,109,0,0,224,64,0,0,104,65,108,0,0,160,64,0,0,104,65,108,0,0,160,64,0,0,72,65,108,0,0,224,64,0,0,72,65,108,0,0,224,64,0,0,104,65,99,101,0,0 },
	pathDataForPixel_Row6Col4{ 110,109,0,0,24,65,0,0,104,65,108,0,0,240,64,0,0,104,65,108,0,0,240,64,0,0,72,65,108,0,0,24,65,0,0,72,65,108,0,0,24,65,0,0,104,65,99,101,0,0 },
	pathDataForPixel_Row6Col5{ 110,109,0,0,64,65,0,0,104,65,108,0,0,32,65,0,0,104,65,108,0,0,32,65,0,0,72,65,108,0,0,64,65,0,0,72,65,108,0,0,64,65,0,0,104,65,99,101,0,0 },

	pathDataForPixel_Row7Col1{ 110,109,0,0,0,64,0,0,136,65,108,0,0,0,0,0,0,136,65,108,0,0,0,0,0,0,112,65,108,0,0,0,64,0,0,112,65,108,0,0,0,64,0,0,136,65,99,101,0,0 },
	pathDataForPixel_Row7Col2{ 110,109,0,0,144,64,0,0,136,65,108,0,0,32,64,0,0,136,65,108,0,0,32,64,0,0,112,65,108,0,0,144,64,0,0,112,65,108,0,0,144,64,0,0,136,65,99,101,0,0 },
	pathDataForPixel_Row7Col3{ 110,109,0,0,224,64,0,0,136,65,108,0,0,160,64,0,0,136,65,108,0,0,160,64,0,0,112,65,108,0,0,224,64,0,0,112,65,108,0,0,224,64,0,0,136,65,99,101,0,0 },
	pathDataForPixel_Row7Col4{ 110,109,0,0,24,65,0,0,136,65,108,0,0,240,64,0,0,136,65,108,0,0,240,64,0,0,112,65,108,0,0,24,65,0,0,112,65,108,0,0,24,65,0,0,136,65,99,101,0,0 },
	pathDataForPixel_Row7Col5{ 110,109,0,0,64,65,0,0,136,65,108,0,0,32,65,0,0,136,65,108,0,0,32,65,0,0,112,65,108,0,0,64,65,0,0,112,65,108,0,0,64,65,0,0,136,65,99,101,0,0 }
{
	fillCharacterPaths();
}

void LCDcharacterPaths::fillCharacterPaths() {
	Path emptyPath;
	// ASCII characters 0..31 are invisible control characters
	// ASCII character 32 is a space
	for (auto character = 0; character != 33; ++character)
		characterPaths.add(emptyPath);
	Path path;
	characterPaths.add(createPathForChar33_ExclamationPoint());
	characterPaths.add(createPathForChar34_DoubleQuote());
	characterPaths.add(createPathForChar35_HashSymbol());
	characterPaths.add(createPathForChar36_$());
	characterPaths.add(createPathForChar37_PercentageSymbol());
	characterPaths.add(createPathForChar38_Ampersand());
	characterPaths.add(createPathForChar39_SingleQuote());
	characterPaths.add(createPathForChar40_OpenParenthesis());
	characterPaths.add(createPathForChar41_CloseParenthesis());
	characterPaths.add(createPathForChar42_Asterisk());
	characterPaths.add(createPathForChar43_PlusSymbol());
	characterPaths.add(createPathForChar44_Comma());
	characterPaths.add(createPathForChar45_Hyphen());
	characterPaths.add(createPathForChar46_Period());
	characterPaths.add(createPathForChar47_Slash());
	characterPaths.add(createPathForChar48_0());
	characterPaths.add(createPathForChar49_1());
	characterPaths.add(createPathForChar50_2());
	characterPaths.add(createPathForChar51_3());
	characterPaths.add(createPathForChar52_4());
	characterPaths.add(createPathForChar53_5());
	characterPaths.add(createPathForChar54_6());
	characterPaths.add(createPathForChar55_7());
	characterPaths.add(createPathForChar56_8());
	characterPaths.add(createPathForChar57_9());
	characterPaths.add(createPathForChar58_Colon());
	characterPaths.add(createPathForChar59_Semicolon());
	characterPaths.add(createPathForChar60_OpenAngledBracket());
	characterPaths.add(createPathForChar61_Equals());
	characterPaths.add(createPathForChar62_CloseAngledBracket());
	characterPaths.add(createPathForChar63_QuestionMark());
	characterPaths.add(createPathForChar64_AtSymbol());
	characterPaths.add(createPathForChar65_A());
	characterPaths.add(createPathForChar66_B());
	characterPaths.add(createPathForChar67_C());
	characterPaths.add(createPathForChar68_D());
	characterPaths.add(createPathForChar69_E());
	characterPaths.add(createPathForChar70_F());
	characterPaths.add(createPathForChar71_G());
	characterPaths.add(createPathForChar72_H());
	characterPaths.add(createPathForChar73_I());
	characterPaths.add(createPathForChar74_J());
	characterPaths.add(createPathForChar75_K());
	characterPaths.add(createPathForChar76_L());
	characterPaths.add(createPathForChar77_M());
	characterPaths.add(createPathForChar78_N());
	characterPaths.add(createPathForChar79_O());
	characterPaths.add(createPathForChar80_P());
	characterPaths.add(createPathForChar81_Q());
	characterPaths.add(createPathForChar82_R());
	characterPaths.add(createPathForChar83_S());
	characterPaths.add(createPathForChar84_T());
	characterPaths.add(createPathForChar85_U());
	characterPaths.add(createPathForChar86_V());
	characterPaths.add(createPathForChar87_W());
	characterPaths.add(createPathForChar88_X());
	characterPaths.add(createPathForChar89_Y());
	characterPaths.add(createPathForChar90_Z());
	characterPaths.add(createPathForChar91_OpenBracket());
	characterPaths.add(createPathForChar92_YenSymbol());
	characterPaths.add(createPathForChar93_CloseBracket());
	characterPaths.add(createPathForChar94_Caret());
	characterPaths.add(createPathForChar95_Underscore());
	characterPaths.add(createPathForChar96_GraveAccent());
	characterPaths.add(createPathForChar97_a());
	characterPaths.add(createPathForChar98_b());
	characterPaths.add(createPathForChar99_c());
	characterPaths.add(createPathForChar100_d());
	characterPaths.add(createPathForChar101_e());
	characterPaths.add(createPathForChar102_f());
	characterPaths.add(createPathForChar103_g());
	characterPaths.add(createPathForChar104_h());
	characterPaths.add(createPathForChar105_i());
	characterPaths.add(createPathForChar106_j());
	characterPaths.add(createPathForChar107_k());
	characterPaths.add(createPathForChar108_l());
	characterPaths.add(createPathForChar109_m());
	characterPaths.add(createPathForChar110_n());
	characterPaths.add(createPathForChar111_o());
	characterPaths.add(createPathForChar112_p());
	characterPaths.add(createPathForChar113_q());
	characterPaths.add(createPathForChar114_r());
	characterPaths.add(createPathForChar115_s());
	characterPaths.add(createPathForChar116_t());
	characterPaths.add(createPathForChar117_u());
	characterPaths.add(createPathForChar118_v());
	characterPaths.add(createPathForChar119_w());
	characterPaths.add(createPathForChar120_x());
	characterPaths.add(createPathForChar121_y());
	characterPaths.add(createPathForChar122_z());
	characterPaths.add(createPathForChar123_OpenBrace());
	characterPaths.add(createPathForChar124_Bar());
	characterPaths.add(createPathForChar125_CloseBrace());
	characterPaths.add(createPathForChar126_RightArrow());
	characterPaths.add(createPathForChar127_LeftArrow());
}

Path LCDcharacterPaths::createPathForChar33_ExclamationPoint() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar34_DoubleQuote() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar35_HashSymbol() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar36_$() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar37_PercentageSymbol() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar38_Ampersand() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar39_SingleQuote() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar40_OpenParenthesis() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar41_CloseParenthesis() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar42_Asterisk() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar43_PlusSymbol() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar44_Comma() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar45_Hyphen() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar46_Period() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar47_Slash() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar48_0() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar49_1() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar50_2() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar51_3() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar52_4() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar53_5() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar54_6() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar55_7() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar56_8() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar57_9() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar58_Colon() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar59_Semicolon() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar60_OpenAngledBracket() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar61_Equals() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar62_CloseAngledBracket() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar63_QuestionMark() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar64_AtSymbol() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar65_A() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar66_B()
{
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row1Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar67_C() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar68_D() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar69_E() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar70_F() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar71_G() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar72_H() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar73_I() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar74_J() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar75_K() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar76_L() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar77_M() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar78_N() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar79_O() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar80_P() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar81_Q() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar82_R() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar83_S() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar84_T() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar85_U() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar86_V() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar87_W() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar88_X() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar89_Y() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar90_Z() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar91_OpenBracket() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar92_YenSymbol() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar93_CloseBracket() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar94_Caret() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar95_Underscore() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar96_GraveAccent() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar97_a() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar98_b() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar99_c() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar100_d() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col5.data(), pathDataForPixel_Row1Col5.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar101_e() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar102_f() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar103_g() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col4.data(), pathDataForPixel_Row2Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col5.data(), pathDataForPixel_Row2Col5.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar104_h() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar105_i() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar106_j() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar107_k() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col1.data(), pathDataForPixel_Row1Col1.size());
	path.loadPathFromData(pathDataForPixel_Row2Col1.data(), pathDataForPixel_Row2Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar108_l() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar109_m() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar110_n() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar111_o() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar112_p() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar113_q() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar114_r() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar115_s() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar116_t() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col2.data(), pathDataForPixel_Row2Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar117_u() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar118_v() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar119_w() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col1.data(), pathDataForPixel_Row5Col1.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col1.data(), pathDataForPixel_Row6Col1.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar120_x() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col4.data(), pathDataForPixel_Row6Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar121_y() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col5.data(), pathDataForPixel_Row5Col5.size());
	path.loadPathFromData(pathDataForPixel_Row6Col5.data(), pathDataForPixel_Row6Col5.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar122_z() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row3Col1.data(), pathDataForPixel_Row3Col1.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row3Col5.data(), pathDataForPixel_Row3Col5.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col2.data(), pathDataForPixel_Row6Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col1.data(), pathDataForPixel_Row7Col1.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	path.loadPathFromData(pathDataForPixel_Row7Col5.data(), pathDataForPixel_Row7Col5.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar123_OpenBrace() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col4.data(), pathDataForPixel_Row1Col4.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col4.data(), pathDataForPixel_Row7Col4.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar124_Bar() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col3.data(), pathDataForPixel_Row1Col3.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col3.data(), pathDataForPixel_Row7Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar125_CloseBrace() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row1Col2.data(), pathDataForPixel_Row1Col2.size());
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col3.data(), pathDataForPixel_Row3Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row5Col3.data(), pathDataForPixel_Row5Col3.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	path.loadPathFromData(pathDataForPixel_Row7Col2.data(), pathDataForPixel_Row7Col2.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar126_RightArrow() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col4.data(), pathDataForPixel_Row3Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col4.data(), pathDataForPixel_Row5Col4.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	return path;
}

Path LCDcharacterPaths::createPathForChar127_LeftArrow() {
	Path path;
	path.loadPathFromData(pathDataForPixel_Row2Col3.data(), pathDataForPixel_Row2Col3.size());
	path.loadPathFromData(pathDataForPixel_Row3Col2.data(), pathDataForPixel_Row3Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col1.data(), pathDataForPixel_Row4Col1.size());
	path.loadPathFromData(pathDataForPixel_Row4Col2.data(), pathDataForPixel_Row4Col2.size());
	path.loadPathFromData(pathDataForPixel_Row4Col3.data(), pathDataForPixel_Row4Col3.size());
	path.loadPathFromData(pathDataForPixel_Row4Col4.data(), pathDataForPixel_Row4Col4.size());
	path.loadPathFromData(pathDataForPixel_Row4Col5.data(), pathDataForPixel_Row4Col5.size());
	path.loadPathFromData(pathDataForPixel_Row5Col2.data(), pathDataForPixel_Row5Col2.size());
	path.loadPathFromData(pathDataForPixel_Row6Col3.data(), pathDataForPixel_Row6Col3.size());
	return path;
}

LCDcharacterPaths& LCDcharacterPaths::get() noexcept {
	static LCDcharacterPaths lcdCharacterPaths;
	return lcdCharacterPaths;
}

Path LCDcharacterPaths::getPathForChar(uint8 charNum) {
	jassert(charNum < 128);
	return characterPaths[charNum];
}

