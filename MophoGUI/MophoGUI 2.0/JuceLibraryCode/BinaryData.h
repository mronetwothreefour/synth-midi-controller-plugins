/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   OverpassBold_ttf;
    const int            OverpassBold_ttfSize = 123228;

    extern const char*   bkgrnd_MainWindow_png;
    const int            bkgrnd_MainWindow_pngSize = 93983;

    extern const char*   btn_Clear_Dn_png;
    const int            btn_Clear_Dn_pngSize = 648;

    extern const char*   btn_Clear_Up_png;
    const int            btn_Clear_Up_pngSize = 629;

    extern const char*   btn_Edit_Dn_png;
    const int            btn_Edit_Dn_pngSize = 497;

    extern const char*   btn_Edit_Up_png;
    const int            btn_Edit_Up_pngSize = 487;

    extern const char*   btn_Read_Dn_png;
    const int            btn_Read_Dn_pngSize = 621;

    extern const char*   btn_Read_Up_png;
    const int            btn_Read_Up_pngSize = 599;

    extern const char*   btn_Redo_Dn_png;
    const int            btn_Redo_Dn_pngSize = 625;

    extern const char*   btn_Redo_Up_png;
    const int            btn_Redo_Up_pngSize = 576;

    extern const char*   btn_Undo_Dn_png;
    const int            btn_Undo_Dn_pngSize = 569;

    extern const char*   btn_Undo_Up_png;
    const int            btn_Undo_Up_pngSize = 575;

    extern const char*   btn_Write_Dn_png;
    const int            btn_Write_Dn_pngSize = 652;

    extern const char*   btn_Write_Up_png;
    const int            btn_Write_Up_pngSize = 597;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 14;

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
