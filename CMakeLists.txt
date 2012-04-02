project(babble)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Debug)

set(BABBLE_SOURCES
	sources/Timer.cpp
	sources/Babble.cpp
	sources/Engine.cpp
	sources/Object.cpp
	sources/Actor.cpp
	sources/Application.cpp
	sources/EventHandler.cpp
)

find_package(SDL)
find_package(SDL_image)

include_directories(headers ${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR})
add_executable(babble ${BABBLE_SOURCES})
target_link_libraries(babble ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})
