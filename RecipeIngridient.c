//
// Created by hejag on 24/11/2024.
//

#include "RecipeIngridient.h"
#include "debugmalloc.h"

RecipeIngridient* CreateRecipeIngridient(int IngAmount, Ingridient *IngData) {
    RecipeIngridient *Ing = (RecipeIngridient *) malloc(sizeof(RecipeIngridient));
    Ing->IngAmount = IngAmount;
    Ing->IngData = IngData;
    Ing->NextNode = NULL;
    return Ing;
}

void AddRITo(RecipeIngridient *list, RecipeIngridient *ToAdd) {
    if (list != NULL && ToAdd != NULL) {
        while (list->NextNode != NULL) {
            list = list->NextNode;
        }
        list->NextNode = ToAdd;
    }
}

void DeleteRI(RecipeIngridient *list, RecipeIngridient *ToDelete) {
    if (list != NULL && ToDelete != NULL) {
        while (list->NextNode != ToDelete && list != NULL) {
            list = list->NextNode;
        }
        if (list != NULL) {
            list->NextNode = ToDelete->NextNode;
            free(ToDelete);
        }
    }
}

RecipeIngridient* FindRecipeIngridientByName(RecipeIngridient *list, char* IngName) {
        while (list != NULL) {
            if (strcmp(list->IngData->IngName, IngName) == 0) {
                return list;
            }
            list = list->NextNode;
        }
        return NULL;
}

void DeleteAllRecIng(RecipeIngridient *list) {
    if(list != NULL) {
        while(list != NULL) {
            RecipeIngridient* RecIngToDelete = list;
            list = list->NextNode;
            free(RecIngToDelete);
        }
        if(list != NULL) {
        while(list != NULL) {
            RecipeIngridient* RecIngToDelete = list;
            list = list->NextNode;
            free(RecIngToDelete);
        }
    }
    }
}
