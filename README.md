# CPP-Game-Engine
This project aim to build a Game Engine using C++. This is a learning project.

## Install dependencies (Debian)
- #### SDL2 and build dependencies
```
sudo apt install build-essential gdb libglu1-mesa-dev freeglut3-dev mesa-common-dev libglew-dev libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
```
- #### VSCode extensions
> **[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)**  
> **[C/C++ Makefile Project](https://marketplace.visualstudio.com/items?itemName=adriano-markovic.c-cpp-makefile-project)**  
> **[Code Runner *(optionnal)*](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)**

- #### VSCode Setup
1. If running on WSL, create ".vscode/**c_cpp_properties.json**" and add your SDL dependencies configuration here.  
This should look similar to the following:
```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/SDL2"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "gnu17",
            "cppStandard": "gnu++14",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```
2. Create a ***launch.json*** profile using the VSCode Run and Debug tool. Open the file and click on ***Add Configuration...*** then select **C/C++: (gdb) Launch**. Match the `program` line to your compiled out file *(look for it in the makefile)*.
```json
"program": "${workspaceFolder}/launch",
```
You should now be able to debug your program.