cmake_minimum_required(VERSION 3.29)
project(NHFSave C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall")

add_executable(NHFSave main.c
        Ingridient.h
        Ingridient.c
        Recipe.c
        Recipe.h
        input.c
        input.h
        RecipeIngridient.c
        RecipeIngridient.h
        Menu.c
        Menu.h)
