cmake_minimum_required(VERSION 3.13)
project(rpg)

set(CMAKE_CXX_STANDARD 17)
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

if (MSVC_IDE)
	set_property(TARGET ${CLIENT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "../assets")
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CLIENT_NAME})
endif ()

option(BUILD_RPG_SERVER "Build the game server" OFF)
if (BUILD_RPG_SERVER)
	set(SERVER_NAME "rpg-server")
	add_executable(${SERVER_NAME})
	add_subdirectory(server)
endif ()
