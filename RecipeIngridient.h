//
// Created by hejag on 24/11/2024.
//

#ifndef RECIPEINGRIDIENT_H
#define RECIPEINGRIDIENT_H
#include "Ingridient.h"

typedef struct RecipeIngridient {
    int IngAmount;
    Ingridient* IngData;
    struct RecipeIngridient* NextNode;

}RecipeIngridient;

RecipeIngridient* CreateRecipeIngridient(int IngAmount, Ingridient* IngData);
void AddRITo(RecipeIngridient* list, RecipeIngridient* ToAdd);
void DeleteRI(RecipeIngridient* list, RecipeIngridient* ToDelete);
RecipeIngridient* FindRecipeIngridientByName(RecipeIngridient* list, char* IngName);
void DeleteAllRecIng(RecipeIngridient* list);
//void PrintIngName(Ingridient *list, int IngridientIndex);

#endif //RECIPEINGRIDIENT_H
