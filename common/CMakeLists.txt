find_package(glm CONFIG REQUIRED)
find_package(bullet REQUIRED)

target_sources(${COMMON_LIB_NAME} PRIVATE
	simulation.hpp
	simulation.cpp
)

target_link_libraries(${COMMON_LIB_NAME} PRIVATE glm ${BULLET_LIBRARIES})

target_include_directories(${COMMON_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)