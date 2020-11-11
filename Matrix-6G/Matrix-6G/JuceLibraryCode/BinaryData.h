#pragma once

namespace BinaryData
{
    extern const char* SWISSB_TTF;
    const int            SWISSB_TTFSize = 36852;

    extern const char* Matrix6GMainWindowBackground_png;
    const int            Matrix6GMainWindowBackground_pngSize = 49864;

    extern const char* ButtonMasterDown_png;
    const int            ButtonMasterDown_pngSize = 865;

    extern const char* ButtonMasterUp_png;
    const int            ButtonMasterUp_pngSize = 862;

    extern const char* ButtonPatchesDown_png;
    const int            ButtonPatchesDown_pngSize = 883;

    extern const char* ButtonPatchesUp_png;
    const int            ButtonPatchesUp_pngSize = 866;

    extern const char* ButtonQuickEditDown_png;
    const int            ButtonQuickEditDown_pngSize = 702;

    extern const char* ButtonQuickEditUp_png;
    const int            ButtonQuickEditUp_pngSize = 706;

    extern const char* ButtonQuickEditFlash_png;
    const int            ButtonQuickEditFlash_pngSize = 705;

    extern const char* ButtonRedoDown_png;
    const int            ButtonRedoDown_pngSize = 436;

    extern const char* ButtonRedoUp_png;
    const int            ButtonRedoUp_pngSize = 446;

    extern const char* ButtonSplitsDown_png;
    const int            ButtonSplitsDown_pngSize = 673;

    extern const char* ButtonSplitsUp_png;
    const int            ButtonSplitsUp_pngSize = 690;

    extern const char* ButtonUndoDown_png;
    const int            ButtonUndoDown_pngSize = 410;

    extern const char* ButtonUndoUp_png;
    const int            ButtonUndoUp_pngSize = 432;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 15;

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
