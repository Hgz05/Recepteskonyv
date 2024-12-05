//
// Created by hejag on 23/11/2024.
//

#include "Recipe.h"

#include <stdio.h>

#include "input.h"
#include "Ingridient.h"
#include "debugmalloc.h"

Recipe *CreateRecipe(char *Name, bool bIsFav) {
    Recipe *Rec = (Recipe *) malloc(sizeof(Recipe));
    strcpy(Rec->RecName, Name);
    Rec->bIsFavorite = bIsFav;
    Rec->NextNode = NULL;
    Rec->RecIng = NULL;
    return Rec;
}

void AssignIngridients(Recipe *Rec, RecipeIngridient *RecIngridient) {
    if (Rec != NULL && RecIngridient != NULL) {
        while (Rec->NextNode != NULL) {
            Rec = Rec->NextNode;
        }
        Rec->RecIng = RecIngridient;
    }
}

void AddRecipeTo(Recipe *list, Recipe *ToAdd) {
    if (list != NULL && ToAdd != NULL) {
        while (list->NextNode != NULL) {
            list = list->NextNode;
        }
        list->NextNode = ToAdd;
    }
}

void AddOrCreateRecipe(Recipe **list, Recipe *ToAdd) {
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

void DeleteRecipe(Recipe **listPtr, Recipe *ToDelete) {
    if (listPtr != NULL && ToDelete != NULL) {
        Recipe *list = *listPtr;
        if (list == ToDelete) {
            *listPtr = ToDelete->NextNode;
            DeleteAllRecIng(ToDelete->RecIng);
            free(ToDelete);
        } else {
            if (list != NULL) {
                while (list->NextNode != ToDelete) {
                    list = list->NextNode;
                }

                list->NextNode = ToDelete->NextNode;
                DeleteAllRecIng(ToDelete->RecIng);
                free(ToDelete);
            }
        }
    }
}

Recipe *FindRecipeByName(Recipe *list, char *RecipeName) {
    while (list != NULL) {
        if (strcmp(list->RecName, RecipeName) == 0) {
            return list;
        }
        list = list->NextNode;
    }
    return NULL;
}

void RecipePrint(Recipe *PRecipe) {
    if (PRecipe != NULL) {
        printf("%s\n", PRecipe->RecName);
        RecipeIngridient *NextRecipeIngridient = PRecipe->RecIng;
        while (NextRecipeIngridient != NULL) {
            printf("\t\%s ", NextRecipeIngridient->IngData->IngName);
            printf("%d ", NextRecipeIngridient->IngAmount);
            char *TmpChar = IngTypeDenumerator(NextRecipeIngridient->IngData->MType);
            printf("%s\n", TmpChar);
            free(TmpChar);
            NextRecipeIngridient = NextRecipeIngridient->NextNode;
        }
    }
}


void PrintRecipeByIng(Recipe *list) {
    if (list != NULL) {
        char IngName[50];
        printf("Adja meg az osszetevot: \n");
        scanf("%s", IngName);
        Recipe *RCopy = NULL;
        RCopy = list;
        while (RCopy != NULL) {
            RecipeIngridient *RICopy = RCopy->RecIng;
            while (RICopy != NULL) {
                if (strcmp(RICopy->IngData->IngName, IngName) == 0) {
                    RecipePrint(FindRecipeByName(list, RCopy->RecName));
                }
                RICopy = RICopy->NextNode;
            }
            RCopy = RCopy->NextNode;
        }
    }
}

void PrintFavRecipes(Recipe *list) {
    if (list != NULL) {
        if (list->bIsFavorite == true) {
            printf("%s\n", list->RecName);
        }
        while (list->NextNode != NULL) {
            list = list->NextNode;
            if (list->bIsFavorite == true) {
                printf("%s\n", list->RecName);
            }
        }
    }
}


void SetFavorite(Recipe *list, char *SetFavName, bool isFav) {
    if (list != NULL) {
        if (FindRecipeByName(list, SetFavName) != NULL) {
            if (isFav == true) {
                Recipe *ToFav = FindRecipeByName(list, SetFavName);
                ToFav->bIsFavorite = true;
            } else {
                Recipe *ToFav = FindRecipeByName(list, SetFavName);
                ToFav->bIsFavorite = false;
            }
        }
    }
}

void PrintAllRecipes(Recipe *list) {
    if (list != NULL) {
        while (list != NULL) {
            RecipePrint(list);
            list = list->NextNode;
        }
    }
}

void AddRecipeFromIO(Ingridient *IngList, Recipe *RecList) {
    char RecName[100];
    char isFav[5];
    int IngCount;
    printf("Recept neve: \n");
    scanf("%s", RecName);
    printf("Kedvenc recept(igen/nem): \n");
    scanf("%s", isFav);
    if (strcmp("igen", isFav) != 0 && strcmp("nem", isFav) != 0) {
        printf("Invalid isFav value\n");
        return;
    }
    Recipe *NewRecipe = CreateRecipe(RecName, AddRecipeFromIOIsFav(isFav));
    RecipeIngridient *ReturnRecIng = NULL;
    printf("Osszetevok szama: \n");
    scanf("%d", &IngCount);
    for (int i = 0; i < IngCount; i++) {
        char IngName[40];
        int IngNumber;
        char IngType[10];
        printf("Osszetevo neve: \n");
        scanf("%s", IngName);
        printf("Osszetevo mennyiseg: \n");
        scanf("%d", &IngNumber);
        printf("Osszetevo mertekegyseg (darab/kilogramm/liter): \n");
        scanf("%s", IngType);
        if (FindIngridientByName(IngList, IngName) == NULL) {
            Ingridient *NewIngridient = CreateIngridient(IngName, IngTypeEnumerator(IngType));
            AddIngridientTo(IngList, NewIngridient);
        }
        if (ReturnRecIng == NULL) {
            ReturnRecIng = CreateRecipeIngridient(IngNumber, FindIngridientByName(IngList, IngName));
        } else {
            AddRITo(ReturnRecIng, CreateRecipeIngridient(IngNumber, FindIngridientByName(IngList, IngName)));
        }
    }
    AssignIngridients(NewRecipe, ReturnRecIng);
    AddRecipeTo(RecList, NewRecipe);
}

bool AddRecipeFromIOIsFav(char *IsFav) {
    if (strcmp("igen", IsFav) == 0) {
        return true;
    }
    if (strcmp("nem", IsFav) == 0) {
        return false;
    }
    return false;
}

void DeleteAllRecipe(Recipe *list) {
    if (list != NULL) {
        while (list != NULL) {
            Recipe *ToDelete = list;
            list = list->NextNode;
            DeleteAllRecIng(ToDelete->RecIng);
            free(ToDelete);
        }
    }
}

int RecipeListLen(Recipe *list) {
    int RecListLen = 0;
    if (list != NULL) {
        while (list != NULL) {
            RecListLen++;
            list = list->NextNode;
        }
        return RecListLen;
    }
    return -1;
}

char *BoolFavConverter(bool IsFav) {
    char *isFavChar = malloc(sizeof(char)*6);
    if (IsFav == true) {
        strcpy(isFavChar, "true");
        return isFavChar;
    }
    if (IsFav == false) {
        strcpy(isFavChar, "false");
        return isFavChar;
    }
    free(isFavChar);
    return NULL;
}
