cmake_minimum_required(VERSION 3.10)
project(arterypedia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(
	${PROJECT_NAME}
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ncursesw)