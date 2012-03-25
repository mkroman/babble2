project(babble)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Debug)

set(BABBLE_SOURCES
	sources/Babble.cpp
	sources/Engine.cpp
	sources/BaseObject.cpp
	sources/Application.cpp
	sources/VisualObject.cpp
	sources/PlayerObject.cpp
)

find_package(SDL)
find_package(SDL_image)

include_directories(headers ${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR})
add_executable(babble ${BABBLE_SOURCES})
target_link_libraries(babble ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})
