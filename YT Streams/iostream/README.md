# YTStreams\iostream

## Info

This is for the stream series about writing `iostream` from scratch

## Build/Run info

### Windows 10/11 x64

#### Configuring/Building/Running

1. run `GenerateProjects.bat` (no admin required) and it will use premake5 to generate files for Visual Studio 2022
2. Open the generated .sln file with Visual Studio 2022 and edit/build/run from there

#### Cleaning

Full clean (destroys all output files and files that `GenerateProjects.bat` creates or any linux build files) can be done by running `Clean.bat` (no admin)

Smaller clean (destroys just output files) can be done through Visual Studio 2022

### Linux x64

#### Configuring/Building/Running

1. run `GenerateProjects.sh` (no admin required) and it will use premake5 to generate files for GNU make
2. build with `Build.sh`, can except either 'debug' for debug mode or 'release' for release mode as command line args
3. run with `Run.sh`, can except either 'debug' for debug mode or 'release' for release mode as command line args
4. Open the generated .sln file with Visual Studio 2022 and edit/build/run from there

#### Cleaning

Full clean (destroys all output files and files that `GenerateProjects.sh` creates or any Windows 10/11 build files) can be done by running `Clean.sh` (no admin)

Smaller clean (destroys just output files) has to be done manually
