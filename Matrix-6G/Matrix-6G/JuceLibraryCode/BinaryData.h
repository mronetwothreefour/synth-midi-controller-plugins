#pragma once

namespace BinaryData
{
    extern const char* SWISSB_TTF;
    const int            SWISSB_TTFSize = 36852;

    extern const char* SWISSCL_TTF;
    const int            SWISSCL_TTFSize = 35064;

    extern const char* ButtonLoadDown_png;
    const int            ButtonLoadDown_pngSize = 477;

    extern const char* ButtonLoadUp_png;
    const int            ButtonLoadUp_pngSize = 461;

    extern const char* ButtonMasterDown_png;
    const int            ButtonMasterDown_pngSize = 882;

    extern const char* ButtonMasterUp_png;
    const int            ButtonMasterUp_pngSize = 835;

    extern const char* ButtonPatchesDown_png;
    const int            ButtonPatchesDown_pngSize = 883;

    extern const char* ButtonPatchesUp_png;
    const int            ButtonPatchesUp_pngSize = 866;

    extern const char* ButtonPullDown_png;
    const int            ButtonPullDown_pngSize = 391;

    extern const char* ButtonPullUp_png;
    const int            ButtonPullUp_pngSize = 382;

    extern const char* ButtonPushDown_png;
    const int            ButtonPushDown_pngSize = 530;

    extern const char* ButtonPushUp_png;
    const int            ButtonPushUp_pngSize = 455;

    extern const char* ButtonQuickEditDown_png;
    const int            ButtonQuickEditDown_pngSize = 756;

    extern const char* ButtonQuickEditFlash_png;
    const int            ButtonQuickEditFlash_pngSize = 681;

    extern const char* ButtonQuickEditUp_png;
    const int            ButtonQuickEditUp_pngSize = 707;

    extern const char* ButtonRedoDown_png;
    const int            ButtonRedoDown_pngSize = 401;

    extern const char* ButtonRedoUp_png;
    const int            ButtonRedoUp_pngSize = 418;

    extern const char* ButtonSaveDown_png;
    const int            ButtonSaveDown_pngSize = 602;

    extern const char* ButtonSaveUp_png;
    const int            ButtonSaveUp_pngSize = 525;

    extern const char* ButtonSplitsDown_png;
    const int            ButtonSplitsDown_pngSize = 673;

    extern const char* ButtonSplitsUp_png;
    const int            ButtonSplitsUp_pngSize = 690;

    extern const char* ButtonUndoDown_png;
    const int            ButtonUndoDown_pngSize = 425;

    extern const char* ButtonUndoUp_png;
    const int            ButtonUndoUp_pngSize = 433;

    extern const char* Matrix6GMainWindowBackground_png;
    const int            Matrix6GMainWindowBackground_pngSize = 51164;

    extern const char* PatchesButtonCloseDown_png;
    const int            PatchesButtonCloseDown_pngSize = 225;

    extern const char* PatchesButtonCloseUp_png;
    const int            PatchesButtonCloseUp_pngSize = 225;

    extern const char* PatchesFooterForCustomBanks_png;
    const int            PatchesFooterForCustomBanks_pngSize = 1356;

    extern const char* PatchesFooterForFactoryBanks_png;
    const int            PatchesFooterForFactoryBanks_pngSize = 1354;

    extern const char* PatchesHeader_png;
    const int            PatchesHeader_pngSize = 2478;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 29;

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
