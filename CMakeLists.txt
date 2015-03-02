cmake_minimum_required(VERSION 2.6)

project(MyProject)


file(
        GLOB_RECURSE

	source

        Main/src/*
        Main/includes/*
)

add_executable(snake

        ${source}

)
