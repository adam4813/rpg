find_package(Threads)
find_package(glm CONFIG REQUIRED)
find_package(Angelscript CONFIG REQUIRED)
find_package(bullet REQUIRED)

target_sources(${COMMON_LIB_NAME} PRIVATE
	simulation.hpp
	simulation.cpp
	events/event-dispatcher.hpp
	events/event-listener.hpp
	events/event-queue.hpp
	script/script-system.hpp
	script/script-system.cpp
	script/angelscript-addons-source.cpp
	util/worker-thread.hpp
)

target_link_libraries(${COMMON_LIB_NAME} PRIVATE glm ${BULLET_LIBRARIES} Angelscript::angelscript)

target_include_directories(${COMMON_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)