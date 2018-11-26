find_package(glfw3 CONFIG REQUIRED)
find_package(openal CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)

target_sources(${CLIENT_NAME} PRIVATE
	main.cpp
	game.cpp
	os/os-window.hpp
	os/os-window.cpp
	os/os-events.hpp
	os/os-event-dispatcher.hpp
	os/os-event-dispatcher.cpp
)

target_link_libraries(${CLIENT_NAME} PRIVATE ${COMMON_LIB_NAME} GLEW::GLEW glfw OpenAL::OpenAL)