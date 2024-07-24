# ***Template Project for SFSE - CommonLibSF***

## ***Runtime requirements***

- [Starfield Script Extender (SFSE)](https://sfse.silverlock.org/)
- [Address Library for SFSE Plugins](https://www.nexusmods.com/starfield/mods/3256)

## ***Build requirements***

- [CMake](https://cmake.org/)
- [vcpkg](https://vcpkg.io/en/)
- [Visual Studio Community 2022](https://visualstudio.microsoft.com/vs/community/)
- [CommonLibSF](https://github.com/Starfield-Reverse-Engineering/CommonLibSF)

## ***Building***

In `Developer Command Prompt for VS 2022` or `Developer PowerShell for VS 2022`, run:

~~~
git clone https://github.com/epinter/sfse-clib-template.git
cd sfse-clib-template
~~~

then

~~~
.\cmake\build.ps1
~~~

or

~~~
.\cmake\build.ps1 -buildPreset ALL-relwithdebinfo
~~~

or

~~~
.\cmake\build.ps1 -buildPreset ALL-debug
~~~

or

~~~
cmake -B build -S . --preset ALL --fresh
cmake --build build --preset ALL-release
~~~

Then get the .dll in build/Release, or the .zip (ready to install using mod manager) in build.