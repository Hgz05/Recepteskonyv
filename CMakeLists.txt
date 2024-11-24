cmake_minimum_required(VERSION 3.29)
project(NHFSave C)

set(CMAKE_C_STANDARD 11)

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
