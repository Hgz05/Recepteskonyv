//
// Created by hejag on 24/11/2024.
//

#include "Menu.h"

#include <stdio.h>

#include "input.h"
#include "debugmalloc.h"
#include "debugmalloc.h"
void LogoPrinter() {
    for (int i = 0; i < 11; i++) {
        if (i == 0 || i == 10) {
            for (int j = 0; j < 40; j++) {
                printf("*");
            }
            printf("\n");
        } else if (i == 4) {
            printf("*");
            for (int j = 0; j < 12; j++) {
                printf(" ");
            }
            printf("Receptes Konyv");
            for (int j = 0; j < 12; j++) {
                printf(" ");
            }
            printf("*\n");
        } else if (i == 6) {
            printf("*");
            for (int j = 0; j < 8; j++) {
                printf(" ");
            }
            printf("By: Heja Gergo Zoltan");
            for (int j = 0; j < 9; j++) {
                printf(" ");
            }
            printf("*\n");
        } else {
            printf("*");
            for (int j = 0; j < 38; j++) {
                printf(" ");
            }
            printf("*\n");
        }
    }
}

int MainMenu(Ingridient** IngListPtr, Recipe **RecipeList) {
    int MenuSelection = 0;
    // Ingridient* IngList = *IngListPtr;
    do {
        LogoPrinter();
        printf("\n(1). Recept keresese\n"
            "(2). Receptek szerkesztese\n"
            "(3). Osszetevok szerkesztese\n"
            "(4). Recept kedvencnek jelolese\n"
            "(5). Recept ajanlasa\n"
            "(0). Kilepes\n");
        scanf("%d", &MenuSelection);
        switch (MenuSelection) {
            case(1):
                SearchMenu(IngListPtr, RecipeList);
                break;
            case(2):
                RecipeMenu(IngListPtr, RecipeList);
                break;
            case(3):
                IngManageMenu(IngListPtr, RecipeList);
                break;
            case(4):
                FavMenu(RecipeList);
                break;
            case(5):
                RandomRecipe(*RecipeList);
            case(0):
                break;
            default:
                printf("Hibas bemeneti ertek.");
        }
    } while (MenuSelection != 0);
    return 0;
}

void SearchMenu(Ingridient **IngList, Recipe **RecipeList) {
    int MenuSelection = 0;
    do {
        printf("Receptek keresese:\n\n"
            "(1). Nev szerint\n"
            "(2). Osszetevok Szerint\n"
            "(3). Kedvenc Receptek\n"
            "(0). Vissza\n");
        scanf("%d", &MenuSelection);
        switch (MenuSelection) {
            case(1):
                char searchRecipe[100];
                printf("Recept neve:\n");
                scanf("%s", searchRecipe);
                RecipePrint(FindRecipeByName(*RecipeList, searchRecipe));
                break;
            case(2):
                FindRecipeByIngs(*RecipeList);  //Figure out the logic for this
                break;
            case(3):
                PrintFavRecipes(*RecipeList);
            case(0):
                break;
            default:
                printf("Hibas bemeneti ertek.");
        }
    } while (MenuSelection != 0);
}

void RecipeMenu(Ingridient **IngList, Recipe **RecipeList) {
    int MenuSelection = 0;

    do {
        printf("(1). Receptek kislistazasa\n"
            "(2). Recept hozzaadasa\n"
            "(3). Recept torlese\n"
            "(0). Vissza\n");
        scanf("%d", &MenuSelection);
        switch (MenuSelection) {
            case(1):
                PrintAllRecipes(*RecipeList);
                break;
            case(2):
                AddRecipeFromIO(*IngList, *RecipeList);
                break;
            case(3):
                char ToDeleteName[100];
                printf("Torolni kivant recept neve: \n");
                scanf("%s", ToDeleteName);
                DeleteRecipe(RecipeList, FindRecipeByName(*RecipeList, ToDeleteName));
                break;
            case(0):
                break;
            default:
                printf("Hibas bemeneti ertek.");
        }
    } while (MenuSelection != 0);
}

void IngManageMenu(Ingridient **IngList, Recipe **RecipeList) {
    int MenuSelection = 0;
    do {
        printf("(1). Osszetevok kilistazasa\n"
            "(2). Osszetevo hozzaadasa.\n"
            "(3). Osszetevo torlese.\n"
            "(0). Vissza\n");
        scanf("%d", &MenuSelection);
        switch (MenuSelection) {
            case(1):
                PrintAllIng(*IngList);
                break;
            case(2):
                char IngName[100];
                char IngType[10];
                printf("Osszetevo neve: \n");
                scanf("%s", IngName);
                printf("Osszetevo mertekegyseg (darab/kilogramm/liter): \n");
                scanf("%s", IngType);
                if (strcmp(IngType, "darab") != 0 && strcmp(IngType, "kilogramm") != 0 && strcmp(IngType, "liter") !=
                    0) {
                    printf("Invalid IngType input\n");
                }
                AddIngridientTo(*IngList, CreateIngridient(IngName, IngTypeEnumerator(IngType)));
                break;
            case(3):
                char DelIngName[40];
                printf("Torlendo osszetevo neve (az osszes recept ami ezt tartalmazza torolve lesz):");
                scanf("%s", DelIngName);
                DeleteIngridient(IngList, FindIngridientByName(*IngList, DelIngName),RecipeList);
                break;
            case(0):
                break;
            default:
                printf("Hibas bemeneti ertek.");
        }
    } while (MenuSelection != 0);
}

void FavMenu(Recipe **RecipeList) {
    int MenuSelection = 0;
    do {
        printf("(1). Kedvenc receptek listazasa.\n"
            "(2). Receptek kedvencnek jelolese\n"
            "(3). Receptek torlese a kedvencek listajabol\n"
            "(0). Vissza\n");
        scanf("%d", &MenuSelection);
        switch (MenuSelection) {
            case(1):
                PrintFavRecipes(*RecipeList);
                break;
            case(2):
                char AddFavName[100];
                printf("Kedvenc Recept neve: \n");
                scanf("%s", AddFavName);
                SetFavorite(*RecipeList, AddFavName, true);
                break;
            case(3):
                char RemFavName[100];
                printf("Kedvenc Recept neve: \n");
                scanf("%s", RemFavName);
                SetFavorite(*RecipeList, RemFavName, false);
                break;
            case(0):
                break;
            default:
                printf("Hibas bemeneti ertek.");
        }
    } while (MenuSelection != 0);

}

void RandomRecipe(Recipe *RecipeList) {
    if(RecipeList != NULL){
        Recipe* tmp = RecipeList;
        int RecListLen = RecipeListLen(RecipeList);
        int random = rand() % RecListLen;
        for(int i = 0; i<random; tmp = tmp->NextNode ,i++) {}
        RecipePrint(tmp);
    }
}
