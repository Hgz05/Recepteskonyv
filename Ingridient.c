//
// Created by hejag on 23/11/2024.
//
#include "Ingridient.h"

#include <stdio.h>

#include "Recipe.h"

Ingridient *CreateIngridient(char *Name, MeasurementType Type) {
    Ingridient *Ing = (Ingridient *) malloc(sizeof(Ingridient));
    strcpy(Ing->IngName, Name);
    Ing->MType = Type;
    Ing->NextNode = NULL;
    return Ing;
}

void AddIngridientTo(Ingridient *list, Ingridient *ToAdd) {
    if (list != NULL && ToAdd != NULL) {
        while (list->NextNode != NULL) {
            list = list->NextNode;
        }
        list->NextNode = ToAdd;
    }
}

void AddOrCreateIng(Ingridient **list, Ingridient *ToAdd) {
    if (list != NULL && ToAdd != NULL) {
        if (*list != NULL) {
            while ((*list)->NextNode != NULL) {
                *list = (*list)->NextNode;
            }
            (*list)->NextNode = ToAdd;
        } else {
            *list = ToAdd;
        }
    }
}

void DeleteIngridient(Ingridient **listPtr, Ingridient *ToDelete, Recipe **RecListPtr) {
    if (listPtr != NULL && ToDelete != NULL) {
        Ingridient *list = *listPtr;
        if (list == ToDelete) {
            *listPtr = ToDelete->NextNode;
            Recipe *RecList = *RecListPtr;
            Recipe *RecListNext = NULL;
            while (RecList != NULL) {
                RecipeIngridient *Tmp = RecList->RecIng;
                while (Tmp != NULL) {
                    RecListNext = RecList->NextNode;
                    if (Tmp->IngData == ToDelete) {
                        DeleteRecipe(RecListPtr, RecList);
                        break;
                    }
                    Tmp = Tmp->NextNode;
                }
                RecList = RecListNext;
            }
            free(ToDelete);
        } else {
            if (list != NULL) {
                while (list != NULL && list->NextNode != ToDelete) {
                    list = list->NextNode;
                }
                if (list != NULL) {
                    list->NextNode = ToDelete->NextNode;
                    Recipe *RecList = *RecListPtr;
                    Recipe *RecListNext = NULL;
                    while (RecList != NULL) {
                        RecipeIngridient *Tmp = RecList->RecIng;
                        while (Tmp != NULL) {
                            RecListNext = RecList->NextNode;
                            if (Tmp->IngData == ToDelete) {
                                DeleteRecipe(RecListPtr, RecList);
                                break;
                            }
                            Tmp = Tmp->NextNode;
                        }
                        RecList = RecListNext;
                    }
                    free(ToDelete);
                }
            }
        }
    }
}

Ingridient *FindIngridientByName(Ingridient *list, char *IngName) {
    while (list != NULL) {
        if (strcmp(list->IngName, IngName) == 0) {
            return list;
        }
        list = list->NextNode;
    }
    return NULL;
}


void PrintIngNameByIndex(Ingridient *list, int IngridientIndex) {
    if (list != NULL) {
        for (int i = 0; i < IngridientIndex; list = list->NextNode, i++) {
            if (list == NULL) {
                return;
            }
        }
    } else {
        return;
    }
    printf("%s\n", list->IngName);
}

void PrintAllIng(Ingridient *list) {
    if (list != NULL) {
        while (list != NULL) {
            printf("%s\n", list->IngName);
            list = list->NextNode;
        }
    }
}

void DeleteAllIng(Ingridient *list) {
    if (list != NULL) {
        while (list != NULL) {
            Ingridient *ToDelete = list;
            list = list->NextNode;
            free(ToDelete);
        }
    }
}
