#include <common.h>
#include <gb_emu.h>

typedef struct {
    char filename[1024];
    uint32_t rom_size;
    uint8_t *rom_data;
} rom_context;

const char *GB_ROM_FILES[] = {
    "GB_GREEN_JP.gb", "GB_BLUE_JP.gb",   "GB_BLUE_FR.gb",   "GB_RED_JP.gb",
    "GB_RED_FR.gb",   "GB_YELLOW_JP.gb", "GB_YELLOW_FR.gb",
};

const int GB_ROM_SIZE = sizeof(GB_ROM_FILES) / sizeof(GB_ROM_FILES[0]);

void delay(uint32_t ms) { SDL_Delay(ms); }

int start() {
    printf("Not implemented\n");
    return 0;
}