# GB Emulator
This project aims to create a GameBoy emulator

## External documentation
- https://gbdev.io/pandocs/

## Project setup
### Install dependencies
- #### Ubuntu
```
sudo apt install libsdl2-dev libsdl2-ttf-dev check build-essential cmake
```
- #### Manjaro
```
pamac install sdl2 sdl2_ttf cmake check
```

--- 

### VSCode config
- Create ".vscode/**c_cpp_properties.json**" and add your SDL dependencies configuration here.  
This should look similar to the following:
> ```json
> {
>     "configurations": [
>         {
>             "name": "Linux",
>             "includePath": [
>                 "${workspaceFolder}/**",
>                 "/usr/include/SDL2"
>             ],
>             "defines": [],
>             "compilerPath": "/usr/bin/gcc",
>             "cStandard": "gnu17",
>             "cppStandard": "gnu++14",
>             "intelliSenseMode": "linux-gcc-x64"
>         }
>     ],
>     "version": 4
> }
> ```
- Create a ***tasks.json*** file and paste the following:
> ```json
> {
>     "version": "2.0.0",
>     "tasks": [
>         {
>             "label": "build",
>             "type": "shell",
>             "command": "make",
>             "group": {
>                 "kind": "build",
>                 "isDefault": true
>             },
>             "problemMatcher": "$gcc",
>             "options": {
>                 "cwd": "${workspaceFolder}"
>             }
>         }
>     ]
> }
> ```
> It will build the program using the **makefile** a the root of the project.  

- Create a ***launch.json*** profile using the VSCode Run and Debug tool. Open the file and click on ***Add Configuration...*** then select **C/C++: (gdb) Launch**. Match the `program` line to your compiled out file *(look for it in the makefile)*.
> ```json
> "program": "${workspaceFolder}/launch",
> ```
> You should now be able to debug your program.
#### VSCode extensions
> **[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)**  
> **[C/C++ Makefile Project](https://marketplace.visualstudio.com/items?itemName=adriano-markovic.c-cpp-makefile-project)**  
> **[Code Runner *(optionnal)*](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)**
