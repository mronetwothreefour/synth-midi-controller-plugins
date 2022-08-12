/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   btn_SwitchTab_png;
    const int            btn_SwitchTab_pngSize = 139;

    extern const char*   bkgrnd_MainWindow_png;
    const int            bkgrnd_MainWindow_pngSize = 1136073;

    extern const char*   SWISSB_TTF;
    const int            SWISSB_TTFSize = 36852;

    extern const char*   SWISSCK_TTF;
    const int            SWISSCK_TTFSize = 38696;

    extern const char*   SWISSCL_TTF;
    const int            SWISSCL_TTFSize = 35064;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 5;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
