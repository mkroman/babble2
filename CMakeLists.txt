project(babble)
cmake_minimum_required(VERSION 2.6)

set(BABBLE_SOURCES
	sources/Babble.cpp
	sources/Engine.cpp
	sources/BaseObject.cpp
	sources/Application.cpp
)

find_package(SDL)

include_directories(headers ${SDL_INCLUDE_DIR})
add_executable(babble ${BABBLE_SOURCES})
target_link_libraries(babble ${SDL_LIBRARY})
