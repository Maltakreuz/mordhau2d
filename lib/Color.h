#pragma once
#include <SDL2/SDL.h>

// Base
SDL_Color CLR_WHITE       = {255, 255, 255, 255};
SDL_Color CLR_BLACK       = {0,   0,   0,   255};
SDL_Color CLR_RED         = {255, 0,   0,   255};
SDL_Color CLR_LIME        = {0,   255, 0,   255};
SDL_Color CLR_BLUE        = {0,   0,   255, 255};

// Gray
SDL_Color CLR_GRAY        = {128, 128, 128, 255};
SDL_Color CLR_SILVER      = {192, 192, 192, 255};

// Reds / Pinks
SDL_Color CLR_MAROON      = {128, 0,   0,   255};
SDL_Color CLR_DARK_RED    = {139, 0,   0,   255};
SDL_Color CLR_FIREBRICK   = {178, 34,  34,  255};
SDL_Color CLR_PINK        = {255, 192, 203, 255};
SDL_Color CLR_HOT_PINK    = {255, 105, 180, 255};
SDL_Color CLR_DEEP_PINK   = {255, 20,  147, 255};

// Oranges / Yellows
SDL_Color CLR_ORANGE      = {255, 165, 0,   255};
SDL_Color CLR_DARK_ORANGE = {255, 140, 0,   255};
SDL_Color CLR_GOLD        = {255, 215, 0,   255};
SDL_Color CLR_YELLOW      = {255, 255, 0,   255};
SDL_Color CLR_KHAKI       = {240, 230, 140, 255};

// Greens
SDL_Color CLR_GREEN       = {0,   128, 0,   255}; // CSS green
SDL_Color CLR_DARK_GREEN  = {0,   100, 0,   255};
SDL_Color CLR_OLIVE       = {128, 128, 0,   255};
SDL_Color CLR_OLIVE_DRAB  = {107, 142, 35,  255};
SDL_Color CLR_LAWN_GREEN  = {124, 252, 0,   255};
SDL_Color CLR_SPRING_GREEN= {0,   255, 127, 255};

// Cyans / Blues
SDL_Color CLR_CYAN        = {0,   255, 255, 255};
SDL_Color CLR_AQUA        = {0,   255, 255, 255};
SDL_Color CLR_TEAL        = {0,   128, 128, 255};
SDL_Color CLR_TURQUOISE   = {64,  224, 208, 255};
SDL_Color CLR_DEEP_SKY_BLUE={0,  191, 255, 255};
SDL_Color CLR_DODGER_BLUE = {30,  144, 255, 255};
SDL_Color CLR_ROYAL_BLUE  = {65,  105, 225, 255};
SDL_Color CLR_NAVY        = {0,   0,   128, 255};
SDL_Color CLR_MIDNIGHT_BLUE={25, 25, 112, 255};

// Purples
SDL_Color CLR_PURPLE      = {128, 0,   128, 255};
SDL_Color CLR_INDIGO      = {75,  0,   130, 255};
SDL_Color CLR_VIOLET      = {238, 130, 238, 255};
SDL_Color CLR_DARK_VIOLET = {148, 0,   211, 255};
SDL_Color CLR_MAGENTA     = {255, 0,   255, 255};
SDL_Color CLR_FUCHSIA     = {255, 0,   255, 255};

// Browns
SDL_Color CLR_BROWN       = {165, 42,  42,  255};
SDL_Color CLR_SADDLE_BROWN= {139, 69,  19,  255};

// Special
SDL_Color CLR_TRANSPARENT = {0,   0,   0,   0};


// ===== WHITES =====
SDL_Color CLR_SNOW            = {255, 250, 250, 255};
SDL_Color CLR_IVORY           = {255, 255, 240, 255};
SDL_Color CLR_CREAM           = {255, 253, 208, 255};
SDL_Color CLR_EGGSHELL        = {240, 234, 214, 255};
SDL_Color CLR_BONE            = {227, 218, 201, 255};

// ===== BLACKS =====
SDL_Color CLR_CHARCOAL        = {54,  69,  79,  255};
SDL_Color CLR_JET             = {52,  52,  52,  255};
SDL_Color CLR_INK             = {16,  18,  20,  255};
SDL_Color CLR_RICH_BLACK      = {10,  10,  14,  255};

