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

void AssignIngridients(Recipe *Rec, RecipeIngridient *RecIngridient);

void AddRecipeTo(Recipe *list, Recipe *ToAdd);

void AddOrCreateRecipe(Recipe **list, Recipe *ToAdd);

void DeleteRecipe(Recipe **listPtr, Recipe *ToDelete);

Recipe *FindRecipeByName(Recipe *list, char *RecipeName);

void RecipePrint(Recipe *PRecipe);

void FindRecipeByIngs(Recipe *list);

void PrintFavRecipes(Recipe* list);

void SetFavorite(Recipe *list, char *SetFavName, bool isFav);

void PrintAllRecipes(Recipe *list);

void AddRecipeFromIO(Ingridient *IngList, Recipe *RecList);

bool AddRecipeFromIOIsFav(char* IsFav);

void DeleteAllRecipe(Recipe* list);

//void PrintIngName(Ingridient *list, int IngridientIndex);

#endif //RECIPE_H
