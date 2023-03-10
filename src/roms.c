#include <common.h>
#include <roms.h>

typedef struct {
    char filename[1024];
    uint32_t rom_size;
    uint8_t *rom_data;
} rom_context;

const char *ROM_FILES[] = {
    "GB_GREEN_JP.gb", "GB_BLUE_JP.gb",   "GB_BLUE_FR.gb",   "GB_RED_JP.gb",
    "GB_RED_FR.gb",   "GB_YELLOW_JP.gb", "GB_YELLOW_FR.gb",
};
const char *ROMS_DIR_PATH = NULL;

void roms_init_dir_path() {
    char *base_path = SDL_GetBasePath();
    if (base_path == NULL)
        exit_with_error("Unable to locate program root directory");

    int len = SDL_strlen(base_path) + SDL_strlen("roms") + 2;
    ROMS_DIR_PATH = (char *)SDL_malloc(len);
    if (ROMS_DIR_PATH == NULL)
        exit_with_error("Unable to locate \"roms\" directory");

    SDL_snprintf((char *)ROMS_DIR_PATH, len, "%sroms", base_path);
    SDL_free(base_path);

    SDL_Log("Located roms directory: %s", ROMS_DIR_PATH);
}

void roms_init_dir_content() {
    DIR *dir = opendir(ROMS_DIR_PATH);

    int list_size = (sizeof(ROM_FILES) / sizeof(ROM_FILES[0]));
    if (dir == NULL || list_size == 0)
        exit_with_error("Unable to locate any rom file");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_REG) {
            continue;
        }
        for (int i = 0; i < list_size; i++) {
            if (strcmp(entry->d_name, ROM_FILES[i]) == 0) {
                SDL_Log("Found ROM %s", entry->d_name);
                break;
            }
        }
    }
    closedir(dir);
}