// ===== GRAYS =====
SDL_Color CLR_WARM_GRAY       = {139, 131, 120, 255};
SDL_Color CLR_COOL_GRAY       = {140, 146, 172, 255};
SDL_Color CLR_MID_GRAY        = {128, 128, 128, 255};
SDL_Color CLR_LIGHT_GRAY      = {200, 200, 200, 255};
SDL_Color CLR_DARK_GRAY       = {64,  64,  64,  255};

// ===== REDS =====
SDL_Color CLR_CADMIUM_RED     = {227, 0,   34,  255};
SDL_Color CLR_SCARLET         = {255, 36,  0,   255};
SDL_Color CLR_VERMILION       = {227, 66,  52,  255};
SDL_Color CLR_CRIMSON         = {220, 20,  60,  255};
SDL_Color CLR_ALIZARIN        = {82,  10,  24,  255};
SDL_Color CLR_WINE            = {114, 47,  55,  255};
SDL_Color CLR_OXBLOOD         = {74,  0,   0,   255};

// ===== ORANGES =====
SDL_Color CLR_CADMIUM_ORANGE  = {237, 135, 45,  255};
SDL_Color CLR_BURNT_ORANGE    = {204, 85,  0,   255};
SDL_Color CLR_PUMPKIN         = {255, 117, 24,  255};
SDL_Color CLR_APRICOT         = {251, 206, 177, 255};
SDL_Color CLR_TERRA_COTTA     = {226, 114, 91,  255};
SDL_Color CLR_RUST            = {183, 65,  14,  255};

// ===== YELLOWS =====
SDL_Color CLR_CADMIUM_YELLOW  = {255, 246, 0,   255};
SDL_Color CLR_NAPLES_YELLOW   = {250, 218, 94,  255};
SDL_Color CLR_GOLD_OCHRE      = {199, 153, 0,   255};
SDL_Color CLR_LEMON_YELLOW    = {255, 244, 79,  255};
SDL_Color CLR_STRAW           = {228, 217, 111, 255};

// ===== GREENS =====
SDL_Color CLR_SAP_GREEN       = {80,  125, 42,  255};
SDL_Color CLR_OLIVE_GREEN     = {107, 142, 35,  255};
SDL_Color CLR_FOREST_GREEN    = {34,  139, 34,  255};
SDL_Color CLR_EMERALD_GREEN   = {80,  200, 120, 255};
SDL_Color CLR_MINT            = {152, 255, 152, 255};
SDL_Color CLR_MOSS            = {138, 154, 91,  255};

// ===== BLUES =====
SDL_Color CLR_ULTRAMARINE     = {18,  10,  143, 255};
SDL_Color CLR_COBALT_BLUE     = {0,   71,  171, 255};
SDL_Color CLR_CERULEAN        = {42,  82,  190, 255};
SDL_Color CLR_PRUSSIAN_BLUE   = {0,   49,  83,  255};
SDL_Color CLR_NAVY_BLUE       = {0,   0,   128, 255};
SDL_Color CLR_SKY_BLUE        = {135, 206, 235, 255};
SDL_Color CLR_ICE_BLUE        = {210, 240, 255, 255};

// ===== PURPLES =====
SDL_Color CLR_DIOXAZINE       = {74,  20,  140, 255};
SDL_Color CLR_IMPERIAL_PURPLE= {102, 2,   60,  255};
SDL_Color CLR_AMETHYST       = {153, 102, 204, 255};
SDL_Color CLR_LAVENDER       = {230, 230, 250, 255};
SDL_Color CLR_MAUVE          = {224, 176, 255, 255};

// ===== BROWNS =====
SDL_Color CLR_RAW_UMBER       = {115, 74,  18,  255};
SDL_Color CLR_BURNT_UMBER     = {138, 51,  36,  255};
SDL_Color CLR_SIENNA          = {160, 82,  45,  255};
SDL_Color CLR_CHOCOLATE       = {210, 105, 30,  255};
SDL_Color CLR_TAN             = {210, 180, 140, 255};

// ===== SKIN TONES =====
SDL_Color CLR_FAIR_SKIN       = {255, 224, 189, 255};
SDL_Color CLR_LIGHT_SKIN      = {241, 194, 125, 255};
SDL_Color CLR_MEDIUM_SKIN     = {224, 172, 105, 255};
SDL_Color CLR_OLIVE_SKIN      = {198, 134, 66,  255};
SDL_Color CLR_DARK_SKIN       = {141, 85,  36,  255};

// ===== SPECIAL =====
SDL_Color CLR_COPPER          = {184, 115, 51,  255};
SDL_Color CLR_BRONZE          = {205, 127, 50,  255};
