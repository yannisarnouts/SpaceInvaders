# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project.dir/flags.make

CMakeFiles/Project.dir/main.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\main.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\main.cpp"

CMakeFiles/Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\main.cpp" > CMakeFiles\Project.dir\main.cpp.i

CMakeFiles/Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\main.cpp" -o CMakeFiles\Project.dir\main.cpp.s

CMakeFiles/Project.dir/factory/AbstractFactory.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/factory/AbstractFactory.cpp.obj: ../factory/AbstractFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project.dir/factory/AbstractFactory.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\factory\AbstractFactory.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\AbstractFactory.cpp"

CMakeFiles/Project.dir/factory/AbstractFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/factory/AbstractFactory.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\AbstractFactory.cpp" > CMakeFiles\Project.dir\factory\AbstractFactory.cpp.i

CMakeFiles/Project.dir/factory/AbstractFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/factory/AbstractFactory.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\AbstractFactory.cpp" -o CMakeFiles\Project.dir\factory\AbstractFactory.cpp.s

CMakeFiles/Project.dir/model/PlayerShip.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/PlayerShip.cpp.obj: ../model/PlayerShip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project.dir/model/PlayerShip.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\PlayerShip.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\PlayerShip.cpp"

CMakeFiles/Project.dir/model/PlayerShip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/PlayerShip.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\PlayerShip.cpp" > CMakeFiles\Project.dir\model\PlayerShip.cpp.i

CMakeFiles/Project.dir/model/PlayerShip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/PlayerShip.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\PlayerShip.cpp" -o CMakeFiles\Project.dir\model\PlayerShip.cpp.s

CMakeFiles/Project.dir/controller/Game.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/controller/Game.cpp.obj: ../controller/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project.dir/controller/Game.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\controller\Game.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\controller\Game.cpp"

CMakeFiles/Project.dir/controller/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/controller/Game.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\controller\Game.cpp" > CMakeFiles\Project.dir\controller\Game.cpp.i

CMakeFiles/Project.dir/controller/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/controller/Game.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\controller\Game.cpp" -o CMakeFiles\Project.dir\controller\Game.cpp.s

CMakeFiles/Project.dir/factory/SDLFactory.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/factory/SDLFactory.cpp.obj: ../factory/SDLFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project.dir/factory/SDLFactory.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\factory\SDLFactory.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\SDLFactory.cpp"

CMakeFiles/Project.dir/factory/SDLFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/factory/SDLFactory.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\SDLFactory.cpp" > CMakeFiles\Project.dir\factory\SDLFactory.cpp.i

CMakeFiles/Project.dir/factory/SDLFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/factory/SDLFactory.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\SDLFactory.cpp" -o CMakeFiles\Project.dir\factory\SDLFactory.cpp.s

CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.obj: ../SDLClasses/SDLPlayerShip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\SDLClasses\SDLPlayerShip.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLPlayerShip.cpp"

CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLPlayerShip.cpp" > CMakeFiles\Project.dir\SDLClasses\SDLPlayerShip.cpp.i

CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLPlayerShip.cpp" -o CMakeFiles\Project.dir\SDLClasses\SDLPlayerShip.cpp.s

CMakeFiles/Project.dir/factory/Texture.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/factory/Texture.cpp.obj: ../factory/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project.dir/factory/Texture.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\factory\Texture.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\Texture.cpp"

CMakeFiles/Project.dir/factory/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/factory/Texture.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\Texture.cpp" > CMakeFiles\Project.dir\factory\Texture.cpp.i

CMakeFiles/Project.dir/factory/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/factory/Texture.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\factory\Texture.cpp" -o CMakeFiles\Project.dir\factory\Texture.cpp.s

CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.obj: ../SDLClasses/SDLBackground.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\SDLClasses\SDLBackground.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLBackground.cpp"

CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLBackground.cpp" > CMakeFiles\Project.dir\SDLClasses\SDLBackground.cpp.i

CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLBackground.cpp" -o CMakeFiles\Project.dir\SDLClasses\SDLBackground.cpp.s

CMakeFiles/Project.dir/model/Background.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/Background.cpp.obj: ../model/Background.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Project.dir/model/Background.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\Background.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Background.cpp"

CMakeFiles/Project.dir/model/Background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/Background.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Background.cpp" > CMakeFiles\Project.dir\model\Background.cpp.i

CMakeFiles/Project.dir/model/Background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/Background.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Background.cpp" -o CMakeFiles\Project.dir\model\Background.cpp.s

CMakeFiles/Project.dir/model/Alien.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/Alien.cpp.obj: ../model/Alien.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Project.dir/model/Alien.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\Alien.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Alien.cpp"

CMakeFiles/Project.dir/model/Alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/Alien.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Alien.cpp" > CMakeFiles\Project.dir\model\Alien.cpp.i

CMakeFiles/Project.dir/model/Alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/Alien.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Alien.cpp" -o CMakeFiles\Project.dir\model\Alien.cpp.s

CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.obj: ../SDLClasses/SDLAlien.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\SDLClasses\SDLAlien.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLAlien.cpp"

CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLAlien.cpp" > CMakeFiles\Project.dir\SDLClasses\SDLAlien.cpp.i

CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLAlien.cpp" -o CMakeFiles\Project.dir\SDLClasses\SDLAlien.cpp.s

CMakeFiles/Project.dir/controller/KeyHandler.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/controller/KeyHandler.cpp.obj: ../controller/KeyHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Project.dir/controller/KeyHandler.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\controller\KeyHandler.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\controller\KeyHandler.cpp"

CMakeFiles/Project.dir/controller/KeyHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/controller/KeyHandler.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\controller\KeyHandler.cpp" > CMakeFiles\Project.dir\controller\KeyHandler.cpp.i

