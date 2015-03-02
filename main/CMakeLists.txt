cmake_minimum_required(VERSION 2.6)

#Déclaration du projet

project(MyProject)



file(

        GLOB_RECURSE

	source

        src/*
        includes/*

)

add_executable(

        snake

        ${source}

)
