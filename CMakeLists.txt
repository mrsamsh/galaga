cmake_minimum_required(VERSION 3.20)

project(GALAGA_GL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_Mixer REQUIRED)
find_package(SDL2_TTF REQUIRED)

add_executable(galaga
	src/Bullet.cpp
	src/CFG.cpp
	src/Core.cpp
	src/Elements.cpp
	src/Formations.cpp
	src/Game.cpp
	src/LevelsElement.cpp
	src/Music.cpp
	src/Objects.cpp
	src/Patterns.cpp
	src/Resources.cpp
	src/Rocket.cpp
	src/Ship.cpp
	src/StageM.cpp
	src/Text.cpp
	src/glad.c
	src/main.cpp
	src/physix.cpp
	src/shapes.cpp
	src/stages.cpp
	src/starsField.cpp
	src/texture.cpp
	src/timer.cpp
)

target_link_libraries(galaga
	${SDL2_LIBRARIES}
	${SDL2_IMAGE_LIBRARY}
	${SDL2_MIXER_LIBRARY}
	${SDL2_TTF_LIBRARY}
)

target_include_directories(galaga
	PRIVATE ${CMAKE_SOURCE_DIR}/include
	PRIVATE ${SDL2_INCLUDE_DIRS}
	PRIVATE ${SDL2_IMAGE_INCLUDE_DIR}
	PRIVATE ${SDL2_MIXER_INCLUDE_DIR}
	PRIVATE ${SDL2_TTF_INCLUDE_DIR}
)

set (source "${CMAKE_SOURCE_DIR}/resources")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/resources")

add_custom_command(
	TARGET galaga POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
	DEPENDS ${destination}
	COMMENT "symbolic link resources folder from ${source} => ${destination}"
)
