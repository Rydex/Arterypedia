cmake_minimum_required(VERSION 3.10)
project(arterypedia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(
	${PROJECT_NAME}
	src/main.cpp
	src/menu.cpp
	src/branches/cca.cpp
	src/branches/eca.cpp
)

add_library(mylib
	src/menu.cpp
	src/menu.h
	src/branches/cca.cpp
	src/branches/eca.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ncursesw)