CMakeFiles/Project.dir/controller/KeyHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/controller/KeyHandler.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\controller\KeyHandler.cpp" -o CMakeFiles\Project.dir\controller\KeyHandler.cpp.s

CMakeFiles/Project.dir/model/Bullet.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/Bullet.cpp.obj: ../model/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Project.dir/model/Bullet.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\Bullet.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Bullet.cpp"

CMakeFiles/Project.dir/model/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/Bullet.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Bullet.cpp" > CMakeFiles\Project.dir\model\Bullet.cpp.i

CMakeFiles/Project.dir/model/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/Bullet.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Bullet.cpp" -o CMakeFiles\Project.dir\model\Bullet.cpp.s

CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.obj: ../SDLClasses/SDLBullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\SDLClasses\SDLBullet.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLBullet.cpp"

CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLBullet.cpp" > CMakeFiles\Project.dir\SDLClasses\SDLBullet.cpp.i

CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\SDLClasses\SDLBullet.cpp" -o CMakeFiles\Project.dir\SDLClasses\SDLBullet.cpp.s

CMakeFiles/Project.dir/model/Aliens.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/Aliens.cpp.obj: ../model/Aliens.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Project.dir/model/Aliens.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\Aliens.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Aliens.cpp"

CMakeFiles/Project.dir/model/Aliens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/Aliens.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Aliens.cpp" > CMakeFiles\Project.dir\model\Aliens.cpp.i

CMakeFiles/Project.dir/model/Aliens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/Aliens.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Aliens.cpp" -o CMakeFiles\Project.dir\model\Aliens.cpp.s

CMakeFiles/Project.dir/model/Canon.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/Canon.cpp.obj: ../model/Canon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Project.dir/model/Canon.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\Canon.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Canon.cpp"

CMakeFiles/Project.dir/model/Canon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/Canon.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Canon.cpp" > CMakeFiles\Project.dir\model\Canon.cpp.i

CMakeFiles/Project.dir/model/Canon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/Canon.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Canon.cpp" -o CMakeFiles\Project.dir\model\Canon.cpp.s

CMakeFiles/Project.dir/model/Entity.cpp.obj: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/model/Entity.cpp.obj: ../model/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Project.dir/model/Entity.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project.dir\model\Entity.cpp.obj -c "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Entity.cpp"

CMakeFiles/Project.dir/model/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/model/Entity.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Entity.cpp" > CMakeFiles\Project.dir\model\Entity.cpp.i

CMakeFiles/Project.dir/model/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/model/Entity.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\model\Entity.cpp" -o CMakeFiles\Project.dir\model\Entity.cpp.s

# Object files for target Project
Project_OBJECTS = \
"CMakeFiles/Project.dir/main.cpp.obj" \
"CMakeFiles/Project.dir/factory/AbstractFactory.cpp.obj" \
"CMakeFiles/Project.dir/model/PlayerShip.cpp.obj" \
"CMakeFiles/Project.dir/controller/Game.cpp.obj" \
"CMakeFiles/Project.dir/factory/SDLFactory.cpp.obj" \
"CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.obj" \
"CMakeFiles/Project.dir/factory/Texture.cpp.obj" \
"CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.obj" \
"CMakeFiles/Project.dir/model/Background.cpp.obj" \
"CMakeFiles/Project.dir/model/Alien.cpp.obj" \
"CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.obj" \
"CMakeFiles/Project.dir/controller/KeyHandler.cpp.obj" \
"CMakeFiles/Project.dir/model/Bullet.cpp.obj" \
"CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.obj" \
"CMakeFiles/Project.dir/model/Aliens.cpp.obj" \
"CMakeFiles/Project.dir/model/Canon.cpp.obj" \
"CMakeFiles/Project.dir/model/Entity.cpp.obj"

# External object files for target Project
Project_EXTERNAL_OBJECTS =

Project.exe: CMakeFiles/Project.dir/main.cpp.obj
Project.exe: CMakeFiles/Project.dir/factory/AbstractFactory.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/PlayerShip.cpp.obj
Project.exe: CMakeFiles/Project.dir/controller/Game.cpp.obj
Project.exe: CMakeFiles/Project.dir/factory/SDLFactory.cpp.obj
Project.exe: CMakeFiles/Project.dir/SDLClasses/SDLPlayerShip.cpp.obj
Project.exe: CMakeFiles/Project.dir/factory/Texture.cpp.obj
Project.exe: CMakeFiles/Project.dir/SDLClasses/SDLBackground.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/Background.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/Alien.cpp.obj
Project.exe: CMakeFiles/Project.dir/SDLClasses/SDLAlien.cpp.obj
Project.exe: CMakeFiles/Project.dir/controller/KeyHandler.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/Bullet.cpp.obj
Project.exe: CMakeFiles/Project.dir/SDLClasses/SDLBullet.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/Aliens.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/Canon.cpp.obj
Project.exe: CMakeFiles/Project.dir/model/Entity.cpp.obj
Project.exe: CMakeFiles/Project.dir/build.make
Project.exe: CMakeFiles/Project.dir/linklibs.rsp
Project.exe: CMakeFiles/Project.dir/objects1.rsp
Project.exe: CMakeFiles/Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project.dir/build: Project.exe

.PHONY : CMakeFiles/Project.dir/build

CMakeFiles/Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project.dir/clean

CMakeFiles/Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project" "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project" "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug" "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug" "C:\Users\Gebruiker\Documents\school\semester 2\programmeertechnieken\Project\cmake-build-debug\CMakeFiles\Project.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project.dir/depend

