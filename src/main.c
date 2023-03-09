#include <common.h>
#include <gb_emu.h>

extern const char *GB_ROM_FILES[];

const char *ROMS_PATH = NULL;

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Initialize dir paths
    char *base_path = SDL_GetBasePath();
    if (base_path == NULL) {
        SDL_Log("Unable to get base path: %s", SDL_GetError());
        SDL_Quit();
    }
    int len = SDL_strlen(base_path) + SDL_strlen("roms") + 2;
    ROMS_PATH = (char *)SDL_malloc(len);
    if (ROMS_PATH == NULL) {
        SDL_Log("Unable to allocate memory: %s", SDL_GetError());
        SDL_free(base_path);
        SDL_Quit();
    }
    SDL_snprintf((char *)ROMS_PATH, len, "%s/roms", base_path);
    SDL_free(base_path);

    // Analyze ROMs
    DIR *dir = opendir(ROMS_PATH);
    if (dir == NULL || GB_ROM_SIZE == 0) {
        SDL_Log("No ROM found: %s", SDL_GetError());
        SDL_Quit();
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_REG) {
            continue;
        }
        for (int i = 0; i < GB_ROM_SIZE; i++) {
            if (strcmp(entry->d_name, GB_ROM_FILES[i]) == 0) {
                SDL_Log("Found ROM %s", entry->d_name);
                break;
            }
        }
    }
    closedir(dir);

    // start();
    return 0;
}
