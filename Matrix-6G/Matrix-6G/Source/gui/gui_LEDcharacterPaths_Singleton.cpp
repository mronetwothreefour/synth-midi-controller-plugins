#include "gui_LEDcharacterPaths_Singleton.h"




LEDcharacterPaths::LEDcharacterPaths() :
	pathDataForSegment_A{ 110,109,113,61,234,63,0,0,0,0,108,31,133,3,65,0,0,0,0,108,31,133,3,65,236,81,184,62,108,215,163,248,64,195,245,40,63,108,82,184,230,64,215,163,48,63,108,133,235,217,64,102,102,102,63,108,133,235,169,64,102,102,102,63,108,102,102,158,64,0,0,0,63,108,215,
		163,136,64,0,0,0,63,108,82,184,126,64,123,20,110,63,108,82,184,78,64,123,20,110,63,108,123,20,62,64,246,40,28,63,108,92,143,18,64,246,40,28,63,99,101,0,0 },
	pathDataForSegment_B{ 110,109,61,10,255,64,113,61,138,63,108,143,194,253,64,236,81,56,64,108,133,235,241,64,154,153,89,64,108,123,20,230,64,205,204,188,64,108,143,194,237,64,20,174,207,64,108,184,30,253,64,20,174,207,64,108,154,153,5,65,164,112,189,64,108,72,225,10,65,225,
		122,180,63,108,72,225,6,65,10,215,35,63,99,101,0,0 },
	pathDataForSegment_C{ 110,109,143,194,221,64,10,215,251,64,108,184,30,237,64,133,235,233,64,108,154,153,249,64,154,153,233,64,108,51,51,3,65,20,174,255,64,108,123,20,238,64,123,20,82,65,108,92,143,226,64,236,81,88,65,108,205,204,212,64,51,51,79,65,108,246,40,220,64,164,112,
		49,65,108,61,10,215,64,72,225,42,65,99,101,0,0 },
	pathDataForSegment_D{ 110,109,20,174,7,63,184,30,89,65,108,102,102,102,63,246,40,80,65,108,133,235,241,63,174,71,81,65,108,102,102,6,64,20,174,75,65,108,164,112,29,64,31,133,75,65,108,195,245,56,64,143,194,85,65,108,82,184,110,64,143,194,85,65,108,72,225,130,64,123,20,78,
		65,108,154,153,177,64,82,184,78,65,108,0,0,184,64,225,122,84,65,108,82,184,206,64,246,40,84,65,108,20,174,215,64,82,184,90,65,108,20,174,207,64,0,0,96,65,108,133,235,81,63,0,0,96,65,99,101,0,0 },
	pathDataForSegment_E{ 110,109,215,163,112,63,123,20,230,64,108,92,143,162,63,123,20,230,64,108,123,20,206,63,10,215,251,64,108,246,40,188,63,61,10,19,65,108,195,245,136,63,82,184,26,65,108,143,194,53,63,61,10,75,65,108,41,92,143,62,143,194,85,65,108,0,0,0,0,0,0,76,65,108,
		205,204,12,63,174,71,241,64,99,101,0,0 },
	pathDataForSegment_F{ 110,109,0,0,160,63,113,61,10,63,108,195,245,200,63,225,122,148,62,108,61,10,247,63,102,102,102,63,108,51,51,211,63,246,40,92,64,108,246,40,252,63,184,30,133,64,108,113,61,234,63,164,112,189,64,108,51,51,179,63,164,112,205,64,108,0,0,128,63,164,112,205,
		64,108,143,194,53,63,246,40,188,64,99,101,0,0 },
	pathDataForSegment_G{ 110,109,154,153,25,64,92,143,162,63,108,102,102,6,64,154,153,89,64,108,123,20,62,64,61,10,191,64,108,143,194,85,64,41,92,191,64,108,0,0,96,64,82,184,134,64,99,101,0,0 },
	pathDataForSegment_H{ 110,109,31,133,131,64,143,194,149,63,108,143,194,149,64,205,204,76,63,108,225,122,164,64,184,30,165,63,108,246,40,148,64,143,194,189,64,108,61,10,135,64,246,40,204,64,108,61,10,119,64,246,40,204,64,108,184,30,101,64,133,235,193,64,99,101,0,0 },
	pathDataForSegment_I{ 110,109,41,92,159,64,82,184,158,64,108,51,51,227,64,51,51,147,63,108,133,235,241,64,205,204,140,63,108,174,71,241,64,61,10,39,64,108,184,30,173,64,0,0,192,64,108,184,30,157,64,0,0,192,64,99,101,0,0 },
	pathDataForSegment_J{ 110,109,215,163,144,64,123,20,214,64,108,133,235,153,64,102,102,198,64,108,154,153,217,64,102,102,198,64,108,102,102,230,64,20,174,215,64,108,246,40,228,64,184,30,229,64,108,164,112,213,64,225,122,244,64,108,205,204,156,64,225,122,244,64,108,0,0,144,
		64,41,92,231,64,99,101,0,0 },
	pathDataForSegment_K{ 110,109,61,10,151,64,225,122,252,64,108,195,245,160,64,225,122,252,64,108,133,235,209,64,10,215,51,65,108,246,40,204,64,225,122,76,65,108,143,194,189,64,205,204,76,65,108,113,61,146,64,184,30,21,65,99,101,0,0 },
	pathDataForSegment_L{ 110,109,61,10,87,64,143,194,245,64,108,246,40,108,64,72,225,234,64,108,164,112,125,64,113,61,234,64,108,31,133,139,64,82,184,246,64,108,164,112,125,64,92,143,66,65,108,51,51,99,64,215,163,80,65,108,184,30,69,64,195,245,80,65,108,41,92,47,64,205,204,72,
		65,99,101,0,0 },
	pathDataForSegment_M{ 110,109,61,10,39,64,205,204,252,64,108,246,40,60,64,205,204,252,64,108,82,184,46,64,184,30,37,65,108,92,143,226,63,31,133,75,65,108,195,245,136,63,61,10,75,65,108,51,51,179,63,154,153,41,65,99,101,0,0 },
	pathDataForSegment_N{ 110,109,61,10,183,63,164,112,213,64,108,195,245,232,63,20,174,199,64,108,113,61,90,64,20,174,199,64,108,82,184,110,64,133,235,209,64,108,31,133,107,64,92,143,226,64,108,20,174,71,64,72,225,242,64,108,20,174,231,63,10,215,243,64,108,51,51,179,63,0,0,224,
		64,99,101,0,0 },
	pathDataForSegment_O{ 110,109,102,102,6,65,41,92,59,65,108,195,245,16,65,143,194,53,65,108,102,102,30,65,0,0,60,65,108,143,194,29,65,154,153,77,65,108,195,245,16,65,92,143,82,65,108,184,30,5,65,195,245,76,65,99,101,0,0 },
	pathDataForSegment_P{ 110,109,184,30,5,65,123,20,86,65,108,72,225,2,65,236,81,116,65,108,246,40,8,65,236,81,116,65,108,31,133,27,65,215,163,96,65,108,195,245,28,65,31,133,87,65,99,101,0,0 }
{
	fillCharacterPaths();
}

