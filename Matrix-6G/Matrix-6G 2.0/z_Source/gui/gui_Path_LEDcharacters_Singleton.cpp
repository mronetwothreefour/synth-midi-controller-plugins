#include "gui_Path_LEDcharacters_Singleton.h"

#include "gui_Constants.h"

using namespace constants;




LEDcharacterPaths::LEDcharacterPaths()
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
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar34_DoubleQuote() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar35_HashSymbol() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar36_$() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar37_PercentageSymbol() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar38_Ampersand() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar39_SingleQuote() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar40_OpenParenthesis() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar41_CloseParenthesis() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar42_Asterisk() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar43_PlusSymbol() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar44_Comma() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_O.data(), GUI::pathDataForSegment_O.size());
	path.loadPathFromData(GUI::pathDataForSegment_P.data(), GUI::pathDataForSegment_P.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar45_Hyphen() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar46_Period() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_O.data(), GUI::pathDataForSegment_O.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar47_Slash() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar48_0() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar49_1() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar50_2() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar51_3() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar52_4() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar53_5() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar54_6() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar55_7() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar56_8() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar57_9() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar58_Colon() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar59_Semicolon() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar60_OpenAngledBracket() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar61_Equals() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar62_CloseAngledBracket() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar63_QuestionMark() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar65_A() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar66_B() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar67_C() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar68_D() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar69_E() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar70_F() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar71_G() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar72_H() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar73_I() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar74_J() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar75_K() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar76_L() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar77_M() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar78_N() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar79_O() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar80_P() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar81_Q() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar82_R() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar83_S() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_J.data(), GUI::pathDataForSegment_J.size());
	path.loadPathFromData(GUI::pathDataForSegment_N.data(), GUI::pathDataForSegment_N.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar84_T() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_H.data(), GUI::pathDataForSegment_H.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar85_U() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar86_V() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar87_W() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar88_X() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar89_Y() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_L.data(), GUI::pathDataForSegment_L.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar90_Z() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_I.data(), GUI::pathDataForSegment_I.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar91_OpenBracket() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar92_Backslash() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar94_Caret() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_K.data(), GUI::pathDataForSegment_K.size());
	path.loadPathFromData(GUI::pathDataForSegment_M.data(), GUI::pathDataForSegment_M.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar95_Underscore() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	return path;
}

Path LEDcharacterPaths::createPathForChar124_Bar() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
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
