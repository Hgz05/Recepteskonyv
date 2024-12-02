//
// Created by hejag on 24/11/2024.
//

#ifndef MENU_H
#define MENU_H
#include "Recipe.h"
#include "debugmalloc.h"

/**
 * Prints out the logo.
 */
void LogoPrinter();

/**
 * This is the main menu function this from this function the user can access the other menus.
 * @param IngListPtr The address of the first element of the Ingridient linked list.
 * @param RecipeList The address of the first element of the Recipe linked list.
 * @return If the user exits the program with the exit option the return will be 0.
 */
int MainMenu(Ingridient** IngListPtr, Recipe** RecipeList);

/**
 * The Recipe search menu.
 * @param IngList The address of the first element of the Ingridient linked list.
 * @param RecipeList The address of the first element of the Recipe linked list.
 */
void SearchMenu(Ingridient** IngList, Recipe** RecipeList);

/**
 * Recipe menu for modifying recipes.
 * @param IngList The address of the first element of the Ingridient linked list.
 * @param RecipeList The address of the first element of the Recipe linked list.
 */
void RecipeMenu(Ingridient** IngList, Recipe** RecipeList);

/**
 *Ingridient menu for modifying ingridients.
 * @param IngList The address of the first element of the Ingridient linked list.
 * @param RecipeList The address of the first element of the Recipe linked list.
 */
void IngManageMenu(Ingridient** IngList, Recipe** RecipeList);

/**
 * The menu for modifying the favorite parameter of the recipe stuct.
 * @param RecipeList The address of the first element of the Recipe linked list.
 */
void FavMenu(Recipe** RecipeList);

/**
 * This function will print out a random recipe.
 * @param RecipeList The address of the first element of the Recipe linked list.
 */
void RandomRecipe(Recipe* RecipeList);




#endif //MENU_H
