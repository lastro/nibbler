cmake_minimum_required(VERSION 2.6)

project(MyProject)


cmake_minimum_required(VERSION 2.8)

project(testas)

file(

        GLOB_RECURSE

		source

		Qt/src/*
		Qt/includes/*
        main/src/main.cpp
        main/includes/*
)

add_executable(testas ${source})
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
