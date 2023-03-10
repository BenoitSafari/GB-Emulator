#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void delay(uint32_t ms) { SDL_Delay(ms); }
static inline void exit_with_error(const char *msg) {
    SDL_Log("Exiting on error: %s", msg);
    exit(1);
}