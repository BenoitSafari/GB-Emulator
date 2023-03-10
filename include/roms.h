#pragma once

#include <dirent.h>

extern const char *ROMS_DIR_PATH;
extern const char *ROM_FILES[];

void roms_init_dir_path();
void roms_init_dir_content();