void LEDcharacterPaths::fillCharacterPaths() {
	Path emptyPath;
	// ASCII characters 0..31 are invisible control characters
	// ASCII character 32 is a space
	for (auto character = 0; character != 33; ++character)
		characterPaths.add(emptyPath);
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
	characterPaths.add(emptyPath);
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
	characterPaths.add(createPathForChar92_Backslash());
	characterPaths.add(emptyPath);
	characterPaths.add(createPathForChar94_Caret());
	characterPaths.add(createPathForChar95_Underscore());
	for (auto character = 96; character != 124; ++character)
		characterPaths.add(emptyPath);
	characterPaths.add(createPathForChar124_Bar());
}

Path LEDcharacterPaths::createPathForChar33_ExclamationPoint() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar34_DoubleQuote() {
	Path path;
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar35_HashSymbol() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar36_$() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar37_PercentageSymbol() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar38_Ampersand() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar39_SingleQuote() {
	Path path;
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar40_OpenParenthesis() {
	Path path;
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar41_CloseParenthesis() {
	Path path;
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar42_Asterisk() {
	Path path;
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar43_PlusSymbol() {
	Path path;
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar44_Comma() {
	Path path;
	path.loadPathFromData(pathDataForSegment_O.data(), pathDataForSegment_O.size());
	path.loadPathFromData(pathDataForSegment_P.data(), pathDataForSegment_P.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar45_Hyphen() {
	Path path;
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar46_Period() {
	Path path;
	path.loadPathFromData(pathDataForSegment_O.data(), pathDataForSegment_O.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar47_Slash() {
	Path path;
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar48_0() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar49_1() {
	Path path;
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar50_2() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar51_3() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar52_4() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar53_5() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar54_6() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar55_7() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar56_8() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar57_9() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar58_Colon() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar59_Semicolon() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar60_OpenAngledBracket() {
	Path path;
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar61_Equals() {
	Path path;
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar62_CloseAngledBracket() {
	Path path;
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar63_QuestionMark() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar65_A() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar66_B() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar67_C() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar68_D() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar69_E() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar70_F() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar71_G() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar72_H() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar73_I() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar74_J() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar75_K() {
	Path path;
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar76_L() {
	Path path;
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar77_M() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar78_N() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar79_O() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar80_P() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar81_Q() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar82_R() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar83_S() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_J.data(), pathDataForSegment_J.size());
	path.loadPathFromData(pathDataForSegment_N.data(), pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar84_T() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_H.data(), pathDataForSegment_H.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar85_U() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar86_V() {
	Path path;
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar87_W() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar88_X() {
	Path path;
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar89_Y() {
	Path path;
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_L.data(), pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar90_Z() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_I.data(), pathDataForSegment_I.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar91_OpenBracket() {
	Path path;
	path.loadPathFromData(pathDataForSegment_A.data(), pathDataForSegment_A.size());
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	path.loadPathFromData(pathDataForSegment_E.data(), pathDataForSegment_E.size());
	path.loadPathFromData(pathDataForSegment_F.data(), pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar92_Backslash() {
	Path path;
	path.loadPathFromData(pathDataForSegment_G.data(), pathDataForSegment_G.size());
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar94_Caret() {
	Path path;
	path.loadPathFromData(pathDataForSegment_K.data(), pathDataForSegment_K.size());
	path.loadPathFromData(pathDataForSegment_M.data(), pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar95_Underscore() {
	Path path;
	path.loadPathFromData(pathDataForSegment_D.data(), pathDataForSegment_D.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar124_Bar() {
	Path path;
	path.loadPathFromData(pathDataForSegment_B.data(), pathDataForSegment_B.size());
	path.loadPathFromData(pathDataForSegment_C.data(), pathDataForSegment_C.size());
	return path;
}

LEDcharacterPaths& LEDcharacterPaths::get() noexcept {
	static LEDcharacterPaths ledCharacterPaths;
	return ledCharacterPaths;
}

Path LEDcharacterPaths::getPathForChar(uint8 charNum) {
	jassert(charNum < 125);
	return characterPaths[charNum];
}
