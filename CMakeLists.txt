cmake_minimum_required(VERSION 2.8)

project(nibbler)

add_definitions( "-Wall -Werror -Wextra" )
set(Qt_USE_STATIC_LIBS OFF)
set(OpenGL_USE_STATIC_LIBS OFF)


find_package(
		
		OpenGL REQUIRED
)

find_package(

        Qt4 REQUIRED
)

file(

        GLOB_RECURSE

		sources

		Qt/src/*
        main/src/*
)

file(

        GLOB_RECURSE

		headers

		Qt/includes/*
        main/includes/*
)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
QT4_WRAP_CPP(Qt_HEADERS_MOC ${headers})

add_executable(

		nibbler

		${sources}
		${headers}
		${Qt_HEADERS_MOC}
)


include_directories(
		${OPENGL_INCLUDE_DIRS}
		${GLUT_INCLUDE_DIRS}
		${SDL2_LIBRARYDIR}
)

target_link_libraries(
		nibbler
		${OPENGL_LIBRARIES}
		${GLUT_LIBRARY}
		${SDL2_INCLUDEDIR}
)
