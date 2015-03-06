cmake_minimum_required(VERSION 2.8)

project(nibbler)

file(

        GLOB_RECURSE

		source

		Qt/src/*
		Qt/includes/*
        main/src/*
        main/includes/*
)

add_executable(nibbler ${source})
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${SDL2_LIBRARYDIR})

target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${SDL2_INCLUDEDIR})
