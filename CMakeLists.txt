cmake_minimum_required(VERSION 2.6)

project(MyProject)


file(
        GLOB_RECURSE

	source

	QT/src/*
	QT/includes/*

        Main/src/*
        Main/includes/*
)

add_executable(snake

        ${source}

)
