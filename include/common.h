#pragma once

#include <SDL2/SDL.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const char *ROMS_PATH;
extern const char *GB_ROM_FILES[];
extern const int GB_ROM_SIZE;

enum gb_roms {
    GB_GREEN_JP,
    GB_BLUE_JP,
    GB_BLUE_FR,
    GB_RED_JP,
    GB_RED_FR,
    GB_YELLOW_JP,
    GB_YELLOW_FR,
};
