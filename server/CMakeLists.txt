target_sources(${SERVER_NAME} PRIVATE
	main.cpp
)

target_link_libraries(${SERVER_NAME} PRIVATE ${COMMON_LIB_NAME})