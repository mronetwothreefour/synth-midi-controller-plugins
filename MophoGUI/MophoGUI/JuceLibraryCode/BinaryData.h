#pragma once

namespace BinaryData
{
    extern const char* OverpassBold_ttf;
    const int            OverpassBold_ttfSize = 123228;

    extern const char* MophoGUIMainWindowBackground_png;
    const int            MophoGUIMainWindowBackground_pngSize = 97029;

    extern const char* ButtonDownProgramNameEdit_png;
    const int            ButtonDownProgramNameEdit_pngSize = 514;

    extern const char* ButtonUpProgramNameEdit_png;
    const int            ButtonUpProgramNameEdit_pngSize = 495;

    extern const char* ButtonDownWrite_png;
    const int            ButtonDownWrite_pngSize = 676;

    extern const char* ButtonUpWrite_png;
    const int            ButtonUpWrite_pngSize = 618;

    extern const char* ButtonDownRead_png;
    const int            ButtonDownRead_pngSize = 618;

    extern const char* ButtonUpRead_png;
    const int            ButtonUpRead_pngSize = 613;

    extern const char* ButtonDownBanks_png;
    const int            ButtonDownBanks_pngSize = 729;

    extern const char* ButtonUpBanks_png;
    const int            ButtonUpBanks_pngSize = 695;

    extern const char* ButtonDownGlobal_png;
    const int            ButtonDownGlobal_pngSize = 702;

    extern const char* ButtonUpGlobal_png;
    const int            ButtonUpGlobal_pngSize = 702;

    extern const char* ButtonDownUndo_png;
    const int            ButtonDownUndo_pngSize = 582;

    extern const char* ButtonUpUndo_png;
    const int            ButtonUpUndo_pngSize = 570;

    extern const char* ButtonDownRedo_png;
    const int            ButtonDownRedo_pngSize = 641;

    extern const char* ButtonUpRedo_png;
    const int            ButtonUpRedo_pngSize = 593;

    extern const char* ButtonDownClear_png;
    const int            ButtonDownClear_pngSize = 648;

    extern const char* ButtonUpClear_png;
    const int            ButtonUpClear_pngSize = 629;

    extern const char* ButtonDownClose_png;
    const int            ButtonDownClose_pngSize = 669;

    extern const char* ButtonUpClose_png;
    const int            ButtonUpClose_pngSize = 661;

    extern const char* ButtonDownLoad_png;
    const int            ButtonDownLoad_pngSize = 633;

    extern const char* ButtonUpLoad_png;
    const int            ButtonUpLoad_pngSize = 598;

    extern const char* ButtonDownSave_png;
    const int            ButtonDownSave_pngSize = 629;

    extern const char* ButtonUpSave_png;
    const int            ButtonUpSave_pngSize = 635;

    extern const char* ButtonDownPush_png;
    const int            ButtonDownPush_pngSize = 600;

    extern const char* ButtonUpPush_png;
    const int            ButtonUpPush_pngSize = 586;

    extern const char* ButtonDownPull_png;
    const int            ButtonDownPull_pngSize = 546;

    extern const char* ButtonUpPull_png;
    const int            ButtonUpPull_pngSize = 528;

    extern const char* ButtonDownReset_png;
    const int            ButtonDownReset_pngSize = 640;

    extern const char* ButtonUpReset_png;
    const int            ButtonUpReset_pngSize = 615;

    extern const char* ProgramBanksTabBackground_png;
    const int            ProgramBanksTabBackground_pngSize = 4579;

    extern const char* LabelBank1_png;
    const int            LabelBank1_pngSize = 510;

    extern const char* LabelBank2_png;
    const int            LabelBank2_pngSize = 528;

    extern const char* LabelBank3_png;
    const int            LabelBank3_pngSize = 536;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 34;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource(const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename(const char* resourceNameUTF8);
}
