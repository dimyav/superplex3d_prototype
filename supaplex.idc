
#include <idc.idc>

#undef SegAlign

static main()
{
	auto my_struc, my_enum, i, tmp;

	SetLongPrm(INF_STRTYPE, ASCSTR_TERMCHR);
	SetCharPrm(INF_LPREFIX, "@@");

	// --------------------------------------------
	// Segments

	//SegRename(0, "");
	SegRename(0x7E00, "MENU_DAT_SEG");
	SegRename(0xFB00, "GFX_DAT_SEG");
	SegRename(0x17800, "CONTROLS_DAT_SEG");
	SegRename(0x1F500, "BACK_DAT_SEG");
	//SegRename(0x27200, "");
	SegRename(0x36C20, "CODE_SEG");
	//SegAlign(0x36C20, saRelPara);
	SegRename(0x3F600, "DATA_SEG");
	SegRename(0x4D460, "DOS_ERROR_MSG_SEG");
	SegRename(0x4D570, "INT80_SEG");
	SegRename(0x4EB60, "INT81_SEG");
	SegRename(0x587B0, "STACK_SEG");

	SegBounds(0x587B0, 0x587B0, 0x58BB0, 1);

	// --------------------------------------------
	// Structures

	my_struc = AddStrucEx(-1, "SPECIAL_PORT", 0);
	AddStrucMember(my_struc, "coords", -1, FF_WORD | FF_DATA, -1, 2);
	AddStrucMember(my_struc, "gravity", -1, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "freeze_zonks", -1, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "freeze_enemies", -1, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "unused", -1, FF_BYTE | FF_DATA, -1, 1);

	DelStruc(GetStrucIdByName("KEYBOARD_STATE"));
	my_struc = AddStrucEx(-1, "KEYBOARD_STATE", 0);
	AddStrucMember(my_struc, "keyEscape", 0x01, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key1", 0x02, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key2", 0x03, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key3", 0x04, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key4", 0x05, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key5", 0x06, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key6", 0x07, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key7", 0x08, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key8", 0x09, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key9", 0x0A, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "key0", 0x0B, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyMinus", 0x0C, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyPlus", 0x0D, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyBackspace", 0x0E, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyTab", 0x0F, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyQ", 0x10, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyW", 0x11, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyE", 0x12, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyR", 0x13, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyT", 0x14, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyY", 0x15, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyU", 0x16, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyI", 0x17, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyO", 0x18, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyP", 0x19, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyOpenSqBracket", 0x1A, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyCloseSqBracket", 0x1B, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyEnter", 0x1C, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyCtrl", 0x1D, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyA", 0x1E, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyS", 0x1F, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyD", 0x20, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF", 0x21, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyG", 0x22, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyH", 0x23, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyJ", 0x24, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyK", 0x25, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyL", 0x26, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyColon", 0x27, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyQuote", 0x28, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyTilde", 0x29, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyLeftShift", 0x2A, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyBackslash", 0x2B, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyZ", 0x2C, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyX", 0x2D, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyC", 0x2E, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyV", 0x2F, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyB", 0x30, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyN", 0x31, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyM", 0x32, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyLessThan", 0x33, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyGreaterThan", 0x34, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keySlash", 0x35, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyRightShift", 0x36, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNumAsterisk", 0x37, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyAlt", 0x38, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keySpaceBar", 0x39, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyCapsLock", 0x3A, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF1", 0x3B, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF2", 0x3C, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF3", 0x3D, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF4", 0x3E, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF5", 0x3F, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF6", 0x40, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF7", 0x41, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF8", 0x42, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF9", 0x43, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF10", 0x44, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNumLock", 0x45, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyScrollLock", 0x46, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum7_Home", 0x47, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum8_Up", 0x48, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum9_PgUp", 0x49, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNumMinus", 0x4A, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum4_Left", 0x4B, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum5", 0x4C, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum6_Right", 0x4D, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNumPlus", 0x4E, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum1_End", 0x4F, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum2_Down", 0x50, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum3_PgDn", 0x51, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNum0_Ins", 0x52, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyNumDot_Del", 0x53, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyAltSysRq", 0x54, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF11", 0x57, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "keyF12", 0x58, FF_BYTE | FF_DATA, -1, 1);
	AddStrucMember(my_struc, "unused", 0x59, FF_BYTE | FF_DATA, -1, 0x26);

	// --------------------------------------------
	// Enums

	my_enum = AddEnum(GetEnumQty(), "MAP_ELEMENT", 0);
	AddConstEx(my_enum, "MAP_SPACE", 0, -1);
	AddConstEx(my_enum, "MAP_ZONK", 1, -1);
	AddConstEx(my_enum, "MAP_BASE", 2, -1);
	AddConstEx(my_enum, "MAP_MURPHY", 3, -1);
	AddConstEx(my_enum, "MAP_INFOTRON", 4, -1);
	AddConstEx(my_enum, "MAP_RAM_CHIP_SQUARE", 5, -1);
	AddConstEx(my_enum, "MAP_GRAY_DENTED_PYRAMID", 6, -1);
	AddConstEx(my_enum, "MAP_EXIT", 7, -1);
	AddConstEx(my_enum, "MAP_DISK_ORANGE", 8, -1);
	AddConstEx(my_enum, "MAP_PORT_LEFT_TO_RIGHT", 9, -1);
	AddConstEx(my_enum, "MAP_PORT_UP_TO_DOWN", 10, -1);
	AddConstEx(my_enum, "MAP_PORT_RIGHT_TO_LEFT", 11, -1);
	AddConstEx(my_enum, "MAP_PORT_DOWN_TO_UP", 12, -1);
	AddConstEx(my_enum, "MAP_PORT_SPECIAL_LEFT_TO_RIGHT", 13, -1);
	AddConstEx(my_enum, "MAP_PORT_SPECIAL_UP_TO_DOWN", 14, -1);
	AddConstEx(my_enum, "MAP_PORT_SPECIAL_RIGHT_TO_LEFT", 15, -1);
	AddConstEx(my_enum, "MAP_PORT_SPECIAL_DOWN_TO_UP", 16, -1);
	AddConstEx(my_enum, "MAP_SNIK_SNAK", 17, -1);
	AddConstEx(my_enum, "MAP_DISK_YELLOW", 18, -1);
	AddConstEx(my_enum, "MAP_TERMINAL", 19, -1);
	AddConstEx(my_enum, "MAP_DISK_RED", 20, -1);
	AddConstEx(my_enum, "MAP_PORT_VERTICAL", 21, -1);
	AddConstEx(my_enum, "MAP_PORT_HORIZONTAL", 22, -1);
	AddConstEx(my_enum, "MAP_PORT_CROSS", 23, -1);
	AddConstEx(my_enum, "MAP_ELECTRON", 24, -1);
	AddConstEx(my_enum, "MAP_BUG", 25, -1);
	AddConstEx(my_enum, "MAP_RAM_CHIP_LEFT", 26, -1);
	AddConstEx(my_enum, "MAP_RAM_CHIP_RIGHT", 27, -1);
	AddConstEx(my_enum, "MAP_HARDWARE_1", 28, -1);
	AddConstEx(my_enum, "MAP_GREEN_LAMP", 29, -1);
	AddConstEx(my_enum, "MAP_BLUE_LAMP", 30, -1);
	AddConstEx(my_enum, "MAP_RED_LAMP", 31, -1);
	AddConstEx(my_enum, "MAP_YELLOW_BLACK_DIAGONAL", 32, -1);
	AddConstEx(my_enum, "MAP_HARDWARE_2", 33, -1);
	AddConstEx(my_enum, "MAP_HARDWARE_3", 34, -1);
	AddConstEx(my_enum, "MAP_HARDWARE_4", 35, -1);
	AddConstEx(my_enum, "MAP_HARDWARE_5", 36, -1);
	AddConstEx(my_enum, "MAP_HARDWARE_6", 37, -1);
	AddConstEx(my_enum, "MAP_RAM_CHIP_TOP", 38, -1);
	AddConstEx(my_enum, "MAP_RAM_CHIP_BOTTOM", 39, -1);
	AddConstEx(my_enum, "MAP_INVISIBLE_WALL", 40, -1);

	my_enum = AddEnum(GetEnumQty(), "MAP_DIMENSIONS", 0);
	AddConstEx(my_enum, "MAP_WIDTH", 60, -1);
	AddConstEx(my_enum, "MAP_HEIGHT", 24, -1);
	AddConstEx(my_enum, "MAP_NUM_CELLS", 60 * 24, -1);

	DelEnum(GetEnum("SOUND_DRIVER_TYPE"));
	my_enum = AddEnum(GetEnumQty(), "SOUND_DRIVER_TYPE", 0);
	AddConstEx(my_enum, "SND_NONE", 0, -1);
	AddConstEx(my_enum, "SND_BEEP", 1, -1);
	AddConstEx(my_enum, "SND_SAMPLE", 2, -1);
	AddConstEx(my_enum, "SND_ADLIB", 3, -1);
	AddConstEx(my_enum, "SND_BLASTER", 4, -1);
	AddConstEx(my_enum, "SND_ROLAND", 5, -1);

	DelEnum(GetEnum("SOUND_DRIVER_FUNC"));
	my_enum = AddEnum(GetEnumQty(), "SOUND_DRIVER_FUNC", 0);
	AddConstEx(my_enum, "SND_FN_INIT", 0, -1);
	AddConstEx(my_enum, "SND_FN_UNINIT", 2, -1);

	// --------------------------------------------
	// Functions

	MakeUnkn(0x36C20, 0);
	MakeCode(0x36C20);
	MakeUnkn(0x36C25, 0);
	MakeFunction(0x36C20, 0x36CFC);
	MakeName(0x36C20, "main");
//	MakeNameEx(0x36C25, "@@1", 0);
//	MakeName(0x36C82, "@@2");
	OpOff(0x36C50, 1, 0x3F600);
	OpOff(0x36C59, 1, 0x3F600);
	OpOff(0x36C87, 1, 0x3F600);
	OpOff(0x36C98, 1, 0x3F600);
	OpOff(0x36CAD, 1, 0x3F600);
	OpOff(0x36CE0, 1, 0x3F600);

	MakeName(0x36CFD, "DisplayErrorAndExit");

	MakeUnkn(0x36D0F, 0);
	MakeUnkn(0x36D17, 0);
	MakeCode(0x36D0F);
	MakeFunction(0x36D0F, BADADDR);
	OpOff(0x36D0F, 1, 0x3F600);
	OpOff(0x36D18, 1, 0x3F600);
	OpDecimal(0x36D38, 1);
	OpOff(0x36D3B, 1, 0x3F600);
	OpDecimal(0x36D46, 1);
	OpOff(0x36D49, 1, 0x3F600);
	OpOff(0x36D52, 1, 0x3F600);
	MakeName(0x36D0F, "VID_func2");
	HideArea(0x36D0F, 0x36DC2, "Hidden: VID_func2", "", "", -1);
	SetHiddenArea(0x36D0F, 0);

	MakeFunction(0x36DC2, BADADDR);
	MakeName(0x36DC2, "VID_func3");

	MakeFunction(0x36E2C, BADADDR);
	MakeName(0x36E2C, "VID_func4");

	MakeFunction(0x36E82, BADADDR);
	MakeName(0x36E82, "VID_func5");

	MakeFunction(0x36E92, BADADDR);
	MakeName(0x36E92, "VID_func1");
	HideArea(0x36E92, 0x36EA2, "Hidden: VID_func1", "", "", -1);
	SetHiddenArea(0x36E92, 0);

	MakeFunction(0x36EA2, BADADDR);
	MakeName(0x36EA2, "InitKeyboard");
	OpHex(0x36EA4, 1);
	OpHex(0x36EBA, 1);
	OpOff(0x36EB2, 1, 0x36C20);

	MakeFunction(0x36EC4, BADADDR);
	MakeName(0x36EC4, "UninitKeyboard");
	OpHex(0x36ECF, 1);

	MakeFunction(0x36ED8, BADADDR);
	MakeName(0x36ED8, "Int9_Handler");
	OpOff(0x36EFC, 0, 0x3F600);
	MakeComm(0x36F09, "Alt+SysRq");
	OpHex(0x36F09, 1);
	MakeName(0x36F1C, "@@KeyReleased");
	MakeName(0x36F21, "@@DoneKeybIntr");
	OpHex(0x36F21, 1);

	MakeUnkn(0x36F2A, 0);
	MakeUnkn(0x36F2E, 0);
	MakeUnkn(0x36F30, 0);
	MakeUnkn(0x36F37, 0);
	MakeFunction(0x36F2A, BADADDR);
	MakeName(0x36F2A, "Int8_Handler");
	OpHex(0x36F50, 1);
	OpHex(0x36F61, 1);
	OpHex(0x36F72, 1);
	MakeName(0x36FAD, "@@DoneTimerIntr");
	OpHex(0x36FAD, 1);

	MakeFunction(0x36FB5, BADADDR);
	MakeName(0x36FB5, "InitTimer");
	OpHex(0x36FB7, 1);
	OpOff(0x36FC5, 1, 0x36C20);
	OpHex(0x36FCD, 1);
	OpHex(0x36FD3, 1);
	MakeComm(0x36FD5, "8254 command: set counter for channel 0");
	OpHex(0x36FD7, 1);
	MakeComm(0x36FD9, "8254: send new counter high byte");
	OpHex(0x36FDB, 1);
	MakeComm(0x36FDD, "8254: send new counter low byte");

	MakeFunction(0x36FE3, BADADDR);
	MakeName(0x36FE3, "UninitTimer");
	OpHex(0x36FEE, 1);
	OpHex(0x36FF4, 1);
	MakeComm(0x36FF6, "8254 command: set counter for channel 0");
	OpHex(0x36FF8, 1);
	MakeComm(0x36FFA, "8254: send new counter high byte");
	OpHex(0x36FFC, 1);
	MakeComm(0x36FFE, "8254: send new counter low byte");

	MakeFunction(0x37003, BADADDR);
	MakeName(0x37003, "InitDosErrorHandler");
	OpHex(0x37005, 1);
	OpHex(0x37007, 1);
	OpOff(0x37013, 1, 0x36C20);
	OpHex(0x3701B, 1);
	OpHex(0x3701D, 1);

	MakeFunction(0x37024, BADADDR);
	MakeName(0x37024, "UninitDosErrorHandler");
	OpHex(0x3702F, 1);
	OpHex(0x37031, 1);

	MakeUnkn(0x37038, 0);
	MakeFunction(0x37038, BADADDR);
	MakeName(0x37038, "DosErrorHandler");

	MakeFunction(0x3703B, BADADDR);
	MakeName(0x3703B, "ReadConfigFile");
	OpOff(0x3703E, 1, 0x3F600);
	MakeComm(0x37045, "DOS ERROR: File not found");
	MakeName(0x3704D, "@@CfgFileCheckPathErr");
	MakeComm(0x3704D, "DOS ERROR: Path not found");
	MakeName(0x37055, "@@CfgFileUnrecoverableErr");
	MakeName(0x37058, "@@CfgFileOpenOk");
	OpOff(0x37065, 1, 0x3F600);
	MakeName(0x3706F, "@@CfgFileReadOk");
	MakeName(0x3707D, "@@CfgFileCloseOk");
	OpOff(0x3707D, 1, 0x3F600);
	OpChr(0x37080, 1);
	MakeName(0x37088, "@@CfgFileNotBeepSound");
	OpChr(0x37088, 1);
	MakeName(0x37090, "@@CfgFileNotBeepSampleSound");
	OpChr(0x37090, 1);
	MakeName(0x37098, "@@CfgFileNotAdlibSound");
	OpChr(0x37098, 1);
	MakeName(0x370A0, "@@CfgFileNotBlasterSound");
	OpChr(0x370A0, 1);
	MakeName(0x370A8, "@@CfgFileNotRolandSound");
	OpChr(0x370A8, 1);
	MakeName(0x370B0, "@@CfgFileNotCombinedSound");
	OpChr(0x370B1, 1);
	MakeName(0x370BB, "@@CfgFileNotKeyboard");
	OpChr(0x370BB, 1);
	MakeName(0x370C8, "@@CfgFileNotJoystick");
	OpChr(0x370C9, 1);
	MakeName(0x370D3, "@@CfgFileMusicDisabled");
	OpChr(0x370D3, 1);
	MakeName(0x370DD, "@@CfgFileMusicEnabled");
	OpChr(0x370DE, 1);
	MakeName(0x370E8, "@@CfgFileSfxDisabled");
	OpChr(0x370E8, 1);
	MakeName(0x370F2, "@@CfgFileParseDone");
	MakeName(0x370F3, "@@UseDefaultConfig");

	MakeUnkn(0x370FC, 0);
	MakeFunction(0x370FC, BADADDR);
	MakeName(0x370FC, "WriteConfigFile");
	OpOff(0x37102, 1, 0x3F600);
	MakeName(0x3710C, "@@CfgFileCreateOk");
	OpOff(0x3710F, 1, 0x3F600);
	OpEnumEx(0x37112, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpChr(0x37119, 1);
	MakeName(0x3711E, "@@CfgFileNotBeepSample");
	OpEnumEx(0x3711E, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpChr(0x37125, 1);
	MakeName(0x3712A, "@@CfgFileNotBeep");
	OpEnumEx(0x3712A, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpChr(0x37131, 1);
	MakeName(0x37136, "@@CfgFileNotAdlib");
	OpEnumEx(0x37136, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpChr(0x3713D, 1);
	MakeName(0x37142, "@@CfgFileNotRoland");
	OpEnumEx(0x37142, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpChr(0x37149, 1);
	MakeName(0x3714E, "@@CfgFileNotCombined");
	MakeName(0x37151, "@@CfgFileDoneWriteSoundConfig");
	MakeName(0x3715E, "@@CfgFileJoystickEnabled");
	MakeName(0x37161, "@@CfgFileWriteMusic");
	MakeName(0x3716E, "@@CfgFileNoMusic");
	MakeName(0x37171, "@@CfgFileWriteSfx");
	MakeName(0x3717E, "@@CfgFileSfxEnabled");
	MakeName(0x37181, "@@CfgFileDoWriteData");
	MakeName(0x37195, "@@CfgFileWriteOk");
	MakeName(0x371A3, "@@CfgFileClosedOk");

	OpChr(0x3714E, 1);
	OpChr(0x37159, 1);
	OpChr(0x3715E, 1);
	OpChr(0x37169, 1);
	OpChr(0x3716E, 1);
	OpChr(0x37179, 1);
	OpChr(0x3717E, 1);
	OpOff(0x3718B, 1, 0x3F600);

	MakeFunction(0x371A4, BADADDR);
	MakeName(0x371A4, "StopFloppyMotor");

	MakeFunction(0x371AB, BADADDR);
	MakeName(0x371AB, "LoadAllDemoFiles");
	MakeName(0x371BB, "@@LoadNextDemoFile");
	OpOff(0x371B1, 1, 0x27200);
	OpOff(0x371BF, 1, 0x3F600);
	OpDecimal(0x371D5, 1);
	MakeName(0x371EC, "@@DemoFileReadOk");
	OpChr(0x371C2, 1);
	MakeName(0x371FC, "@@DemoFileCloseOk");
	MakeName(0x37217, "@@DemoFileOpenFailed");

	MakeFunction(0x3721A, BADADDR);
	MakeName(0x3721A, "VID_LoadPalettes");
	OpOff(0x3721D, 1, 0x3F600);
	MakeComm(0x37224, "DOS ERROR: File not found");
	MakeName(0x3722E, "@@PaletteFileOpenError");
	MakeName(0x37231, "@@PaletteFileOpenOk");
	OpDecimal(0x3723B, 1);
	OpOff(0x3723E, 1, 0x3F600);
	MakeName(0x37248, "@@PaletteFileReadOk");
	MakeName(0x37256, "@@PaletteFileCloseOk");

	MakeFunction(0x37257, BADADDR);
	MakeName(0x37257, "VID_ScrollScreenHorizontal");
	MakeLocal(0x37257, BADADDR, "[bp-06]", "savedDS");
	OpDecimal(0x3725A, 1);
	if (substr(GetOpnd(0x3725A, 1), 0, 1) != "-")
		OpSign(0x3725A, 1);
	MakeComm(0x3726C, "Select the Graphics Mode register");
	MakeComm(0x37270, "Set mode:\n 16 colors,\n interleave mode disabled,\n normal addressing\n write mode 01: In this mode, data is transferred directly from the\n   32 bit latch register to display memory, affected only by the\n   Memory Plane Write Enable field. The host data is not used in\n   this mode.");
	MakeComm(0x37276, "Select the Map Mask register");
	MakeComm(0x3727A, "Enable writing to all color planes");
	MakeComm(0x37280, "Select the Bit Mask register");
	MakeComm(0x37284, "Write the bit mask");
	OpOff(0x3733B, 1, 0x3F600);
	// FIXME: Needs completion

	MakeFunction(0x37345, BADADDR);
	MakeName(0x37345, "VID_DisplayTitleScreen");
	OpOff(0x37348, 1, 0x3F600);
	MakeName(0x37352, "@@Title1FileOpenOk");
	MakeComm(0x3735A, "Select the Graphics Mode register");
	MakeComm(0x3735E, "Set mode:\n 16 colors,\n interleave mode disabled,\n normal addressing\n write mode 00: In this mode, the host data is first rotated as per\n   the Rotate Count field, then the Enable Set/Reset mechanism\n   selects data from this or the Set/Reset field. Then the selected\n   Logical Operation is performed on the resulting data and the\n   data in the latch register. Then the Bit Mask field is used to\n   select which bits come from the resulting data and which come\n   from the latch register. Finally, only the bit planes enabled by\n   the Memory Plane Write Enable field are written to memory.");
	MakeComm(0x37364, "Select the Enable Set/Reset register");
	MakeComm(0x37368, "Use the CPU-specified value for all color planes");
	MakeComm(0x3736E, "Select the Bit Mask register");
	MakeComm(0x37372, "Write the bit mask");
	MakeComm(0x37373, "Height of the image");
	OpDecimal(0x37373, 1);
	MakeComm(0x37376, "Address in the video memory");
	MakeName(0x37379, "@@Title1ReadNextRow");
	OpDecimal(0x37381, 1);
	OpOff(0x37384, 1, 0x3F600);
	MakeName(0x3738E, "@@Title1FileReadOk");
	OpOff(0x3738E, 1, 0x3F600);
	MakeComm(0x37391, "First color plane");
	MakeName(0x37393, "@@Title1WritePlane");
	MakeComm(0x37398, "Select the Map Mask register");
	MakeComm(0x3739C, "Set the bit plane mask");
	OpDecimal(0x3739D, 1);
	OpDecimal(0x373A2, 1);
	MakeComm(0x373A5, "Next color plane");
	OpDecimal(0x373AC, 1);
	MakeName(0x373C0, "@@Title1FileCloseOk");
	MakeComm(0x373C5, "Select the Map Mask register");
	MakeComm(0x373C9, "Enable writing to all color planes");
	MakeComm(0x373CF, "Select the Enable Set/Reset register");
	MakeComm(0x373D3, "Enable use of bit expansion from the Set/Reset Register into all color planes");
	MakeComm(0x373D4, "Address in the video memory");
	MakeComm(0x373E0, "Select the Start Address Low register");
	MakeComm(0x373E4, "Write low byte of the memory address");
	MakeComm(0x373EA, "Select the Start Address High register");
	MakeComm(0x373EE, "Write high byte of the memory address");
	OpOff(0x373F7, 1, 0x3F600);
	OpOff(0x37400, 1, 0x3F600);
	MakeName(0x3740A, "@@Title2FileOpenOk");
	MakeComm(0x37412, "Select the Enable Set/Reset register");
	MakeComm(0x37416, "Use the CPU-specified value for all color planes");
	MakeComm(0x3741C, "Select the Bit Mask register");
	MakeComm(0x37420, "Write the bit mask");
	OpDecimal(0x37421, 1);
	MakeComm(0x37424, "Address in the video memory");
	MakeName(0x37427, "@@Title2ReadNextRow");
	OpDecimal(0x3742F, 1);
	OpOff(0x37432, 1, 0x3F600);
	MakeName(0x3743C, "@@Title2FileReadOk");
	OpOff(0x3743C, 1, 0x3F600);
	MakeComm(0x3743F, "First color plane");
	MakeName(0x37441, "@@Title2WritePlane");
	MakeComm(0x37446, "Select the Map Mask register");
	MakeComm(0x3744A, "Set the bit plane mask");
	OpDecimal(0x3744B, 1);
	OpDecimal(0x37450, 1);
	MakeComm(0x37453, "Next color plane");
	OpDecimal(0x3745A, 1);
	MakeName(0x3746E, "@@Title2FileCloseOk");
	MakeComm(0x37473, "Select the Map Mask register");
	MakeComm(0x37477, "Enable writing to all color planes");

	MakeFunction(0x37479, BADADDR);
	MakeName(0x37479, "VID_LoadSprites");
	if (substr(GetOpnd(0x3747C, 1), 0, 1) != "-")
		OpSign(0x3747C, 1);
	MakeName(0x3747F, "@@MovingRetryFileOpen");
	OpOff(0x37482, 1, 0x3F600);
	MakeComm(0x37489, "DOS ERROR: File not found");
	MakeName(0x37495, "@@MovingFileOpenFailed");
	MakeName(0x37498, "@@MovingFileOpenOk");
	OpDecimal(0x374D1, 1);
	OpOff(0x374D4, 1, 0x3F600);
	MakeName(0x374DE, "@@MovingFileReadOk");
	OpOff(0x374DE, 1, 0x3F600);
	OpDecimal(0x3750B, 1);
	MakeName(0x3753D, "@@MovingFileCloseOk");
	OpOff(0x37540, 1, 0x3F600);
	MakeName(0x3754A, "@@FixedFileOpenOk");
	OpDecimal(0x37554, 1);
	OpOff(0x37557, 1, 0x3F600);
	MakeName(0x37561, "@@FixedFileReadOk");
	MakeName(0x3756F, "@@FixedFileCloseOk");

	MakeFunction(0x3757D, BADADDR);
	MakeName(0x3757D, "VID_LoadPanelImage");
	OpOff(0x37580, 1, 0x3F600);
	MakeComm(0x37587, "DOS ERROR: File not found");
	MakeName(0x37593, "@@PanelFileOpenFailed");
	MakeName(0x37596, "@@PanelFileOpenOk");
	OpDecimal(0x375A0, 1);
	OpOff(0x375A3, 1, 0x3F600);
	MakeName(0x375AD, "@@PanelFileReadOk");
	MakeName(0x375BB, "@@PanelFileCloseOk");

	MakeFunction(0x375BC, BADADDR);
	MakeName(0x375BC, "VID_LoadGradientBackground");
	OpOff(0x375BF, 1, 0x3F600);
	MakeComm(0x375C6, "DOS ERROR: File not found");
	MakeName(0x375D2, "@@BackFileOpenFailed");
	MakeName(0x375D5, "@@BackFileOpenOk");
	OpDecimal(0x375E5, 1);
	OpOff(0x375E8, 1, 0x1F500);
	MakeName(0x375F3, "@@BackFileReadOk");
	MakeName(0x37602, "@@BackFileCloseOk");

	MakeFunction(0x37603, BADADDR);
	MakeName(0x37603, "VID_LoadFonts");
	OpOff(0x37606, 1, 0x3F600);
	MakeComm(0x3760D, "DOS ERROR: File not found");
	MakeName(0x37619, "@@Chars6FileOpenFailed");
	MakeName(0x3761C, "@@Chars6FileOpenOk");
	OpDecimal(0x37626, 1);
	OpOff(0x37629, 1, 0x3F600);
	MakeName(0x37633, "@@Chars6FileReadOk");
	MakeName(0x37641, "@@Chars6FileCloseOk");
	OpOff(0x37644, 1, 0x3F600);
	MakeName(0x3764E, "@@Chars8FileOpenOk");
	OpDecimal(0x37658, 1);
	OpOff(0x3765B, 1, 0x3F600);
	MakeName(0x37665, "@@Chars8FileReadOk");
	MakeName(0x37673, "@@Chars8FileCloseOk");

	MakeFunction(0x37674, BADADDR);
	MakeName(0x37674, "VID_DisplayTitle");
	OpOff(0x3769A, 1, 0x3F600);
	// FIXME

	MakeFunction(0x37727, BADADDR);
	MakeName(0x37727, "LoadLevelsList");
	OpOff(0x3772A, 1, 0x3F600);
	MakeComm(0x37731, "DOS ERROR: File not found");
	MakeName(0x3773D, "@@LevelsLstFileOpenFailed");
	MakeName(0x37740, "@@LevelsLstFileOpenOk");
	OpDecimal(0x3774A, 1);
	OpOff(0x3774D, 1, 0x3F600);
	MakeName(0x37757, "@@LevelsLstFileReadOk");
	MakeName(0x37765, "@@LevelsLstFileCloseOk");

	MakeFunction(0x37766, BADADDR);
	MakeName(0x37766, "VID_LoadGfxDat");
	OpOff(0x37769, 1, 0x3F600);
	MakeComm(0x37770, "DOS ERROR: File not found");
	MakeName(0x3777C, "@@GfxFileOpenFailed");
	MakeName(0x3777F, "@@GfxFileOpenOk");
	OpDecimal(0x3778F, 1);
	OpOff(0x37792, 1, 0xFB00);
	MakeName(0x3779D, "@@GfxFileReadOk");
	MakeName(0x377AC, "@@GfxFileCloseOk");

	MakeFunction(0x377AD, BADADDR);
	MakeName(0x377AD, "VID_LoadControlsDat");
	OpOff(0x377B0, 1, 0x3F600);
	MakeComm(0x377B7, "DOS ERROR: File not found");
	MakeName(0x377C3, "@@ControlsFileOpenFailed");
	MakeName(0x377C6, "@@ControlsFileOpenOk");
	OpDecimal(0x377D6, 1);
	OpOff(0x377D9, 1, 0x17800);
	MakeName(0x377E4, "@@ControlsFileReadOk");
	MakeName(0x377F3, "@@ControlsFileCloseOk");

	MakeFunction(0x377F4, BADADDR);
	MakeName(0x377F4, "LoadPlayerLst");
	OpOff(0x377F7, 1, 0x3F600);
	OpDecimal(0x37803, 1);
	OpOff(0x37806, 1, 0x3F600);
	MakeName(0x37812, "@@PlayerLstFileReadFailed");

	MakeFunction(0x37813, BADADDR);
	MakeName(0x37813, "LoadHallfameLst");
	OpOff(0x37816, 1, 0x3F600);
	OpDecimal(0x37822, 1);
	OpOff(0x37825, 1, 0x3F600);
	MakeName(0x37831, "@@HallfameLstFileReadFailed");

	MakeFunction(0x37832, BADADDR);
	MakeName(0x37832, "LoadAllDataFiles");

	MakeFunction(0x37854, BADADDR);
	MakeName(0x37854, "");
	MakeName(0x378AE, "@@WaitForKeyRelease");
	// FIXME

	MakeName(0x378C3, "AskUserToInsertAnotherDisk");
	OpOff(0x378C6, 1, 0x3F600);
	OpOff(0x378D6, 1, 0x3F600);
	MakeName(0x378E0, "@@CurrentDiskIs2");
	OpOff(0x378E0, 1, 0x3F600);
	MakeName(0x378E8, "@@DoAskUser");
	OpOff(0x378F0, 1, 0x3F600);
	OpOff(0x37910, 1, 0x3F600);

	// UNUSED
	MakeFunction(0x37920, BADADDR);
	//MakeName(0x37920, "");

	// UNUSED
	MakeFunction(0x37D99, BADADDR);
	//MakeName(0x37D99, "");

	// UNUSED
	MakeFunction(0x37D9A, BADADDR);
	//MakeName(0x37D9A, "");

	MakeFunction(0x38191, BADADDR);
	//MakeName(0x38191, "");

	MakeFunction(0x3826F, BADADDR);
	//MakeName(0x3826F, "");

	MakeFunction(0x382EA, BADADDR);
	//MakeName(0x382EA, "");
	OpOff(0x382EA, 0, 0x3F600);
	OpEnumEx(0x382EA, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x382F1, 0, 0x3F600);
	OpEnumEx(0x382F1, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x382F7, 0, 0x3F600);
	OpOff(0x382FE, 0, 0x3F600);
//	OpOff(0x38307, 0, 0x3F600);
//	OpOff(0x3830F, 0, 0x3F600);
//	OpOff(0x38316, 0, 0x3F600);
//	OpOff(0x3831E, 0, 0x3F600);
//	OpOff(0x38325, 0, 0x3F600);

	MakeFunction(0x38370, BADADDR);
	MakeName(0x38370, "DisplayDosErrorMessage");
	OpOff(0x38378, 1, 0x4D460);
	MakeName(0x3837D, "@@FindErrorDescr");
	OpDecimal(0x3837D, 1);
	MakeName(0x38385, "@@DisplayNextChar");
	MakeName(0x38395, "@@DisplayCRLF");
	OpDecimal(0x38397, 1);
	OpDecimal(0x3839F, 1);

	MakeFunction(0x383B0, BADADDR);
	MakeName(0x383B0, "InitPlayerState");

	MakeFunction(0x385DD, BADADDR);
	MakeName(0x385DD, "PollJoystick");

	MakeFunction(0x3890E, BADADDR);
	MakeName(0x3890E, "CalibrateJoystick");

	MakeFunction(0x38A7F, BADADDR);
	MakeName(0x38A7F, "WriteDemoFile");
	OpOff(0x38A7F, 1, 0x3F600);
	OpChr(0x38A82, 1);
	OpOff(0x38AA6, 1, 0x3F600);

	MakeFunction(0x38AC1, BADADDR);
	MakeName(0x38AC1, "HandleUserInput");

	MakeFunction(0x38FBA, BADADDR);
	MakeName(0x38FBA, "JoystickRawRead");

	MakeFunction(0x3900A, BADADDR);
	MakeName(0x3900A, "xxx_HandleBug");
	OpOff(0x3900A, 0, 0x3F600);
	OpEnumEx(0x3900A, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3901E, 1, 0x3F600);
	OpEnumEx(0x39024, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39034, 0, 0x3F600);
	OpEnumEx(0x39038, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3903E, 0, 0x3F600);
	OpEnumEx(0x3903E, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39045, 0, 0x3F600);
	OpEnumEx(0x39045, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3904C, 0, 0x3F600);
	OpEnumEx(0x3904C, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39053, 0, 0x3F600);
	MakeComm(0x39053, "-1");
	OpEnumEx(0x39053, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3905A, 0, 0x3F600);
	OpEnumEx(0x3905A, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39061, 0, 0x3F600);
	OpEnumEx(0x39061, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39068, 0, 0x3F600);
	OpEnumEx(0x39068, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3906F, 0, 0x3F600);
	OpEnumEx(0x3906F, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3907D, 1, 0x3F600);
	OpOff(0x39085, 1, 0x3F600);
	OpDecimal(0x39090, 1);
	OpDecimal(0x39095, 1);
	OpDecimal(0x39098, 1);

	MakeFunction(0x3909F, BADADDR);
	MakeName(0x3909F, "xxx_HandleTerminal");		// ?
	OpOff(0x3909F, 0, 0x3F600);
	OpEnumEx(0x3909F, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x390A7, 1, 0x3F600);
	OpOff(0x390B2, 0, 0x3F600);
	OpOff(0x390C2, 0, 0x3F600);
	OpOff(0x390C6, 1, 0x3F600);

	MakeFunction(0x3916F, BADADDR);
	MakeName(0x3916F, "InitRandomNumberGenerator");

	MakeFunction(0x3917B, BADADDR);
	MakeName(0x3917B, "GenerateRandomNumber");
	OpDecimal(0x3917E, 1);
	OpDecimal(0x39183, 1);

	MakeFunction(0x3918C, BADADDR);
	MakeName(0x3918C, "ReadKeyboardArrowsInput");

	MakeFunction(0x39209, BADADDR);
	//MakeName(0x39209, "");
	OpEnumEx(0x3920C, 1, GetEnum("MAP_DIMENSIONS"), 0);
	OpOff(0x3920F, 1, 0x3F600);
	OpEnumEx(0x39213, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39217, 0, 0x3F600);
	OpEnumEx(0x39217, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x39225, BADADDR);
	//MakeName(0x39225, "");
	OpEnumEx(0x39228, 1, GetEnum("MAP_DIMENSIONS"), 0);
	OpOff(0x3922B, 1, 0x3F600);
	OpEnumEx(0x3922F, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39233, 0, 0x3F600);
	OpEnumEx(0x39233, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x39241, BADADDR);
	//MakeName(0x39241, "");
	OpEnumEx(0x39244, 1, GetEnum("MAP_DIMENSIONS"), 0);
	OpOff(0x39247, 1, 0x3F600);
	OpEnumEx(0x3924B, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3924F, 0, 0x3F600);
	OpEnumEx(0x3924F, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x3925D, BADADDR);
	//MakeName(0x3925D, "");
	OpEnumEx(0x39260, 1, GetEnum("MAP_DIMENSIONS"), 0);
	OpOff(0x39263, 1, 0x3F600);
	OpEnumEx(0x39267, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x3926B, 0, 0x3F600);
	OpEnumEx(0x3926B, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x39279, BADADDR);
	//MakeName(0x39279, "");
	OpEnumEx(0x3927C, 1, GetEnum("MAP_DIMENSIONS"), 0);
	OpOff(0x3927F, 1, 0x3F600);
	OpEnumEx(0x39283, 1, GetEnum("MAP_ELEMENT"), 0);
	OpOff(0x39287, 0, 0x3F600);
	OpEnumEx(0x39287, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x39295, BADADDR);
	MakeName(0x39295, "FindPlayerPositionOnLevelMap");
	OpOff(0x392A2, 1, 0x3F600);
	OpEnumEx(0x392A5, 1, GetEnum("MAP_DIMENSIONS"), 0);
	OpEnumEx(0x392A8, 1, GetEnum("MAP_ELEMENT"), 0);
	OpDecimal(0x392AF, 1);
	OpEnumEx(0x392BC, 1, GetEnum("MAP_DIMENSIONS"), 0);

	OpDecimal(0x392E3, 1);
	OpOff(0x392E6, 1, 0x3F600);
	OpEnumEx(0x392EB, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x392F0, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x392F5, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x392FA, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x392FF, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39304, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39309, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3930E, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39313, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39309, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39318, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3931D, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39327, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3932D, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39333, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x39339, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x393B9, BADADDR);
	MakeName(0x393B9, "StartLevel");

	MakeFunction(0x393CF, BADADDR);
	MakeName(0x393CF, "xxx_handleOrangeDisk");
	OpOff(0x393CF, 0, 0x3F600);
	OpEnumEx(0x393CF, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x3956F, BADADDR);
//	MakeName(0x3956F, "");
	OpOff(0x3956F, 0, 0x3F600);
	OpEnumEx(0x3956F, 1, GetEnum("MAP_ELEMENT"), 0);

	MakeFunction(0x398F9, BADADDR);
//	MakeName(0x398F9, "");
	OpOff(0x398F9, 0, 0x3F600);

	MakeFunction(0x39A20, BADADDR);
	MakeName(0x39A20, "VID_LoadMenu");
	OpOff(0x39A23, 1, 0x3F600);
	MakeName(0x39A2D, "@@MenuDatFileOpenOk");
	OpDecimal(0x39A3D, 1);
	OpOff(0x39A40, 1, 0x7E00);
	MakeName(0x39A4B, "@@MenuDatFileReadOk");
	MakeName(0x39A5A, "@@MenuDatFileCloseOk");

	MakeFunction(0x39A5B, BADADDR);
	MakeName(0x39A5B, "");

	MakeFunction(0x3AA75, BADADDR);
	MakeName(0x3AA75, "VID_DrawText6");
	OpChr(0x3AAAC, 1);
	OpOff(0x3AAB1, 1, 0x3F600);
	OpDecimal(0x3AAE5, 1);
	OpDecimal(0x3AAE8, 1);
	OpDecimal(0x3AB06, 1);
	OpDecimal(0x3AB09, 1);
	OpDecimal(0x3AB27, 1);
	OpDecimal(0x3AB2A, 1);
	OpDecimal(0x3AB48, 1);
	OpDecimal(0x3AB4B, 1);
	OpDecimal(0x3AB69, 1);
	OpDecimal(0x3AB6C, 1);
	OpDecimal(0x3AB8A, 1);
	OpDecimal(0x3AB8D, 1);
	OpDecimal(0x3ABAB, 1);
	OpDecimal(0x3ABAE, 1);
	OpDecimal(0x3ABB1, 1);

	MakeFunction(0x3B3A8, BADADDR);
	MakeName(0x3B3A8, "VID_DrawGradientBackground");

	MakeFunction(0x3BCAC, BADADDR);
	MakeName(0x3BCAC, "WritePlayerLst");
	OpOff(0x3BCB2, 1, 0x3F600);
	OpDecimal(0x3BCBE, 1);
	OpOff(0x3BCC1, 1, 0x3F600);

	MakeFunction(0x3BCCE, BADADDR);
	MakeName(0x3BCCE, "WriteHallfameLst");
	OpOff(0x3BCD4, 1, 0x3F600);
	OpDecimal(0x3BCE0, 1);
	OpOff(0x3BCE3, 1, 0x3F600);

	MakeFunction(0x3BD99, BADADDR);
	//MakeName(0x3BD99, "");
	OpOff(0x3BDAD, 1, 0x3F600);
	OpOff(0x3BDC0, 1, 0x3F600);
	OpOff(0x3BDD3, 1, 0x3F600);
	OpOff(0x3BDE6, 1, 0x3F600);
	OpOff(0x3BE05, 1, 0x3F600);
	OpOff(0x3BE18, 1, 0x3F600);
	OpOff(0x3BE2B, 1, 0x3F600);
	OpOff(0x3BE3E, 1, 0x3F600);
	OpOff(0x3BE5D, 1, 0x3F600);
	OpOff(0x3BE70, 1, 0x3F600);
	OpOff(0x3BE83, 1, 0x3F600);
	OpOff(0x3BE96, 1, 0x3F600);

	MakeFunction(0x3BF60, BADADDR);
	MakeName(0x3BF60, "InitVideoMode");
	MakeComm(0x3BF67, "EGA 320x200 16-color");

	MakeFunction(0x3BF9F, BADADDR);
	MakeName(0x3BF9F, "xxx_SetPaletteRegister");	// ?
	OpDecimal(0x3BFA6, 1);
	OpOff(0x3BFBA, 1, 0x3F600);

	MakeFunction(0x3BFC1, BADADDR);
	MakeName(0x3BFC1, "UninitVideoMode");

	MakeFunction(0x3BFC9, BADADDR);
	MakeName(0x3BFC9, "InitMouse");
	MakeComm(0x3BFDB, "iret");
	OpDecimal(0x3BFFD, 1);
	OpDecimal(0x3C000, 1);
	OpDecimal(0x3C008, 1);
	OpDecimal(0x3C00B, 1);
	OpDecimal(0x3C013, 1);
	OpDecimal(0x3C016, 1);
	OpDecimal(0x3C01B, 1);
	OpDecimal(0x3C021, 1);

	MakeFunction(0x3C02F, BADADDR);
	MakeName(0x3C02F, "UninitMouse");

	MakeFunction(0x3C039, BADADDR);
	MakeName(0x3C039, "PollMouse");
	OpDecimal(0x3C0C6, 1);
	OpDecimal(0x3C0CB, 1);
	OpDecimal(0x3C0D2, 1);
	OpDecimal(0x3C0D8, 1);
	OpDecimal(0x3C0EB, 1);
	OpDecimal(0x3C0F1, 1);

	MakeFunction(0x3C0F9, BADADDR);
	MakeName(0x3C0F9, "VID_SetHorizontalPanning");
	MakeName(0x3C0FB, "@@WaitVerticalRetrace");
	MakeComm(0x3C10A, "Read the Input Status #1 register");
	MakeComm(0x3C10F, "Read the Input Status #1 register\nThis will switch the 0x3C0 port into the address mode");
	OpHex(0x3C113, 1);
	MakeComm(0x3C115, "Select the Horizontal Pixel Panning Register;\nEnable CPU access to the palette registers");
	MakeComm(0x3C119, "Write the horizontal pixel panning value");

	MakeFunction(0x3C11E, BADADDR);
	MakeName(0x3C11E, "VID_WaitVerticalRetrace");
	MakeName(0x3C120, "@@WaitForVSync");
	MakeComm(0x3C123, "Read the Input Status #1 register");

	MakeFunction(0x3C1D9, BADADDR);
	MakeName(0x3C1D9, "VID_BlankScreen");
	MakeComm(0x3C1DE, "Select the Graphics Mode register");
	MakeComm(0x3C1E2, "Set mode:\n 16 colors,\n interleave mode disabled,\n normal addressing\n write mode 00: In this mode, the host data is first rotated as per\n   the Rotate Count field, then the Enable Set/Reset mechanism\n   selects data from this or the Set/Reset field. Then the selected\n   Logical Operation is performed on the resulting data and the\n   data in the latch register. Then the Bit Mask field is used to\n   select which bits come from the resulting data and which come\n   from the latch register. Finally, only the bit planes enabled by\n   the Memory Plane Write Enable field are written to memory.");
	MakeComm(0x3C1E8, "Select the Set/Reset register");
	MakeComm(0x3C1EC, "Zero for all color planes");
	MakeComm(0x3C1F2, "Select the Enable Set/Reset register");
	MakeComm(0x3C1F6, "Enable use of bit expansion from the Set/Reset Register into all color planes.");
	MakeComm(0x3C1FC, "Select the Bit Mask register");
	MakeComm(0x3C200, "Write the bit mask");

	MakeFunction(0x3C1A6, BADADDR);
	MakeName(0x3C1A6, "VID_InitHorizontalScrolling");
	MakeComm(0x3C1AB, "Select the Enable Set/Reset register");
	MakeComm(0x3C1AF, "Enable use of bit expansion from the Set/Reset Register into all color planes.");
	MakeComm(0x3C1B5, "Select the Graphics Mode register.");
	MakeComm(0x3C1B9, "Set mode:\n 16 colors,\n interleave mode disabled,\n normal addressing\n write mode 01: In this mode, data is transferred directly from the\n   32 bit latch register to display memory, affected only by the\n   Memory Plane Write Enable field. The host data is not used in\n   this mode.");
	MakeComm(0x3C1BF, "Select the Memory Plane Write Enable register");
	MakeComm(0x3C1C3, "Enable writing to all color planes");
	MakeComm(0x3C1C9, "Select the Bit Mask register");
	MakeComm(0x3C1CD, "Write the bit mask");
	MakeComm(0x3C1D3, "Select the CRT Offset register");
	OpDecimal(0x3C1D5, 1);
	MakeComm(0x3C1D7, "Beginning with the second scan line, the starting scan line is\nincreased by twice the value of this register multiplied by the\ncurrent memory address size (byte = 1, word = 2, dword = 4)\neach line");

	MakeFunction(0x3C20A, BADADDR);
	MakeName(0x3C20A, "LoadLevelMap");
	OpOff(0x3C20D, 1, 0x3F600);
	OpDecimal(0x3C251, 1);
	OpOff(0x3C254, 1, 0x3F600);
	OpDecimal(0x3C263, 1);
	OpOff(0x3C266, 1, 0x3F600);
	OpOff(0x3C269, 1, 0x3F600);
	OpOff(0x3C272, 1, 0x3F600);
	OpDecimal(0x3C277, 1);

	MakeFunction(0x3C3CB, BADADDR);
	MakeName(0x3C3CB, "xxx_SetPalette");
	OpDecimal(0x3C3E4, 1);
	OpOff(0x3C40D, 1, 0x3F600);
	OpOff(0x3C42D, 1, 0x3F600);
	MakeName(0x3C3F0, "@@SetPalette_UploadLoop");
	MakeName(0x3C407, "@@SetPalette_UseBIOS");
	MakeName(0x3C410, "@@SetPalette_ConvToBiosLoop");
	MakeName(0x3C433, "@@SetPalette_Done");

	MakeFunction(0x3C440, BADADDR);
	MakeName(0x3C440, "SND_InitIntVectors");
	OpAlt(0x3C445, 1, "80h * 4");
	OpAlt(0x3C452, 1, "81h * 4");

	MakeFunction(0x3C46E, BADADDR);
	MakeName(0x3C46E, "SND_Uninit");

	MakeFunction(0x3C477, BADADDR);
	MakeName(0x3C477, "SND_UseNoSound");
	OpEnumEx(0x3C47A, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C47F, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);

	MakeFunction(0x3C48A, BADADDR);
	MakeName(0x3C48A, "SND_UseBeepSound");
	OpOff(0x3C48D, 1, 0x3F600);
	MakeComm(0x3C48D, "Name of the driver file");
	OpDecimal(0x3C490, 1);
	MakeComm(0x3C490, "Size of the driver file in bytes");
	OpEnumEx(0x3C496, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C49B, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpDecimal(0x3C4AD, 1);

	MakeFunction(0x3C4BD, BADADDR);
	MakeName(0x3C4BD, "SND_UseBeepSampleSound");
	OpOff(0x3C4C0, 1, 0x3F600);
	MakeComm(0x3C4C0, "Name of the driver file");
	OpDecimal(0x3C4C3, 1);
	MakeComm(0x3C4C3, "Size of the driver file in bytes");
	OpOff(0x3C4C9, 1, 0x3F600);
	MakeComm(0x3C4C9, "Name of the driver file");
	OpDecimal(0x3C4CC, 1);
	MakeComm(0x3C4CC, "Size of the driver file in bytes");
	OpEnumEx(0x3C4D2, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C4D7, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpDecimal(0x3C4E9, 1);

	MakeFunction(0x3C4F9, BADADDR);
	MakeName(0x3C4F9, "SND_UseAdlibSound");
	OpOff(0x3C4FC, 1, 0x3F600);
	MakeComm(0x3C4FC, "Name of the driver file");
	OpDecimal(0x3C4FF, 1);
	MakeComm(0x3C4FF, "Size of the driver file in bytes");
	OpEnumEx(0x3C505, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C50A, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpDecimal(0x3C51C, 1);

	MakeFunction(0x3C52C, BADADDR);
	MakeName(0x3C52C, "SND_UseBlasterSound");
	OpOff(0x3C52F, 1, 0x3F600);
	MakeComm(0x3C52F, "Name of the driver file");
	OpDecimal(0x3C532, 1);
	MakeComm(0x3C532, "Size of the driver file in bytes");
	OpOff(0x3C538, 1, 0x3F600);
	MakeComm(0x3C538, "Name of the driver file");
	OpDecimal(0x3C53B, 1);
	MakeComm(0x3C53B, "Size of the driver file in bytes");
	OpEnumEx(0x3C541, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C546, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpDecimal(0x3C558, 1);

	MakeFunction(0x3C568, BADADDR);
	MakeName(0x3C568, "SND_UseRolandSound");
	OpOff(0x3C56B, 1, 0x3F600);
	MakeComm(0x3C56B, "Name of the driver file");
	OpDecimal(0x3C56E, 1);
	MakeComm(0x3C56E, "Size of the driver file in bytes");
	OpEnumEx(0x3C574, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C579, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpDecimal(0x3C58B, 1);

	MakeFunction(0x3C59B, BADADDR);
	MakeName(0x3C59B, "SND_UseCombinedSound");
	OpOff(0x3C59E, 1, 0x3F600);
	MakeComm(0x3C59E, "Name of the driver file");
	OpDecimal(0x3C5A1, 1);
	MakeComm(0x3C5A1, "Size of the driver file in bytes");
	OpOff(0x3C5A7, 1, 0x3F600);
	MakeComm(0x3C5A7, "Name of the driver file");
	OpDecimal(0x3C5AA, 1);
	MakeComm(0x3C5AA, "Size of the driver file in bytes");
	OpEnumEx(0x3C5B0, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C5B5, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpDecimal(0x3C5C7, 1);

	MakeFunction(0x3C5D7, BADADDR);
	MakeName(0x3C5D7, "SND_LoadSmallDriver");
	MakeName(0x3C5E1, "@@SmallDriverFileOpenOk");
	OpOff(0x3C5F1, 1, 0x4D570);
	MakeName(0x3C5FC, "@@SmallDriverFileReadOk");
	MakeName(0x3C60B, "@@SmallDriverFileCloseOk");

	MakeFunction(0x3C60C, BADADDR);
	MakeName(0x3C60C, "SND_LoadLargeDriver");
	MakeName(0x3C616, "@@LargeDriverFileOpenOk");
	OpOff(0x3C626, 1, 0x4EB60);
	MakeName(0x3C631, "@@LargeDriverFileReadOk");
	MakeName(0x3C640, "@@LargeDriverFileCloseOk");

	MakeFunction(0x3C641, BADADDR);
	MakeName(0x3C641, "SND_UninitSoundDriver");
	OpEnumEx(0x3C646, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C64D, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C64F, "Call the sound driver");
	MakeComm(0x3C651, "");
	MakeComm(0x3C655, "");
	MakeName(0x3C659, "@@UninitAdlib");
	OpEnumEx(0x3C659, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	MakeComm(0x3C660, "ADLIB address/status port");
	OpEnumEx(0x3C663, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C665, "Call the sound driver");
	MakeName(0x3C669, "@@UninitRoland");
	OpEnumEx(0x3C669, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C670, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C672, "Call the sound driver");
	OpEnumEx(0x3C674, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C676, "Call the sound driver");
	MakeName(0x3C678, "@@UninitSample");
	OpEnumEx(0x3C678, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C67D, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C684, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C686, "Call the sound driver");
	MakeName(0x3C68A, "@@UninitBlaster");
	OpEnumEx(0x3C68A, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C691, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C693, "Call the sound driver");
	MakeName(0x3C695, "@@SndUninitComplete");
	OpEnumEx(0x3C695, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);

	MakeFunction(0x3C69B, BADADDR);
	MakeName(0x3C69B, "SND_InitSmallDriver");
	MakeName(0x3C6A3, "@@DoInitBeep");
	OpEnumEx(0x3C6A3, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C6AA, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C6AD, "Call the sound driver");
	MakeName(0x3C6B6, "@@DoInitAdlib");
	OpEnumEx(0x3C6B6, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	MakeComm(0x3C6BD, "ADLIB address/status port");
	OpEnumEx(0x3C6C0, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C6C3, "Call the sound driver");
	MakeName(0x3C6CC, "@@DoInitRoland");
	OpEnumEx(0x3C6CC, 1, GetEnum("SOUND_DRIVER_TYPE"), 0);
	OpEnumEx(0x3C6D3, 1, GetEnum("SOUND_DRIVER_FUNC"), 0);
	MakeComm(0x3C6D6, "Call the sound driver");
	MakeName(0x3C6DD, "@@SndInitComplete");

	MakeFunction(0x3C6DE, BADADDR);
	MakeName(0x3C6DE, "SND_zzz");

	MakeFunction(0x3C71E, BADADDR);
	MakeName(0x3C71E, "SND_qqq");

	MakeFunction(0x3C747, BADADDR);
	MakeName(0x3C747, "SND_ttt");

	MakeFunction(0x3C7B0, BADADDR);
	MakeName(0x3C7B0, "SND_ppp");

	MakeFunction(0x3C819, BADADDR);
	MakeName(0x3C819, "SND_mmm");

	MakeFunction(0x3C882, BADADDR);
	MakeName(0x3C882, "SND_nnn");

	MakeFunction(0x3C8EB, BADADDR);
	MakeName(0x3C8EB, "SND_aaa");

	MakeFunction(0x3C955, BADADDR);
	MakeName(0x3C955, "SND_bbb");

	MakeFunction(0x3C9BE, BADADDR);
	MakeName(0x3C9BE, "SND_ccc");

	MakeFunction(0x3CA30, BADADDR);
	MakeName(0x3CA30, "SND_ddd");

	MakeFunction(0x3CA60, BADADDR);
	//MakeName(0x3CA60, "");
	OpEnumEx(0x3CA66, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CA76, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CA8A, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CA91, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CA98, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CA9F, 1, GetEnum("MAP_ELEMENT"), 0);

	OpEnumEx(0x3CCAC, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCB3, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCBB, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCC3, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCCA, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCD1, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCD8, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCDF, 1, GetEnum("MAP_ELEMENT"), 0);
	OpEnumEx(0x3CCE6, 1, GetEnum("MAP_ELEMENT"), 0);

	
	OpOff(0x3EFD7, 1, 0x00000);
	OpOff(0x3EFDA, 1, 0x00000);

	
	OpOff(0x3F018, 1, 0x00000);
	OpOff(0x3F01B, 1, 0x00000);

	
	OpOff(0x3F06A, 1, 0x00000);
	OpOff(0x3F072, 1, 0x00000);
	OpDecimal(0x3F079, 1);

	MakeFunction(0x3F08B, BADADDR);
	MakeName(0x3F08B, "VID_DrawBottomPanel");

	
	OpOff(0x3F098, 1, 0x00000);
	OpOff(0x3F09B, 1, 0x3F600);
	OpDecimal(0x3F0A1, 1);
	OpOff(0x3F0B5, 1, 0x3F600);
	OpOff(0x3F0B8, 1, 0x00000);

	MakeFunction(0x3F1A0, BADADDR);
	MakeName(0x3F1A0, "GenerateRandomNumber2");
	OpDecimal(0x3F1A3, 1);
	OpDecimal(0x3F1A8, 1);

	MakeFunction(0x3F409, BADADDR);
	MakeName(0x3F409, "InputValidationCode");
	OpOff(0x3F40B, 1, 0x36C20);
	OpOff(0x3F40E, 1, 0x36C20);
	OpDecimal(0x3F417, 1);
	OpDecimal(0x3F44C, 1);
	OpDecimal(0x3F44F, 1);
	OpDecimal(0x3F45E, 1);
	OpOff(0x3F461, 1, 0x36C20);
	OpDecimal(0x3F478, 1);
	OpOff(0x3F47B, 1, 0x36C20);
	OpDecimal(0x3F4BD, 1);
	OpDecimal(0x3F4C4, 1);
	OpDecimal(0x3F4CA, 1);
	OpDecimal(0x3F4D1, 1);
	OpOff(0x3F4E3, 1, 0x3F600);
	OpDecimal(0x3F4E6, 1);
	OpDecimal(0x3F4ED, 1);
	OpDecimal(0x3F4F3, 1);
	OpDecimal(0x3F4FA, 1);
	OpOff(0x3F502, 1, 0x3F600);
	OpOff(0x3F505, 1, 0x3F600);
	OpOff(0x3F50D, 1, 0x3F600);
	OpOff(0x3F510, 1, 0x3F600);
	OpOff(0x3F518, 1, 0x3F600);
	OpDecimal(0x3F52D, 1);
	OpChr(0x3F531, 1);
	OpChr(0x3F539, 1);
	OpChr(0x3F541, 1);
	OpChr(0x3F549, 1);
	OpChr(0x3F551, 1);
	OpChr(0x3F559, 1);
	OpChr(0x3F561, 1);
	OpChr(0x3F569, 1);
	OpChr(0x3F571, 1);
	OpChr(0x3F579, 1);
	OpDecimal(0x3F57D, 1);
	OpChr(0x3F581, 1);
	OpChr(0x3F58D, 1);
	OpOff(0x3F5C2, 1, 0x3F600);
	OpDecimal(0x3F5C5, 1);
	OpChr(0x3F5C9, 1);
	OpChr(0x3F5D4, 1);
	OpChr(0x3F5DD, 1);

	// --------------------------------------------
	// Variables

	MakeUnkn(0x7E00, 0);
	MakeByte(0x7E00);
	MakeArray(0x7E00, 32000);
	MakeName(0x7E00, "MenuDat");
	OpDecimal(0x7E00, -1);

	MakeUnkn(0xFB00, 0);
	MakeByte(0xFB00);
	MakeArray(0xFB00, 32000);
	MakeName(0xFB00, "GfxDat");
	OpDecimal(0xFB00, -1);

	MakeUnkn(0x17800, 0);
	MakeByte(0x17800);
	MakeArray(0x17800, 32000);
	MakeName(0x17800, "ControlsDat");
	OpDecimal(0x17800, -1);

	MakeUnkn(0x1F500, 0);
	MakeByte(0x1F500);
	MakeArray(0x1F500, 32000);
	MakeName(0x1F500, "GradientBackgroundImage");
	OpDecimal(0x1F500, -1);

	MakeByte(0x27216);
	MakeName(0x27216, "DemoData");
	MakeArray(0x27216, 64010);

	MakeByte(0x3FC10);
	MakeName(0x3FC10, "SavedVideoMode");

	MakeByte(0x3FC11);
	MakeArray(0x3FC11, 17);
	MakeName(0x3FC11, "TmpPalette");

	MakeName(0x3FC30, "EnableJoystick");
	MakeName(0x3FC31, "JoystickButtons");
	MakeName(0x3FC36, "JoystickCalibrated");
	MakeName(0x3FC37, "JoystickMinX");
	MakeName(0x3FC39, "JoystickMinY");
	MakeName(0x3FC3B, "JoystickMaxX");	// StepX ?
	MakeName(0x3FC3D, "JoystickMaxY");	// StepY ?
	MakeName(0x3FC3F, "JoystickX");
	MakeName(0x3FC41, "JoystickY");

	MakeWord(0x3FD66);
	MakeName(0x3FD66, "FileHandle");

	MakeName(0x3FD68, "FileIoBuffer");

	MakeUnkn(0x4038C, 0);
	MakeUnkn(0x4038E, 0);
	MakeDword(0x4038C);
	MakeName(0x4038C, "SavedInt8");

	MakeName(0x403B3, "PlayerPosition_MapX");
	MakeName(0x403B5, "PlayerPosition_MapY");

	MakeName(0x403B9, "PlayerPosition_Ofs");

	MakeName(0x40396, "VID_HorizontalPanning");
	MakeComm(0x40396, "Number of pixels that the video data is shifted to the left");

	MakeUnkn(0x40397, 0);
	MakeUnkn(0x40399, 0);
	MakeDword(0x40397);
	MakeName(0x40397, "SavedInt24");

	MakeName(0x403AC, "PlayerPosition2_MapX");
	MakeName(0x403AE, "PlayerPosition2_MapY");

	MakeName(0x403CF, "CurrentDemoOffset");

	MakeWord(0x403D4);
	MakeName(0x403D4, "FileHandle2");

	MakeName(0x403D8, "PlayerPosition_PixelsX");
	MakeName(0x403DA, "PlayerPosition_PixelsY");

	MakeName(0x40C57, "VID_VgaMemStartAddress");
	MakeComm(0x40C57, "Used to scroll the screen");

	MakeUnkn(0x40C6D, 0);
	MakeUnkn(0x40C6E, 0);
	MakeUnkn(0x40C6F, 0);
	MakeUnkn(0x40C70, 0);
	MakeUnkn(0x40C71, 0);
	MakeUnkn(0x40C72, 0);
	MakeUnkn(0x40C73, 0);
	MakeUnkn(0x40C74, 0);
	MakeUnkn(0x40C75, 0);
	MakeUnkn(0x40C76, 0);
	MakeUnkn(0x40C77, 0);
	MakeUnkn(0x40C78, 0);
	MakeUnkn(0x40C79, 0);
	MakeUnkn(0x40C7A, 0);
	MakeUnkn(0x40C7B, 0);
	MakeUnkn(0x40C7C, 0);
	MakeUnkn(0x40C7D, 0);
	MakeUnkn(0x40C7E, 0);
	MakeUnkn(0x40C7F, 0);
	MakeUnkn(0x40C80, 0);
	MakeUnkn(0x40C81, 0);
	MakeUnkn(0x40C82, 0);
	MakeUnkn(0x40C83, 0);
	MakeUnkn(0x40C84, 0);
	MakeUnkn(0x40C85, 0);
	MakeUnkn(0x40C86, 0);
	MakeUnkn(0x40C87, 0);
	MakeUnkn(0x40C88, 0);
	MakeUnkn(0x40C89, 0);
	MakeUnkn(0x40C8A, 0);
	MakeUnkn(0x40C8B, 0);
	MakeUnkn(0x40C8C, 0);
	MakeUnkn(0x40C8D, 0);
	MakeUnkn(0x40C8E, 0);
	MakeUnkn(0x40C8F, 0);
	MakeUnkn(0x40C90, 0);
	MakeUnkn(0x40C91, 0);
	MakeUnkn(0x40C92, 0);
	MakeUnkn(0x40C93, 0);
	MakeUnkn(0x40C94, 0);
	MakeUnkn(0x40C95, 0);
	MakeUnkn(0x40C96, 0);
	MakeUnkn(0x40C97, 0);
	MakeUnkn(0x40C98, 0);
	MakeUnkn(0x40C99, 0);
	MakeUnkn(0x40C9A, 0);
	MakeUnkn(0x40C9B, 0);
	MakeUnkn(0x40C9C, 0);
	MakeUnkn(0x40C9D, 0);
	MakeUnkn(0x40C9E, 0);
	MakeUnkn(0x40C9F, 0);
	MakeUnkn(0x40CA0, 0);
	MakeUnkn(0x40CA1, 0);
	MakeUnkn(0x40CA2, 0);
	MakeUnkn(0x40CA3, 0);
	MakeUnkn(0x40CA4, 0);
	MakeUnkn(0x40CA5, 0);
	MakeUnkn(0x40CA6, 0);
	MakeUnkn(0x40CA7, 0);
	MakeUnkn(0x40CA8, 0);
	MakeUnkn(0x40CA9, 0);
	MakeUnkn(0x40CAA, 0);
	MakeUnkn(0x40CAB, 0);
	MakeUnkn(0x40CAC, 0);
	MakeUnkn(0x40CAD, 0);
	MakeUnkn(0x40CAE, 0);
	MakeUnkn(0x40CAF, 0);
	MakeUnkn(0x40CB0, 0);
	MakeUnkn(0x40CB1, 0);
	MakeUnkn(0x40CB2, 0);
	MakeUnkn(0x40CB3, 0);
	MakeUnkn(0x40CB4, 0);
	MakeUnkn(0x40CB5, 0);
	MakeUnkn(0x40CB6, 0);
	MakeUnkn(0x40CB7, 0);
	MakeUnkn(0x40CB8, 0);
	MakeUnkn(0x40CB9, 0);
	MakeUnkn(0x40CBA, 0);
	MakeUnkn(0x40CBB, 0);
	MakeUnkn(0x40CBC, 0);
	MakeUnkn(0x40CBD, 0);
	MakeUnkn(0x40CBE, 0);
	MakeUnkn(0x40CBF, 0);
	MakeUnkn(0x40CC0, 0);
	MakeUnkn(0x40CC1, 0);
	MakeUnkn(0x40CC2, 0);
	MakeUnkn(0x40CC3, 0);
	MakeUnkn(0x40CC4, 0);
	MakeUnkn(0x40CC5, 0);
	MakeUnkn(0x40CC6, 0);
	MakeUnkn(0x40CC7, 0);
	MakeUnkn(0x40CC8, 0);
	MakeUnkn(0x40CC9, 0);
	MakeUnkn(0x40CCA, 0);
	MakeUnkn(0x40CCB, 0);
	MakeUnkn(0x40CCC, 0);
	MakeUnkn(0x40CCD, 0);
	MakeUnkn(0x40CCE, 0);
	MakeUnkn(0x40CCF, 0);
	MakeUnkn(0x40CD0, 0);
	MakeUnkn(0x40CD1, 0);
	MakeUnkn(0x40CD2, 0);
	MakeUnkn(0x40CD3, 0);
	MakeUnkn(0x40CD4, 0);
	MakeUnkn(0x40CD5, 0);
	MakeUnkn(0x40CD6, 0);
	MakeUnkn(0x40CD7, 0);
	MakeUnkn(0x40CD8, 0);
	MakeUnkn(0x40CD9, 0);
	MakeUnkn(0x40CDA, 0);
	MakeUnkn(0x40CDB, 0);
	MakeUnkn(0x40CDC, 0);
	MakeUnkn(0x40CDD, 0);
	MakeUnkn(0x40CDE, 0);
	MakeUnkn(0x40CDF, 0);
	MakeUnkn(0x40CE0, 0);
	MakeUnkn(0x40CE1, 0);
	MakeUnkn(0x40CE2, 0);
	MakeUnkn(0x40CE3, 0);
	MakeUnkn(0x40CE4, 0);
	MakeUnkn(0x40CE5, 0);
	MakeUnkn(0x40CE6, 0);
	MakeUnkn(0x40CE7, 0);
	MakeUnkn(0x40CE8, 0);
	MakeUnkn(0x40CE9, 0);
	MakeUnkn(0x40CEA, 0);
	MakeUnkn(0x40CEB, 0);
	MakeUnkn(0x40CEC, 0);
	MakeStructEx(0x40C6D, 0x7F, "KEYBOARD_STATE");
	MakeName(0x40C6D, "KeyboardState");

	MakeUnkn(0x40CED, 0);
	MakeUnkn(0x40CEF, 0);
	MakeDword(0x40CED);
	MakeName(0x40CED, "SavedInt9");

	MakeName(0x40CF9, "KeyPressed");

	MakeName(0x40DAF, "LEVELS_DAT");

	MakeUnkn(0x40DBA, 0);
	MakeByte(0x40DBA);
	MakeArray(0x40DBA, 1440);
	MakeName(0x40DBA, "LevelMap");
	OpDecimal(0x40DBA, -1);

	MakeDword(0x4135A);
	MakeName(0x4135A, "LevelMap_Unused");

	MakeByte(0x4135E);
	MakeName(0x4135E, "LevelMap_Gravitation");
	MakeComm(0x4135E, "0=off, 1=on");

	MakeByte(0x4135F);
	MakeName(0x4135F, "LevelMap_Version");
	MakeComm(0x4135F, "0x20 = original, 0x74 = v5.4, 0x80 = v6.0");

	MakeUnkn(0x41360, 0);
	MakeByte(0x41360);
	MakeArray(0x41360, 23);
	MakeName(0x41360, "LevelMap_Name");
	OpDecimal(0x41360, -1);

	MakeByte(0x41377);
	MakeName(0x41377, "LevelMap_FreezeZonks");
	MakeComm(0x41377, "Freeze zonks start value (0=off, 2=on) (yes 2=on, no mistake!)");

	MakeByte(0x41378);
	MakeName(0x41378, "LevelMap_InfotronsNeeded");
	MakeComm(0x41378, "0 means Supaplex will count the total number of infotrons in the level at the start and use that");

	MakeByte(0x41379);
	MakeName(0x41379, "LevelMap_NumSpecialPorts");
	MakeComm(0x41379, "Maximum 10");

	MakeStructEx(0x4137A, 6, "SPECIAL_PORT");
	MakeArray(0x4137A, 10);
	MakeName(0x4137A, "LevelMap_SpecialPorts");

	MakeDword(0x413B6);
	MakeName(0x413B6, "LevelMap_Unused2");

	MakeUnkn(0x419BA, 0);
	MakeByte(0x419BA);
	MakeArray(0x419BA, 1536);
	MakeName(0x419BA, "SomeLevelData");
	OpDecimal(0x419BA, -1);

	MakeUnkn(0x41FF2, 0);
	MakeByte(0x41FF2);
	MakeArray(0x41FF2, 3108);
	MakeName(0x41FF2, "LevelLst");
	OpDecimal(0x41FF2, -1);

	MakeStr(0x42C16, 0x42C32);
	MakeName(0x42C16, "");
	MakeStr(0x42C32, 0x42C4E);
	MakeName(0x42C32, "");

	MakeByte(0x42C4E);
	MakeArray(0x42C4E, 28);
	OpDecimal(0x42C4E, 0);

	MakeByte(0x42C6A);
	MakeArray(0x42C6A, 28);
	OpDecimal(0x42C6A, 0);

	MakeName(0x42C86, "CurrentInsertedDisk");
	MakeName(0x42C87, "msgInsertDisk1");
	MakeName(0x42C95, "msgInsertDisk2");
	MakeName(0x42CA3, "SUPAPLEX_CFG");
	MakeName(0x42CB0, "MOVING_DAT");
	MakeName(0x42CBB, "FIXED_DAT");
	MakeName(0x42CC5, "PANEL_DAT");
	MakeName(0x42CCF, "MENU_DAT");
	MakeName(0x42CD8, "TITLE_DAT");
	MakeName(0x42CE2, "TITLE1_DAT");
	MakeName(0x42CED, "TITLE2_DAT");
	MakeName(0x42CF8, "BACK_DAT");
	MakeName(0x42D01, "GFX_DAT");
	MakeName(0x42D09, "CHARS6_DAT");
	MakeName(0x42D14, "CHARS8_DAT");
	MakeName(0x42D1F, "LEVEL_LST");
	MakeName(0x42D29, "CONTROLS_DAT");
	MakeName(0x42D36, "BEEP_SND");
	MakeName(0x42D3F, "SAMPLE_SND");
	MakeName(0x42D4A, "ADLIB_SND");
	MakeName(0x42D54, "ROLAND_SND");
	MakeName(0x42D5F, "BLASTER_SND");
	MakeName(0x42D6B, "PLAYER_LST");
	MakeName(0x42D76, "PALETTES_DAT");
	MakeName(0x42D83, "HALLFAME_LST");
	MakeName(0x42D90, "DEMO0_BIN");

	MakeName(0x42D9A, "UseDirectVideoAdapterAccess");
	MakeComm(0x42D9A, "1 = Use BIOS calls, 2 = Use Direct access");

	MakeUnkn(0x42D9B, 0);
	MakeByte(0x42D9B);
	MakeArray(0x42D9B, 5120);
	MakeName(0x42D9B, "Fixed");
	OpDecimal(0x42D9B, -1);

	MakeUnkn(0x4419B, 0);
	MakeByte(0x4419B);
	MakeArray(0x4419B, 3840);
	MakeName(0x4419B, "PanelImage");
	OpDecimal(0x4419B, -1);

	MakeUnkn(0x4509B, 0);
	MakeByte(0x4509B);
	MakeArray(0x4509B, 512);
	MakeName(0x4509B, "Chars6");
	OpDecimal(0x4509B, -1);

	MakeUnkn(0x4529B, 0);
	MakeByte(0x4529B);
	MakeArray(0x4529B, 512);
	MakeName(0x4529B, "Chars8");
	OpDecimal(0x4529B, -1);

	MakeName(0x4549B, "VID_xxx_Palette");
	for (i = 0; i < 16; i++)
	{
		MakeUnkn(0x4549B + i * 4, 0);
		MakeDword(0x4549B + i * 4);
	}

	MakeName(0x454DB, "VID_MenuPalette");
	for (i = 0; i < 16; i++)
	{
		MakeUnkn(0x454DB + i * 4, 0);
		MakeDword(0x454DB + i * 4);
	}

	MakeName(0x4551B, "VID_TitlePalette");
	for (i = 0; i < 16; i++)
	{
		MakeUnkn(0x4551B + i * 4, 0);
		MakeDword(0x4551B + i * 4);
	}

	MakeUnkn(0x4555B, 0);
	MakeByte(0x4555B);
	MakeArray(0x4555B, 256);
	MakeName(0x4555B, "Palettes");
	OpDecimal(0x4555B, -1);

	MakeName(0x4565B, "VID_yyy_Palette");
	MakeDword(0x4565B);
	MakeArray(0x4565B, 16);
	OpDecimal(0x4565B, -1);

	MakeWord(0x456CB);
	MakeArray(0x456CB, 1440);

	MakeWord(0x4622F);
	MakeName(0x4622F, "RandomSeed");

	MakeName(0x4B06F, "MousePosX");

	MakeName(0x4B073, "MousePosY");
	MakeName(0x4B075, "HaveMouse");

	MakeName(0x4B99A, "PlayerLst");
	for (i = 0; i < 20; i++)
	{
		MakeUnkn(0x4B99A + i * 128, 0);
		MakeStr(0x4B99A + i * 128, 0x4B99A + i * 128 + 8);
		MakeByte(0x4B99A + i * 128 + 8);
		MakeArray(0x4B99A + i * 128 + 8, 120);
		OpDecimal(0x4B99A + i * 128 + 8, -1);
	}

	MakeName(0x4C412, "HallfameLst");
	for (i = 0; i < 8; i++)
	{
		MakeUnkn(0x4C412 + i * 12, 0);
		MakeStr(0x4C412 + i * 12, 0x4C412 + i * 12 + 8);
		MakeDword(0x4C412 + i * 12 + 8);
	}

	MakeName(0x4C472, "SoundInitialized");
	MakeName(0x4C473, "SoundEffectsEnabled");
	MakeName(0x4C474, "MusicEnabled");
	MakeName(0x4C475, "SoundDriver");
	MakeComm(0x4C475, "ID of the currently loaded int80 handler");
	MakeName(0x4C476, "SoundDriverExt");
	MakeComm(0x4C476, "ID of the currently loaded int81 handler");
	MakeName(0x4C477, "SND_var_xxx");
	MakeName(0x4C478, "SND_var_yyy");
	MakeName(0x4C479, "SND_var_zzz");
	MakeName(0x4C47A, "SND_var_aaa");

	MakeName(0x4D430, "RandomSeed2");

	MakeName(0x4D434, "ExpectedValidationCode");

	MakeUnkn(0x4D448, 0);
	MakeStr(0x4D454, BADADDR);
	MakeStr(0x4D448, 0x4D450);
	MakeStr(0x4D450, 0x4D454);

	MakeStr(0x4D460, BADADDR);
	MakeName(0x4D460, "DosErrorMessages");

	MakeStr(0x4D161, BADADDR);
	MakeName(0x4D461, "MSG_DosError1");
	MakeStr(0x4D484, BADADDR);
	MakeName(0x4D484, "MSG_DosError2");
	MakeStr(0x4D49E, BADADDR);
	MakeName(0x4D49E, "MSG_DosError3");
	MakeStr(0x4D4B8, BADADDR);
	MakeName(0x4D4B8, "MSG_DosError4");
	MakeStr(0x4D4D7, BADADDR);
	MakeName(0x4D4D7, "MSG_DosError5");
	MakeStr(0x4D4F0, BADADDR);
	MakeName(0x4D4F0, "MSG_DosError6");

	MakeUnkn(0x4D50A, 0);
	MakeByte(0x4D50A);
	MakeArray(0x4D50A, 102);
	OpDecimal(0x4D50A, -1);

	MakeCode(0x4D570);
	MakeFunction(0x4D570, 0x4D571);
	MakeName(0x4D570, "Int80_Handler");
	MakeByte(0x4D571);
	MakeArray(0x4D571, 5615);
	OpDecimal(0x4D571, -1);

	MakeCode(0x4EB60);
	MakeFunction(0x4EB60, 0x4EB61);
	MakeName(0x4EB60, "Int81_Handler");
	MakeByte(0x4EB61);
	MakeArray(0x4EB61, 40015);
	OpDecimal(0x4EB61, -1);

	MakeByte(0x587B0);
	MakeArray(0x587B0, 1024);
	OpDecimal(0x587B0, -1);
}
