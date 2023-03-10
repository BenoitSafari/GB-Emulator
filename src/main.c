#include <common.h>
#include <gb_emu.h>
#include <roms.h>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Initialize roms directory path and check content
    roms_init_dir_path();
    roms_init_dir_content();

    return 0;
}
