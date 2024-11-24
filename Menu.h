//
// Created by hejag on 24/11/2024.
//

#ifndef MENU_H
#define MENU_H
#include "Recipe.h"
#include "debugmalloc.h"


void LogoPrinter();

int MainMenu(Ingridient** IngListPtr, Recipe** RecipeList);

void SearchMenu(Ingridient** IngList, Recipe** RecipeList);

void RecipeMenu(Ingridient** IngList, Recipe** RecipeList);

void IngManageMenu(Ingridient** IngList, Recipe** RecipeList);

void FavMenu(Recipe** RecipeList);

void RandomRecipe(Recipe* RecipeList);




#endif //MENU_H
