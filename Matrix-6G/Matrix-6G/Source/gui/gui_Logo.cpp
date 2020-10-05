#include "gui_Logo.h"

#include "gui_Colors.h"



Logo::Logo() {
    auto logo_w{ 211 };
    auto logo_h{ 33 };
    setSize(logo_w, logo_h);
}

void Logo::paint(Graphics& g) {
    static const unsigned char pathData[] = { 110,109,41,92,183,65,174,71,2,66,108,215,163,180,65,194,245,1,66,98,41,92,173,65,122,20,1,66,174,71,167,65,61,10,0,66,82,184,162,65,142,194,253,65,98,113,61,158,65,162,112,251,65,236,81,152,65,152,153,247,65,184,30,145,65,101,102,242,65,98,123,20,140,
    65,101,102,238,65,143,194,135,65,244,40,234,65,123,20,132,65,19,174,229,65,98,62,10,127,65,121,20,224,65,0,0,120,65,132,235,217,65,62,10,115,65,40,92,211,65,108,236,81,36,65,244,40,84,65,108,174,71,13,65,102,102,230,65,98,215,163,12,65,51,51,233,65,102,
    102,14,65,153,153,235,65,102,102,18,65,133,235,237,65,98,41,92,19,65,92,143,238,65,143,194,21,65,133,235,239,65,215,163,28,65,51,51,243,65,98,154,153,33,65,153,153,245,65,20,174,39,65,31,133,247,65,72,225,46,65,194,245,248,65,108,215,163,44,65,81,184,
    254,65,108,0,0,0,0,81,184,254,65,108,72,225,122,63,173,71,249,65,98,62,10,183,63,81,184,246,65,20,174,231,63,19,174,243,65,62,10,7,64,112,61,240,65,98,113,61,26,64,81,184,236,65,195,245,40,64,163,112,233,65,175,71,49,64,225,122,230,65,98,114,61,58,64,
    30,133,227,65,216,163,64,64,10,215,223,65,185,30,69,64,153,153,219,65,108,225,122,180,64,123,20,174,64,98,184,30,181,64,174,71,169,64,164,112,181,64,72,225,162,64,164,112,181,64,113,61,154,64,98,164,112,181,64,92,143,138,64,195,245,176,64,175,71,113,
    64,236,81,168,64,114,61,74,64,98,0,0,160,64,42,92,31,64,113,61,146,64,146,194,245,63,165,112,125,64,156,153,185,63,108,102,102,70,64,184,30,69,63,108,82,184,114,65,184,30,69,63,108,10,215,173,65,92,143,142,65,108,143,194,215,65,192,30,69,63,108,246,40,
    26,66,192,30,69,63,108,144,194,26,66,86,184,190,63,98,93,143,24,66,250,40,220,63,93,143,23,66,45,92,239,63,185,30,23,66,158,153,249,63,98,205,204,22,66,217,163,0,64,185,30,22,66,33,133,11,64,62,10,21,66,33,133,43,64,98,113,61,20,66,12,215,67,64,205,204,
    19,66,207,204,92,64,205,204,19,66,104,102,118,64,98,205,204,19,66,52,51,131,64,10,215,19,66,175,71,137,64,133,235,19,66,165,112,141,64,108,123,20,31,66,225,122,224,65,98,51,51,31,66,30,133,227,65,236,81,31,66,102,102,230,65,164,112,31,66,184,30,233,65,
    98,92,143,31,66,153,153,235,65,72,225,31,66,133,235,237,65,41,92,32,66,123,20,240,65,98,10,215,32,66,246,40,242,65,164,112,33,66,133,235,243,65,51,51,34,66,174,71,245,65,98,61,10,35,66,82,184,246,65,61,10,36,66,123,20,248,65,246,40,37,66,184,30,249,65,
    108,31,133,36,66,204,204,254,65,108,236,81,230,65,204,204,254,65,108,185,30,229,65,61,10,249,65,98,11,215,233,65,194,245,246,65,62,10,237,65,133,235,243,65,72,225,238,65,10,215,239,65,98,72,225,240,65,30,133,235,65,11,215,241,65,164,112,231,65,11,215,
    241,65,143,194,227,65,98,154,153,241,65,215,163,226,65,31,133,241,65,163,112,225,65,31,133,241,65,204,204,224,65,108,21,174,229,65,19,174,91,65,108,41,92,183,65,174,71,2,66,99,109,92,143,38,65,41,92,55,65,108,102,102,126,65,51,51,209,65,98,164,112,129,
    65,51,51,215,65,82,184,132,65,205,204,220,65,205,204,136,65,10,215,225,65,98,246,40,140,65,0,0,230,65,113,61,144,65,133,235,233,65,205,204,148,65,30,133,237,65,98,154,153,155,65,225,122,242,65,174,71,161,65,122,20,246,65,31,133,165,65,235,81,248,65,98,
    62,10,169,65,245,40,250,65,21,174,173,65,10,215,251,65,41,92,179,65,174,71,253,65,108,102,102,228,65,20,174,59,65,108,112,61,234,65,204,204,60,65,108,153,153,247,65,102,102,224,65,98,153,153,247,65,51,51,225,65,20,174,247,65,122,20,226,65,133,235,247,
    65,51,51,227,65,98,133,235,247,65,112,61,232,65,205,204,246,65,184,30,237,65,102,102,244,65,112,61,242,65,98,174,71,243,65,214,163,244,65,10,215,241,65,204,204,246,65,0,0,240,65,214,163,248,65,108,205,204,31,66,214,163,248,65,98,133,235,30,66,71,225,
    246,65,113,61,30,66,81,184,244,65,21,174,29,66,234,81,242,65,98,123,20,29,66,152,153,239,65,21,174,28,66,214,163,236,65,31,133,28,66,29,133,233,65,98,41,92,28,66,80,184,230,65,113,61,28,66,9,215,227,65,246,40,28,66,203,204,224,65,108,62,10,17,66,248,
    255,143,64,98,195,245,16,66,43,51,139,64,72,225,16,66,2,215,131,64,72,225,16,66,168,30,117,64,98,72,225,16,66,35,51,83,64,103,102,17,66,117,235,49,64,226,122,18,66,35,51,19,64,98,113,61,19,66,121,153,249,63,195,245,19,66,29,10,215,63,216,163,20,66,224,
    255,191,63,108,238,81,220,65,224,255,191,63,108,95,143,174,65,80,184,160,65,108,102,102,106,65,92,143,194,63,108,225,122,164,64,92,143,194,63,98,0,0,176,64,61,10,247,63,215,163,184,64,236,81,24,64,82,184,190,64,61,10,55,64,98,215,163,200,64,51,51,99,
    64,143,194,205,64,61,10,135,64,143,194,205,64,133,235,153,64,98,143,194,205,64,246,40,164,64,184,30,205,64,246,40,172,64,225,122,204,64,174,71,177,64,108,225,122,116,64,102,102,220,65,98,41,92,111,64,51,51,225,65,20,174,103,64,174,71,229,65,164,112,93,
    64,82,184,232,65,98,51,51,83,64,123,20,236,65,51,51,67,64,143,194,239,65,164,112,45,64,143,194,243,65,98,225,122,36,64,31,133,245,65,154,153,25,64,51,51,247,65,205,204,12,64,205,204,248,65,108,61,10,23,65,205,204,248,65,98,122,20,22,65,103,102,248,65,
    174,71,21,65,0,0,248,65,235,81,20,65,154,153,247,65,98,92,143,14,65,72,225,244,65,71,225,10,65,195,245,242,65,184,30,9,65,11,215,241,65,98,61,10,3,65,236,81,238,65,235,81,0,65,113,61,234,65,174,71,1,65,11,215,229,65,108,82,184,26,65,196,245,56,65,108,
    92,143,38,65,41,92,55,65,99,109,92,143,115,66,20,174,0,66,98,246,40,111,66,20,174,0,66,184,30,107,66,61,10,0,66,225,122,103,66,30,133,253,65,98,133,235,99,66,194,245,250,65,123,20,96,66,71,225,246,65,184,30,92,66,50,51,241,65,98,235,81,89,66,183,30,237,
    65,184,30,87,66,70,225,230,65,92,143,85,66,214,163,222,65,98,164,112,85,66,122,20,222,65,41,92,85,66,163,112,221,65,112,61,85,66,71,225,220,65,108,81,184,76,66,245,40,0,66,108,204,204,64,66,245,40,0,66,98,245,40,56,66,245,40,0,66,255,255,48,66,152,153,
    251,65,30,133,43,66,234,81,242,65,98,40,92,37,66,132,235,231,65,112,61,34,66,50,51,217,65,112,61,34,66,214,163,198,65,98,112,61,34,66,204,204,182,65,132,235,37,66,101,102,170,65,112,61,45,66,142,194,161,65,98,92,143,49,66,214,163,156,65,92,143,56,66,
    142,194,151,65,153,153,66,66,193,245,146,65,98,255,255,72,66,19,174,143,65,174,71,77,66,183,30,141,65,174,71,79,66,162,112,139,65,98,235,81,82,66,203,204,136,65,10,215,83,66,19,174,133,65,10,215,83,66,121,20,130,65,98,10,215,83,66,47,51,123,65,174,71,
    83,66,191,245,116,65,184,30,82,66,180,30,113,65,98,61,10,81,66,160,112,109,65,30,133,78,66,180,30,105,65,10,215,72,66,180,30,105,65,98,82,184,67,66,180,30,105,65,92,143,63,66,6,215,107,65,225,122,60,66,190,245,112,65,108,123,20,48,66,213,163,130,65,108,
    51,51,58,66,98,102,34,65,108,123,20,68,66,221,122,28,65,98,0,0,73,66,139,194,25,65,236,81,78,66,231,81,24,65,72,225,83,66,231,81,24,65,98,236,81,95,66,231,81,24,65,185,30,104,66,200,204,36,65,0,0,110,66,170,71,61,65,98,102,102,115,66,37,92,83,65,184,
    30,118,66,170,71,113,65,184,30,118,66,172,71,139,65,108,184,30,118,66,213,163,194,65,98,184,30,118,66,39,92,199,65,30,133,118,66,162,112,203,65,112,61,119,66,203,204,206,65,98,194,245,119,66,121,20,210,65,112,61,121,66,193,245,212,65,194,245,122,66,39,
    92,215,65,98,51,51,124,66,182,30,217,65,153,153,125,66,100,102,218,65,184,30,127,66,59,10,219,65,98,10,87,128,66,141,194,219,65,61,10,129,66,131,235,219,65,215,163,129,66,151,153,219,65,108,61,10,131,66,202,204,218,65,108,61,10,125,66,50,51,0,66,108,
    20,174,120,66,50,51,0,66,98,20,174,119,66,40,92,0,66,153,153,118,66,224,122,0,66,81,184,117,66,91,143,0,66,98,10,215,116,66,215,163,0,66,123,20,116,66,20,174,0,66,92,143,115,66,20,174,0,66,99,109,41,92,86,66,61,10,167,65,108,41,92,86,66,214,163,202,65,
    98,41,92,86,66,50,51,207,65,61,10,87,66,173,71,213,65,102,102,88,66,91,143,220,65,98,82,184,89,66,19,174,227,65,92,143,91,66,193,245,232,65,71,225,93,66,234,81,236,65,98,153,153,97,66,19,174,241,65,51,51,101,66,29,133,245,65,225,122,104,66,132,235,247,
    65,98,205,204,107,66,112,61,250,65,30,133,111,66,163,112,251,65,92,143,115,66,163,112,251,65,98,61,10,116,66,163,112,251,65,20,174,116,66,40,92,251,65,225,122,117,66,50,51,251,65,98,41,92,118,66,60,10,251,65,41,92,119,66,204,204,250,65,30,133,120,66,
    224,122,250,65,108,50,51,123,66,224,122,250,65,108,122,148,128,66,142,194,225,65,98,245,40,128,66,152,153,225,65,162,112,127,66,40,92,225,65,90,143,126,66,193,245,224,65,98,213,163,124,66,121,20,224,65,70,225,122,66,224,122,222,65,233,81,121,66,234,81,
    220,65,98,182,30,119,66,173,71,217,65,28,133,117,66,29,133,213,65,90,143,116,66,173,71,209,65,98,213,163,115,66,183,30,205,65,244,40,115,66,112,61,200,65,244,40,115,66,214,163,194,65,108,244,40,115,66,51,51,139,65,98,244,40,115,66,225,122,116,65,80,184,
    112,66,174,71,89,65,70,225,107,66,164,112,69,65,98,90,143,102,66,41,92,47,65,224,122,94,66,246,40,36,65,70,225,83,66,246,40,36,65,98,162,112,78,66,246,40,36,65,172,71,73,66,154,153,37,65,29,133,68,66,236,81,40,65,108,234,81,60,66,185,30,45,65,108,91,
    143,53,66,52,51,111,65,108,234,81,59,66,144,194,101,65,98,142,194,62,66,1,0,96,65,173,71,67,66,195,245,92,65,203,204,72,66,195,245,92,65,98,244,40,78,66,195,245,92,65,8,215,81,66,226,122,96,65,254,255,83,66,11,215,103,65,98,8,215,85,66,113,61,110,65,
    141,194,86,66,21,174,119,65,141,194,86,66,123,20,130,65,98,141,194,86,66,236,81,136,65,151,153,84,66,174,71,141,65,39,92,80,66,195,245,144,65,98,244,40,78,66,205,204,146,65,70,225,73,66,41,92,149,65,49,51,67,66,205,204,152,65,98,90,143,57,66,164,112,
    157,65,18,174,50,66,113,61,162,65,213,163,46,66,195,245,166,65,98,111,61,40,66,93,143,174,65,182,30,37,66,72,225,184,65,182,30,37,66,82,184,198,65,98,182,30,37,66,20,174,215,65,202,204,39,66,225,122,228,65,39,92,45,66,144,194,237,65,98,172,71,50,66,246,
    40,246,65,203,204,56,66,103,102,250,65,80,184,64,66,103,102,250,65,108,141,194,74,66,103,102,250,65,108,80,184,80,66,31,133,225,65,98,234,81,77,66,133,235,225,65,60,10,74,66,164,112,223,65,172,71,71,66,103,102,218,65,98,213,163,68,66,154,153,213,65,172,
    71,67,66,134,235,207,65,172,71,67,66,31,133,201,65,98,172,71,67,66,226,122,196,65,131,235,67,66,144,194,191,65,182,30,69,66,21,174,187,65,98,39,92,70,66,31,133,183,65,110,61,72,66,113,61,180,65,80,184,74,66,0,0,178,65,108,41,92,86,66,61,10,167,65,99,
    109,41,92,83,66,225,122,176,65,108,184,30,76,66,41,92,183,65,98,245,40,74,66,184,30,185,65,204,204,72,66,31,133,187,65,10,215,71,66,215,163,190,65,98,71,225,70,66,10,215,193,65,102,102,70,66,164,112,197,65,102,102,70,66,164,112,201,65,98,102,102,70,66,
    246,40,206,65,102,102,71,66,113,61,210,65,102,102,73,66,133,235,213,65,98,225,122,75,66,20,174,217,65,20,174,77,66,31,133,219,65,112,61,80,66,31,133,219,65,98,235,81,81,66,31,133,219,65,51,51,82,66,51,51,219,65,71,225,82,66,92,143,218,65,108,153,153,
    84,66,72,225,216,65,98,143,194,83,66,41,92,211,65,235,81,83,66,215,163,206,65,235,81,83,66,215,163,202,65,108,235,81,83,66,225,122,176,65,99,109,215,35,147,66,113,61,2,66,98,123,20,145,66,113,61,2,66,154,25,143,66,72,225,1,66,143,66,141,66,246,40,1,66,
    98,41,92,139,66,164,112,0,66,82,184,137,66,113,61,254,65,102,102,136,66,103,102,250,65,98,153,25,135,66,83,184,246,65,122,20,134,66,205,204,242,65,10,87,133,66,205,204,238,65,98,92,15,132,66,144,194,231,65,133,107,131,66,133,235,223,65,133,107,131,66,
    164,112,215,65,108,133,107,131,66,72,225,114,65,108,30,133,123,66,72,225,114,65,108,30,133,123,66,144,194,53,65,108,10,215,124,66,185,30,53,65,98,205,76,128,66,52,51,51,65,133,235,129,66,11,215,47,65,113,61,131,66,72,225,42,65,98,93,143,132,66,133,235,
    37,65,164,240,133,66,103,102,30,65,41,92,135,66,226,122,20,65,98,61,138,138,66,94,143,250,64,41,92,140,66,176,71,193,64,113,189,140,66,208,204,124,64,108,205,204,140,66,102,102,102,64,108,154,153,148,66,102,102,102,64,108,154,153,148,66,62,10,35,65,108,
    82,184,158,66,62,10,35,65,108,82,184,158,66,134,235,137,65,108,72,97,157,66,165,112,131,65,98,11,215,156,66,206,204,128,65,174,71,156,66,156,153,125,65,82,184,155,66,74,225,122,65,98,184,30,155,66,2,0,120,65,184,158,154,66,135,235,117,65,51,51,154,66,
    217,163,116,65,98,10,215,153,66,33,133,115,65,71,97,153,66,63,10,115,65,10,215,152,66,63,10,115,65,108,154,153,148,66,63,10,115,65,108,154,153,148,66,144,194,199,65,98,154,153,148,66,164,112,203,65,72,225,148,66,216,163,206,65,226,122,149,66,154,153,
    209,65,98,154,25,150,66,82,184,212,65,113,189,150,66,62,10,215,65,72,97,151,66,103,102,216,65,98,31,5,152,66,144,194,217,65,174,199,152,66,205,204,218,65,246,168,153,66,175,71,219,65,98,215,163,154,66,134,235,219,65,133,107,155,66,103,102,220,65,31,5,
    156,66,206,204,220,65,108,215,35,159,66,63,10,223,65,108,72,97,154,66,246,40,1,66,108,62,138,151,66,10,215,1,66,98,123,20,151,66,194,245,1,66,31,133,150,66,61,10,2,66,72,225,149,66,246,40,2,66,98,82,56,149,66,51,51,2,66,205,76,148,66,113,61,2,66,215,
    35,147,66,113,61,2,66,99,109,31,133,126,66,72,225,102,65,108,133,235,132,66,72,225,102,65,108,133,235,132,66,154,153,215,65,98,133,235,132,66,205,204,222,65,225,122,133,66,164,112,229,65,92,143,134,66,41,92,235,65,98,51,51,135,66,205,204,238,65,184,30,
    136,66,113,61,242,65,174,71,137,66,154,153,245,65,98,133,107,138,66,72,225,248,65,41,220,139,66,52,51,251,65,61,138,141,66,226,122,252,65,98,174,71,143,66,11,215,253,65,20,46,145,66,226,122,254,65,215,35,147,66,226,122,254,65,98,143,66,148,66,226,122,
    254,65,184,30,149,66,103,102,254,65,143,194,149,66,246,40,254,65,98,102,102,150,66,0,0,254,65,133,235,150,66,144,194,253,65,41,92,151,66,154,153,253,65,108,133,107,153,66,215,163,252,65,108,235,209,156,66,164,112,227,65,108,143,194,155,66,82,184,226,
    65,98,20,46,155,66,236,81,226,65,102,102,154,66,10,215,225,65,163,112,153,66,174,71,225,65,98,102,102,152,66,215,163,224,65,194,117,151,66,164,112,223,65,245,168,150,66,20,174,221,65,98,40,220,149,66,133,235,219,65,91,15,149,66,184,30,217,65,235,81,148,
    66,40,92,213,65,98,30,133,147,66,40,92,209,65,184,30,147,66,204,204,204,65,184,30,147,66,142,194,199,65,108,184,30,147,66,72,225,102,65,108,41,220,152,66,72,225,102,65,98,154,153,153,66,72,225,102,65,113,61,154,66,21,174,103,65,143,194,154,66,174,71,
    105,65,98,143,66,155,66,72,225,106,65,10,215,155,66,174,71,109,65,30,133,156,66,225,122,112,65,98,143,194,156,66,153,153,113,65,255,255,156,66,61,10,115,65,112,61,157,66,225,122,116,65,108,112,61,157,66,61,10,47,65,108,184,30,147,66,61,10,47,65,108,184,
    30,147,66,51,51,139,64,108,20,46,142,66,51,51,139,64,98,215,163,141,66,20,174,207,64,20,174,139,66,174,71,5,65,71,97,136,66,164,112,29,65,98,10,215,134,66,246,40,40,65,10,87,133,66,236,81,48,65,102,230,131,66,144,194,53,65,98,153,153,130,66,93,143,58,
    65,92,15,129,66,124,20,62,65,153,153,126,66,236,81,64,65,108,153,153,126,66,72,225,102,65,99,109,164,112,159,66,154,153,255,65,108,123,20,159,66,134,235,249,65,98,236,81,160,66,175,71,247,65,82,56,161,66,154,153,243,65,205,204,161,66,206,204,238,65,98,
    185,30,162,66,226,122,236,65,236,81,162,66,1,0,234,65,103,102,162,66,165,112,231,65,98,1,128,162,66,93,143,228,65,62,138,162,66,32,133,225,65,62,138,162,66,237,81,222,65,108,11,87,162,66,187,30,93,65,98,11,87,162,66,13,215,87,65,144,66,162,66,156,153,
    81,65,154,25,162,66,95,143,74,65,98,103,230,161,66,136,235,65,65,52,179,161,66,85,184,62,65,154,153,161,66,156,153,61,65,98,123,148,161,66,156,153,61,65,134,107,161,66,2,0,60,65,93,143,160,66,115,61,50,65,98,83,56,160,66,95,143,46,65,103,230,159,66,2,
    0,44,65,124,148,159,66,105,102,42,65,108,11,87,157,66,44,92,31,65,108,11,87,174,66,44,92,31,65,98,247,168,174,66,44,92,31,65,236,81,175,66,85,184,30,65,124,148,176,66,249,40,28,65,108,63,138,179,66,85,184,14,65,108,63,138,179,66,167,112,57,65,98,135,
    235,179,66,177,71,53,65,12,87,180,66,147,194,49,65,145,194,180,66,95,143,46,65,98,206,204,181,66,75,225,38,65,22,46,183,66,218,163,32,65,12,215,184,66,249,40,28,65,98,135,107,186,66,13,215,23,65,248,168,188,66,44,92,23,65,32,133,190,66,167,112,25,65,
    98,175,71,191,66,116,61,26,65,206,204,191,66,54,51,27,65,216,35,192,66,249,40,28,65,108,216,163,192,66,157,153,29,65,108,93,143,192,66,94,143,130,65,108,226,122,191,66,104,102,128,65,98,144,194,190,66,136,235,125,65,62,10,190,66,13,215,123,65,11,87,189,
    66,75,225,122,65,98,185,158,188,66,147,194,121,65,206,204,187,66,177,71,121,65,134,235,186,66,177,71,121,65,98,185,30,185,66,177,71,121,65,103,102,183,66,126,20,126,65,206,204,181,66,145,194,131,65,98,175,71,180,66,237,81,136,65,1,128,179,66,63,10,141,
    65,32,133,179,66,135,235,145,65,108,83,184,179,66,22,174,231,65,98,206,204,179,66,237,81,234,65,32,5,180,66,63,10,237,65,11,87,180,66,165,112,239,65,98,21,174,180,66,134,235,241,65,62,10,181,66,11,215,243,65,134,107,181,66,185,30,245,65,98,62,138,181,
    66,154,153,245,65,11,215,181,66,216,163,246,65,42,220,182,66,42,92,249,65,108,42,220,184,66,83,184,254,65,108,164,112,159,66,154,153,255,65,99,109,143,194,161,66,41,92,43,65,98,204,76,162,66,164,112,49,65,184,158,162,66,195,245,52,65,112,189,162,66,133,
    235,53,65,98,214,35,163,66,113,61,58,65,71,97,163,66,10,215,63,65,122,148,163,66,225,122,72,65,98,142,194,163,66,245,40,80,65,40,220,163,66,51,51,87,65,40,220,163,66,184,30,93,65,108,91,15,164,66,236,81,222,65,98,91,15,164,66,144,194,225,65,255,255,163,
    66,185,30,229,65,101,230,163,66,113,61,232,65,98,173,199,163,66,154,153,235,65,60,138,163,66,82,184,238,65,244,40,163,66,154,153,241,65,98,203,204,162,66,93,143,244,65,8,87,162,66,52,51,247,65,142,194,161,66,31,133,249,65,108,142,66,180,66,205,204,248,
    65,98,9,215,179,66,185,30,247,65,132,107,179,66,72,225,244,65,60,10,179,66,246,40,242,65,98,183,158,178,66,185,30,239,65,40,92,178,66,154,153,235,65,111,61,178,66,133,235,231,65,108,111,61,178,66,174,71,223,65,108,60,10,178,66,133,235,145,65,98,60,10,
    178,66,194,245,138,65,255,255,178,66,92,143,132,65,162,240,180,66,143,194,125,65,98,203,204,182,66,82,184,114,65,234,209,184,66,184,30,109,65,193,245,186,66,184,30,109,65,98,162,240,187,66,184,30,109,65,39,220,188,66,143,194,109,65,244,168,189,66,61,
    10,111,65,98,213,35,190,66,10,215,111,65,183,158,190,66,194,245,112,65,183,30,191,66,102,102,114,65,108,19,46,191,66,92,143,38,65,98,224,250,190,66,112,61,38,65,50,179,190,66,133,235,37,65,9,87,190,66,164,112,37,65,98,50,179,188,66,21,174,35,65,50,179,
    186,66,0,0,36,65,9,87,185,66,31,133,39,65,98,70,225,183,66,31,133,43,65,19,174,182,66,195,245,48,65,204,204,181,66,31,133,55,65,98,132,235,180,66,123,20,62,65,214,35,180,66,62,10,71,65,255,127,179,66,123,20,82,65,108,91,15,178,66,31,133,79,65,108,91,
    15,178,66,41,92,35,65,108,122,20,177,66,31,133,39,65,98,71,225,175,66,123,20,42,65,255,255,174,66,41,92,43,65,40,92,174,66,41,92,43,65,108,143,194,161,66,41,92,43,65,99,109,236,81,221,66,72,225,254,65,108,42,92,196,66,92,143,254,65,108,32,5,196,66,72,
    225,248,65,98,83,56,197,66,103,102,246,65,186,30,198,66,205,204,242,65,114,189,198,66,0,0,238,65,98,94,15,199,66,20,174,235,65,83,56,199,66,31,133,233,65,175,71,199,66,41,92,231,65,98,42,92,199,66,195,245,228,65,73,97,199,66,154,153,225,65,73,97,199,
    66,174,71,221,65,108,73,97,199,66,10,215,87,65,98,73,97,199,66,153,153,85,65,237,81,199,66,184,30,81,65,1,0,199,66,194,245,72,65,98,52,179,198,66,194,245,64,65,165,112,198,66,163,112,61,65,175,71,198,66,10,215,59,65,108,11,87,197,66,102,102,50,65,98,
    62,10,197,66,30,133,47,65,21,174,196,66,204,204,44,65,113,61,196,66,102,102,42,65,108,236,81,194,66,30,133,31,65,108,226,122,211,66,30,133,31,65,98,236,209,211,66,30,133,31,65,154,25,212,66,40,92,31,65,206,76,212,66,61,10,31,65,98,63,138,212,66,81,184,
    30,65,226,250,212,66,163,112,29,65,247,168,213,66,20,174,27,65,98,206,76,214,66,133,235,25,65,11,215,214,66,20,174,23,65,175,71,215,66,174,71,21,65,108,195,117,216,66,82,184,14,65,108,62,138,216,66,92,143,222,65,98,62,138,216,66,215,163,226,65,123,148,
    216,66,143,194,229,65,216,163,216,66,10,215,231,65,98,52,179,216,66,143,194,233,65,134,235,216,66,0,0,236,65,144,66,217,66,225,122,238,65,98,185,158,217,66,184,30,241,65,226,250,217,66,174,71,243,65,236,81,218,66,205,204,244,65,98,246,168,218,66,236,
    81,246,65,123,20,219,66,133,235,247,65,185,158,219,66,21,174,249,65,108,236,81,221,66,72,225,254,65,99,109,246,168,198,66,92,143,248,65,108,205,76,217,66,205,204,248,65,98,174,71,217,66,82,184,248,65,174,71,217,66,82,184,248,65,144,66,217,66,215,163,
    248,65,98,42,220,216,66,205,204,246,65,134,107,216,66,235,81,244,65,1,0,216,66,174,71,241,65,98,93,143,215,66,123,20,238,65,175,71,215,66,184,30,235,65,52,51,215,66,225,122,232,65,98,185,30,215,66,123,20,230,65,124,20,215,66,205,204,226,65,124,20,215,
    66,102,102,222,65,108,1,0,215,66,244,40,36,65,98,114,189,214,66,183,30,37,65,196,117,214,66,131,235,37,65,21,46,214,66,80,184,38,65,98,103,102,213,66,203,204,40,65,103,230,212,66,121,20,42,65,185,158,212,66,90,143,42,65,98,11,87,212,66,59,10,43,65,195,
    245,211,66,49,51,43,65,31,133,211,66,49,51,43,65,108,154,153,198,66,49,51,43,65,108,0,128,199,66,244,40,52,65,98,41,220,199,66,19,174,55,65,20,46,200,66,172,71,61,65,195,117,200,66,172,71,69,65,98,144,194,200,66,192,245,76,65,103,230,200,66,59,10,83,
    65,103,230,200,66,18,174,87,65,108,103,230,200,66,50,51,221,65,98,103,230,200,66,142,194,225,65,42,220,200,66,173,71,229,65,175,199,200,66,132,235,231,65,98,52,179,200,66,204,204,234,65,195,117,200,66,142,194,237,65,93,15,200,66,81,184,240,65,98,51,179,
    199,66,20,174,243,65,82,56,199,66,236,81,246,65,246,168,198,66,92,143,248,65,99,109,154,25,207,66,164,112,29,65,98,123,148,204,66,164,112,29,65,134,107,202,66,113,61,22,65,246,168,200,66,246,40,8,65,98,72,225,198,66,246,40,244,64,0,0,198,66,174,71,209,
    64,0,0,198,66,195,245,168,64,98,0,0,198,66,0,0,128,64,225,250,198,66,103,102,54,64,133,235,200,66,206,204,236,63,98,41,220,202,66,156,153,89,63,0,0,205,66,56,51,179,62,143,66,207,66,56,51,179,62,98,235,209,209,66,56,51,179,62,61,10,212,66,207,204,76,
    63,10,215,213,66,63,10,215,63,98,246,168,215,66,226,122,36,64,123,148,216,66,154,153,105,64,123,148,216,66,185,30,157,64,98,123,148,216,66,21,174,199,64,246,168,215,66,206,204,236,64,236,209,213,66,134,235,5,65,98,225,250,211,66,154,153,21,65,82,184,
    209,66,164,112,29,65,154,25,207,66,164,112,29,65,99,109,143,66,207,66,205,204,140,63,98,71,97,205,66,205,204,140,63,245,168,203,66,92,143,194,63,225,250,201,66,236,81,24,64,98,205,76,200,66,42,92,79,64,0,128,199,66,123,20,134,64,0,128,199,66,174,71,169,
    64,98,0,128,199,66,31,133,203,64,82,56,200,66,20,174,231,64,82,184,201,66,20,174,255,64,98,82,56,203,66,10,215,11,65,225,250,204,66,153,153,17,65,154,25,207,66,153,153,17,65,98,236,81,209,66,153,153,17,65,246,40,211,66,51,51,11,65,113,189,212,66,9,215,
    251,64,98,236,81,214,66,193,245,224,64,123,20,215,66,112,61,194,64,123,20,215,66,162,112,157,64,98,123,20,215,66,58,10,119,64,10,87,214,66,78,184,62,64,205,204,212,66,78,184,14,64,98,113,61,211,66,246,40,188,63,164,112,209,66,205,204,140,63,143,66,207,
    66,205,204,140,63,99,109,0,128,224,66,72,225,254,65,108,20,174,240,66,42,92,167,65,108,112,61,229,66,64,10,63,65,98,92,15,229,66,218,163,60,65,10,215,228,66,95,143,58,65,122,148,228,66,218,163,56,65,98,112,61,228,66,105,102,54,65,9,215,227,66,3,0,52,
    65,71,97,227,66,177,71,49,65,108,20,46,224,66,54,51,31,65,108,184,158,247,66,54,51,31,65,108,20,174,247,66,218,163,36,65,98,174,199,247,66,208,204,44,65,40,220,247,66,126,20,50,65,133,235,247,66,228,122,52,65,98,0,0,248,66,54,51,55,65,20,46,248,66,248,
    40,60,65,0,128,248,66,23,174,67,65,98,205,204,248,66,74,225,74,65,10,87,249,66,33,133,83,65,154,25,250,66,166,112,93,65,98,164,112,250,66,125,20,98,65,164,240,250,66,12,215,103,65,185,158,251,66,84,184,110,65,108,124,148,252,66,12,215,119,65,108,165,
    112,255,66,196,245,84,65,98,206,204,255,66,206,204,80,65,226,250,255,66,94,143,74,65,226,250,255,66,114,61,66,65,98,226,250,255,66,73,225,62,65,134,235,255,66,63,10,59,65,175,199,255,66,63,10,55,65,98,21,174,255,66,2,0,52,65,1,128,255,66,155,153,49,65,
    83,56,255,66,247,40,48,65,108,63,138,252,66,52,51,31,65,108,134,235,7,67,52,51,31,65,108,62,10,1,67,236,81,156,65,108,103,102,7,67,185,30,237,65,98,83,120,7,67,124,20,238,65,123,148,7,67,52,51,239,65,113,189,7,67,216,163,240,65,108,62,202,7,67,175,71,
    241,65,98,93,207,7,67,165,112,241,65,52,243,7,67,103,102,242,65,134,43,8,67,134,235,243,65,98,21,110,8,67,144,194,245,65,1,192,8,67,32,133,247,65,73,33,9,67,52,51,249,65,108,186,94,10,67,206,204,254,65,108,178,199,252,66,206,204,254,65,108,188,30,250,
    66,52,51,233,65,98,116,61,249,66,247,40,226,65,168,112,248,66,113,61,220,65,178,199,247,66,32,133,215,65,108,86,184,245,66,1,0,202,65,108,240,81,241,66,155,153,227,65,98,189,30,241,66,206,204,228,65,35,5,241,66,216,163,230,65,35,5,241,66,63,10,233,65,
    98,35,5,241,66,237,81,236,65,117,61,241,66,43,92,239,65,25,174,241,66,237,81,242,65,98,189,30,242,66,176,71,245,65,127,148,242,66,176,71,247,65,66,10,243,66,247,40,248,65,108,86,184,242,66,11,215,253,65,108,0,128,224,66,72,225,254,65,99,109,51,179,253,
    66,205,204,248,65,108,82,184,7,67,205,204,248,65,98,51,179,7,67,215,163,248,65,21,174,7,67,92,143,248,65,246,168,7,67,103,102,248,65,98,205,76,7,67,134,235,245,65,164,48,7,67,195,245,244,65,215,35,7,67,103,102,244,65,98,195,245,6,67,83,184,242,65,123,
    212,6,67,42,92,241,65,0,192,6,67,236,81,240,65,108,72,33,0,67,246,40,156,65,108,195,117,6,67,41,92,43,65,108,41,92,0,67,41,92,43,65,98,225,122,0,67,143,194,45,65,92,143,0,67,205,204,48,65,184,158,0,67,246,40,52,65,98,51,179,0,67,174,71,57,65,112,189,
    0,67,133,235,61,65,112,189,0,67,103,102,66,65,98,112,189,0,67,185,30,77,65,40,156,0,67,154,153,85,65,10,87,0,67,11,215,91,65,108,112,189,252,66,0,0,134,65,108,194,117,250,66,102,102,118,65,98,112,189,249,66,71,225,110,65,20,46,249,66,215,163,104,65,235,
    209,248,66,10,215,99,65,98,255,255,247,66,184,30,89,65,133,107,247,66,10,215,79,65,122,20,247,66,20,174,71,65,98,112,189,246,66,20,174,63,65,61,138,246,66,112,61,58,65,194,117,246,66,40,92,55,65,98,102,102,246,66,183,30,53,65,10,87,246,66,173,71,49,65,
    143,66,246,66,30,133,43,65,108,71,225,228,66,30,133,43,65,98,184,30,229,66,194,245,44,65,10,87,229,66,102,102,46,65,61,138,229,66,10,215,47,65,98,163,240,229,66,92,143,50,65,143,66,230,66,143,194,53,65,30,133,230,66,184,30,57,65,108,255,127,242,66,143,
    194,167,65,108,30,133,227,66,72,225,248,65,108,205,204,240,66,0,0,248,65,98,246,168,240,66,51,51,247,65,31,133,240,66,102,102,246,65,72,97,240,66,164,112,245,65,98,205,204,239,66,154,153,241,65,0,128,239,66,164,112,237,65,0,128,239,66,62,10,233,65,98,
    0,128,239,66,31,133,229,65,20,174,239,66,93,143,226,65,92,15,240,66,236,81,224,65,108,174,199,245,66,195,245,190,65,108,92,15,249,66,226,122,212,65,98,143,194,249,66,175,71,217,65,92,143,250,66,42,92,223,65,194,117,251,66,93,143,230,65,108,51,179,253,
    66,205,204,248,65,99,109,92,79,21,67,143,194,185,65,108,112,61,5,67,143,194,185,65,108,194,181,7,67,153,153,125,65,108,235,81,23,67,153,153,125,65,108,92,79,21,67,143,194,185,65,99,109,174,71,6,67,143,194,179,65,108,113,189,20,67,143,194,179,65,108,11,
    87,22,67,82,184,132,65,108,1,64,8,67,82,184,132,65,108,174,71,6,67,143,194,179,65,99,109,215,163,37,67,41,92,2,66,98,61,138,33,67,41,92,2,66,123,84,30,67,10,215,249,65,41,28,28,67,225,122,228,65,98,92,15,26,67,215,163,208,65,31,5,25,67,0,0,182,65,31,
    5,25,67,164,112,149,65,98,31,5,25,67,184,30,101,65,11,215,26,67,205,204,36,65,164,112,30,67,42,92,215,64,98,103,38,34,67,135,235,65,64,225,186,38,67,184,71,97,63,92,15,44,67,0,82,184,62,108,82,184,47,67,0,0,0,0,108,154,153,45,67,51,51,147,64,108,62,74,
    43,67,30,133,171,64,98,62,10,42,67,20,174,183,64,93,207,40,67,204,204,204,64,42,156,39,67,153,153,233,64,98,52,243,37,67,204,204,8,65,42,156,36,67,184,30,33,65,73,161,35,67,184,30,61,65,98,247,104,34,67,0,0,96,65,175,199,33,67,246,40,132,65,175,199,33,
    67,225,122,154,65,98,175,199,33,67,225,122,178,65,165,48,34,67,122,20,196,65,114,253,34,67,215,163,206,65,98,186,158,35,67,72,225,214,65,114,125,36,67,205,204,218,65,216,163,37,67,205,204,218,65,98,83,184,38,67,205,204,218,65,62,138,39,67,195,245,214,
    65,216,35,40,67,62,10,207,65,98,32,197,40,67,82,184,198,65,11,23,41,67,52,51,187,65,11,23,41,67,72,225,172,65,98,11,23,41,67,103,102,158,65,195,181,40,67,205,204,146,65,83,248,39,67,226,122,138,65,98,1,64,39,67,236,81,130,65,237,81,38,67,206,204,124,
    65,247,40,37,67,206,204,124,65,108,216,163,36,67,206,204,124,65,98,216,163,36,67,206,204,124,65,206,140,36,67,196,245,124,65,52,51,36,67,73,225,126,65,108,195,53,34,67,246,40,132,65,108,11,87,38,67,216,163,48,65,108,11,23,40,67,216,163,48,65,98,175,7,
    43,67,216,163,48,65,21,110,45,67,226,122,64,65,226,58,47,67,22,174,95,65,98,134,235,48,67,176,71,125,65,175,199,49,67,42,92,145,65,175,199,49,67,154,153,167,65,98,175,199,49,67,62,10,195,65,155,153,48,67,144,194,217,65,32,69,46,67,195,245,234,65,98,164,
    240,43,67,0,0,252,65,61,10,41,67,41,92,2,66,215,163,37,67,41,92,2,66,99,109,113,125,46,67,174,71,97,63,108,215,35,44,67,123,20,142,63,98,225,250,38,67,41,92,207,63,92,143,34,67,246,40,108,64,82,248,30,67,215,163,232,64,98,31,133,27,67,62,10,43,65,31,
    197,25,67,226,122,104,65,31,197,25,67,31,133,149,65,98,31,197,25,67,82,184,180,65,0,192,26,67,0,0,206,65,164,176,28,67,82,184,224,65,98,144,194,30,67,215,163,244,65,31,197,33,67,205,204,254,65,215,163,37,67,205,204,254,65,98,10,215,40,67,205,204,254,
    65,235,145,43,67,215,163,246,65,0,192,45,67,226,122,230,65,98,133,235,47,67,103,102,214,65,31,5,49,67,52,51,193,65,31,5,49,67,32,133,167,65,98,31,5,49,67,206,204,146,65,226,58,48,67,165,112,129,65,133,171,46,67,34,133,103,65,98,31,5,45,67,75,225,74,65,
    205,204,42,67,239,81,60,65,123,20,40,67,239,81,60,65,108,195,181,38,67,239,81,60,65,108,134,43,36,67,126,20,114,65,98,21,110,36,67,208,204,112,65,62,138,36,67,228,122,112,65,73,161,36,67,228,122,112,65,108,104,38,37,67,228,122,112,65,98,94,143,38,67,
    228,122,112,65,196,181,39,67,115,61,122,65,124,148,40,67,73,225,134,65,98,247,104,41,67,114,61,144,65,11,215,41,67,63,10,157,65,11,215,41,67,206,204,172,65,98,11,215,41,67,237,81,188,65,226,122,41,67,73,225,200,65,175,199,40,67,124,20,210,65,98,62,10,
    40,67,144,194,219,65,226,250,38,67,83,184,224,65,216,163,37,67,83,184,224,65,98,83,56,36,67,83,184,224,65,42,28,35,67,22,174,219,65,155,89,34,67,22,174,209,65,98,196,117,33,67,2,0,198,65,175,7,33,67,135,235,179,65,175,7,33,67,104,102,154,65,98,175,7,
    33,67,63,10,131,65,21,174,33,67,14,215,91,65,83,248,34,67,54,51,55,65,98,144,2,36,67,146,194,25,65,134,107,37,67,248,40,0,65,247,40,39,67,108,102,214,64,98,22,110,40,67,26,174,183,64,114,189,41,67,159,153,161,64,93,15,43,67,231,122,148,64,108,206,12,
    45,67,52,92,127,64,108,113,125,46,67,174,71,97,63,99,109,61,74,72,67,82,184,1,66,98,30,133,67,67,82,184,1,66,51,115,63,67,236,81,248,65,20,46,60,67,102,102,226,65,98,184,158,56,67,92,143,202,65,235,209,54,67,102,102,170,65,235,209,54,67,214,163,130,65,
    98,235,209,54,67,192,245,60,65,235,145,56,67,36,92,255,64,174,7,60,67,118,20,158,64,98,82,120,63,67,206,122,244,63,235,145,67,67,16,143,194,62,51,51,72,67,16,143,194,62,98,153,25,75,67,16,143,194,62,174,135,77,67,13,51,51,63,51,115,79,67,94,61,170,63,
    108,194,181,79,67,207,122,180,63,108,194,181,79,67,90,143,10,65,108,102,102,77,67,57,10,231,64,98,51,243,76,67,180,30,221,64,143,66,76,67,26,133,211,64,10,87,75,67,88,143,202,64,98,82,56,74,67,57,10,191,64,225,58,73,67,170,71,185,64,246,104,72,67,170,
    71,185,64,108,21,238,71,67,170,71,185,64,98,144,2,69,67,150,153,193,64,72,225,66,67,252,255,231,64,185,158,65,67,141,194,21,65,98,165,176,64,67,100,102,46,65,226,58,64,67,38,92,79,65,226,58,64,67,18,174,119,65,98,226,58,64,67,30,133,149,65,103,230,64,
    67,173,71,171,65,195,53,66,67,91,143,188,65,98,41,156,67,67,204,204,206,65,72,97,69,67,19,174,215,65,72,161,71,67,19,174,215,65,108,133,235,73,67,19,174,215,65,108,133,235,73,67,234,81,154,65,98,133,235,73,67,80,184,150,65,184,222,73,67,142,194,147,65,
    143,194,73,67,29,133,145,65,98,225,186,73,67,70,225,144,65,41,156,73,67,183,30,143,65,245,104,73,67,111,61,140,65,98,184,30,73,67,9,215,135,65,194,181,72,67,111,61,132,65,50,51,72,67,172,71,129,65,108,111,61,71,67,16,174,119,65,108,234,145,82,67,16,174,
    119,65,108,234,145,82,67,28,133,247,65,108,121,84,82,67,110,61,248,65,98,193,181,81,67,120,20,250,65,234,81,80,67,100,102,252,65,8,23,78,67,49,51,255,65,98,72,225,75,67,0,0,1,66,20,238,73,67,82,184,1,66,61,74,72,67,82,184,1,66,99,109,51,51,72,67,215,
    163,144,63,98,143,194,67,67,215,163,144,63,123,212,63,67,102,102,38,64,174,135,60,67,236,81,176,64,98,113,61,57,67,103,102,6,65,235,145,55,67,216,163,64,65,235,145,55,67,215,163,130,65,98,235,145,55,67,225,122,168,65,174,71,57,67,184,30,199,65,245,168,
    60,67,144,194,221,65,98,61,202,63,67,82,184,242,65,50,179,67,67,42,92,253,65,173,71,72,67,42,92,253,65,98,71,225,73,67,42,92,253,65,60,202,75,67,1,0,252,65,50,243,77,67,175,71,249,65,98,9,215,79,67,73,225,246,65,70,33,81,67,73,225,244,65,204,204,81,67,
    175,71,243,65,108,204,204,81,67,10,215,129,65,108,214,99,73,67,10,215,129,65,98,101,166,73,67,123,20,132,65,183,222,73,67,215,163,134,65,204,12,74,67,41,92,137,65,98,153,89,74,67,21,174,141,65,132,107,74,67,72,225,142,65,163,112,74,67,164,112,143,65,
    98,122,148,74,67,236,81,146,65,214,163,74,67,10,215,149,65,214,163,74,67,113,61,154,65,108,214,163,74,67,144,194,219,65,108,81,248,73,67,154,153,221,65,108,153,153,71,67,154,153,221,65,98,153,25,69,67,154,153,221,65,92,15,67,67,31,133,211,65,61,138,65,
    67,154,153,191,65,98,102,38,64,67,41,92,173,65,51,115,63,67,92,143,150,65,51,115,63,67,32,133,119,65,98,51,115,63,67,196,245,76,65,51,243,63,67,134,235,41,65,51,243,64,67,42,92,15,65,98,10,87,66,67,248,40,212,64,133,171,68,67,135,235,169,64,184,222,71,
    67,196,245,160,64,108,215,99,72,67,196,245,160,64,98,61,74,73,67,196,245,160,64,154,89,74,67,63,10,167,64,61,138,75,67,32,133,179,64,98,61,138,76,67,165,112,189,64,174,71,77,67,22,174,199,64,61,202,77,67,73,225,210,64,108,163,240,78,67,134,235,233,64,
    108,163,240,78,67,72,225,250,63,98,246,40,77,67,225,122,180,63,215,227,74,67,215,163,144,63,51,51,72,67,215,163,144,63,99,101,0,0 };

    Path logoData;
    logoData.loadPathFromData(pathData, sizeof(pathData));

    g.setColour(Color::offWhite);
    g.fillPath(logoData);
}