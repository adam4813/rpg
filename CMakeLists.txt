cmake_minimum_required(VERSION 3.13)
project(rpg)

cmake_policy(SET CMP0079 NEW) # target_link_libraries modify out of scope
cmake_policy(SET CMP0076 NEW) # target_sources use relative file names

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMMON_LIB_NAME "rpg-common")
add_library(${COMMON_LIB_NAME} STATIC)
add_subdirectory(common)

option(BUILD_RPG_CLIENT "Build the game client" ON)
if (BUILD_RPG_CLIENT)
	set(CLIENT_NAME "rpg-client")
	add_executable(${CLIENT_NAME})
	add_subdirectory(client)
endif ()

option(BUILD_RPG_SERVER "Build the game server" OFF)
if (BUILD_RPG_SERVER)
	set(SERVER_NAME "rpg-server")
	add_executable(${SERVER_NAME})
	add_subdirectory(server)
endif ()