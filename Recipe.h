//
// Created by hejag on 23/11/2024.

#ifndef RECIPE_H
#define RECIPE_H
#include <stdbool.h>
#include "RecipeIngridient.h"
#include "Ingridient.h"

/**
 * The struct that stores recipe values.
 */
typedef struct Recipe {
    char RecName[100];
    struct Recipe *NextNode;
    RecipeIngridient *RecIng;
    bool bIsFavorite;
} Recipe;

/**
 * This function creates a new recipe.
 * @param Name The name of the recipe to create.
 * @param bIsFav Whether to mark this recipe or not.
 * @return Newly created recipe.
 */
Recipe *CreateRecipe(char *Name, bool bIsFav);

/**
 *Assigns the RecipeIngridient linked list to and elemnet of Recipe linkec list.
 * @param Rec An element of the Recipe linked list.
 * @param RecIngridient The first element of the RecinpeIngridient lined list.
 */
void AssignIngridients(Recipe *Rec, RecipeIngridient *RecIngridient);

/**
 * Adds a Recipe to the Recipe linked list.
 * @param list The address of the first element of the recipe linked list.
 * @param ToAdd The address of the Recipe that will be added to the list.
 */
void AddRecipeTo(Recipe *list, Recipe *ToAdd);

/**
 * This function is not used in the program.
 * @param list
 * @param ToAdd
 */
void AddOrCreateRecipe(Recipe **list, Recipe *ToAdd);

/**
 * Deletes an element of the Recipe linked list specified by the ToDelete pointer.
 * @param listPtr The address of the first element of the recipe linked list.
 * @param ToDelete The address of the element of the recipe linked list that will be deleted.
 */
void DeleteRecipe(Recipe **listPtr, Recipe *ToDelete);

/**
 * Finds a recipe by name
 * @param list The address of the first element of the recipe linked list.
 * @param RecipeName The name of the recipe.
 * @return Address of the Recipe specified by name.
 */
Recipe *FindRecipeByName(Recipe *list, char *RecipeName);

/**
 * Prints the recipe of the specified address.
 * @param PRecipe The recipe address.
 */
void RecipePrint(Recipe *PRecipe);

/**
 *
 * @param list
 */
void FindRecipeByIngs(Recipe *list);

/**
 * Prints the favorite recipes
 * @param list The address of the first element of the recipe linked list.
 */
void PrintFavRecipes(Recipe *list);

/**
 * Sets an element of the Recipe linked list to favorite or not favorite.
 * @param list The address of the first element of the recipe linked list.
 * @param SetFavName The name of the SelectFavorite Recipe.
 * @param isFav Favorite or not.
 */
void SetFavorite(Recipe *list, char *SetFavName, bool isFav);

/**
 * Prints all recipes.
 * @param list The address of the first element of the recipe linked list.
 */
void PrintAllRecipes(Recipe *list);

/**
 *This will add a new recipe to the Recipe linked list. This function gets input from the user.
 * @param IngList The address of the first element of the recipe linked list.
 * @param RecList The address of the first element of the ingridient linked list.
 */
void AddRecipeFromIO(Ingridient *IngList, Recipe *RecList);

/**
 * Gets a string and determines that is it a true or false value when converted to a boolean.
 * @param IsFav The string.
 * @return The boolean value.
 */
bool AddRecipeFromIOIsFav(char *IsFav);

/**
 * Deletes all Recipe from the Recipe linked list.
 * @param list The address of the first element of the recipe linked list.
 */
void DeleteAllRecipe(Recipe *list);

/**
 * Gets the lenght of the recipe linked list.
 * @param list The address of the first element of the recipe linked list.
 * @return an intiger value that is the lenght of the list.
 */
int RecipeListLen(Recipe *list);

//void PrintIngName(Ingridient *list, int IngridientIndex);

#endif //RECIPE_H
