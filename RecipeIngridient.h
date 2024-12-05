//
// Created by hejag on 24/11/2024.

#ifndef RECIPEINGRIDIENT_H
#define RECIPEINGRIDIENT_H
#include "Ingridient.h"
#include "debugmalloc.h"
/**
 * A wrapper struct that connects the Ingridient stuct and the Recipe struct and it stores ingridient amount. The IngData points to the selected Ingridient. The NextNode is used to point to the next element of the RecipeIngridinent linked list.
 */
typedef struct RecipeIngridient {
 /**
  * The amount of the selected ingridient.
  */
 int IngAmount;
 /**
  * The pointer of the selected ingridient.
  */
 Ingridient *IngData;
 /**
  * The pointer to then next RecipeIngridient in the chained list.
  */
 struct RecipeIngridient *NextNode;
} RecipeIngridient;

/**
 * Creates a RecipeIngrident struct.
 * @param IngAmount The amount of the ingridient specified in the ing data.
 * @param IngData Points to the selected Ingridient in the Ingridient linked list.
 * @return Pointer RecipeIngridient struct.
 */
RecipeIngridient *CreateRecipeIngridient(int IngAmount, Ingridient *IngData);

/**
 * Adds a RecipeIngridient struct to the RecipeIngridient linked list.
 * @param list The address of the first element of the RecipeIngridient linked list.
 * @param ToAdd The Pointer of theRecipeIngridient that is added to the RecipeIngridient linked list.
 */
void AddRITo(RecipeIngridient *list, RecipeIngridient *ToAdd);

/**
 * Deletes a RecipeIngridient from the RecipeIngridient linked list.
 * @param list The address of the first element of the RecipeIngridient linked list.
 * @param ToDelete The address of the RecipeIngridient that will be deleted.
 */
void DeleteRI(RecipeIngridient *list, RecipeIngridient *ToDelete);

/**
 * Finds a RecipeIngridient by Name.
 * @param list The address of the first element of the RecipeIngridient linked list.
 * @param IngName The name of the searched Ingridient.
 * @return A RecipeIngridient pointer.
 */
RecipeIngridient *FindRecipeIngridientByName(RecipeIngridient *list, char *IngName);

/**
 * Deletes all RecipeIngdients from the RecipeIngridient linked list.
 * @param list The address of the first element of the RecipeIngridient linked list.
 */
void DeleteAllRecIng(RecipeIngridient *list);


#endif //RECIPEINGRIDIENT_H
