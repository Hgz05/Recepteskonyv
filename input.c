//
// Created by hejag on 23/11/2024.
//
#include "debugmalloc.h"
#include "input.h"

#include <stdio.h>

#include "Ingridient.h"
#include "Recipe.h"

Ingridient *IngInput() {
    FILE *fp = fopen("Osszetevok.txt", "r");
    if (fp == NULL) {
        printf("File read error: Osszetevok.txt ");
        return NULL;
    }
    Ingridient *ReturnIng = NULL;
    char InputCharacter;
    IngInputState next_state = IName;
    char ingName[40];
    char ingType[10];
    int ingNameIndex = 0;
    int ingTypeIndex = 0;
    while (next_state != IReturn) {
        while ((InputCharacter = fgetc(fp)) != EOF) {
            switch (next_state) {
                case(IName):
                    if (InputCharacter == ';') {
                        next_state = IType;
                        break;
                    }
                    ingName[ingNameIndex] = InputCharacter;
                    ingNameIndex++;
                    break;

                case(IType):
                    if (InputCharacter == ';') {
                        next_state = CreateIng;
                        break;
                    }
                    ingType[ingTypeIndex] = InputCharacter;
                    ingTypeIndex++;
                    break;

                case(CreateIng):
                    ingName[ingNameIndex] = '\0';
                    ingType[ingTypeIndex] = '\0';
                    ingNameIndex = 0;
                    ingTypeIndex = 0;
                    if (ReturnIng == NULL) {
                        ReturnIng = CreateIngridient(ingName, IngTypeEnumerator(ingType));
                        ReturnIng->NextNode = NULL;
                    } else {
                        AddIngridientTo(ReturnIng, CreateIngridient(ingName, IngTypeEnumerator(ingType)));
                    }
                    StrKiller(ingName);
                    StrKiller(ingType);
                    next_state = IName;
                    break;
                default:
                    break;
            }
        }
        next_state = IReturn;
    }
    ingName[ingNameIndex + 1] = '\0';
    ingType[ingTypeIndex] = '\0';
    AddIngridientTo(ReturnIng, CreateIngridient(ingName, IngTypeEnumerator(ingType)));
    fclose(fp);
    return ReturnIng;
}


MeasurementType IngTypeEnumerator(char *TypeString) {
    if (strcmp(TypeString, "darab") == 0) {
        return darab;
    }
    if (strcmp(TypeString, "kilogramm") == 0) {
        return kilogramm;
    }
    if (strcmp(TypeString, "liter") == 0) {
        return liter;
    }
    return -1;
}

char* IngTypeDenumerator(MeasurementType Mtype) {
    char* TypeString = malloc(sizeof(char)*10);
    if(Mtype == darab) {
        strcpy(TypeString,"darab");
        return TypeString;
    }
    if(Mtype == kilogramm) {
        strcpy(TypeString, "kilogramm");
        return TypeString;
    }
    if (Mtype == liter) {
        strcpy(TypeString, "liter");
        return TypeString;
    }
    free(TypeString);
    return TypeString;
}


void StrKiller(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = "";
    }
}

Recipe *RecInput(Ingridient *list) {
    FILE *fp = fopen("Receptek.txt","r");
    if (fp == NULL) {
        printf("File read error: Receptek.txt ");
        return NULL;
    }
    RecInputState next_state = RName;
    char InputCharacter;
    Recipe *ReturnRec = NULL;
    RecipeIngridient *ReturnRecIng = NULL;
    char recName[100];
    char recIngName[40];
    char recIngType[10];
    char recIsFav[6];
    int recNameIndex = 0;
    int recIngNameIndex = 0;
    int recIngTypeIndex = 0;
    int recIsFavIndex = 0;
    int recIngCount = 0; //The number of Ingridients in the .txt file
    int currentIngCount = 0; //Hanyadik osszetevonel tartunk
    int ingNumber = 0; // The number of Ingridients inside a RecipeIngridient.
    while (next_state != RReturn) {
        while ((InputCharacter = fgetc(fp)) != EOF) {
            switch (next_state) {
                case(RName):
                    if (InputCharacter == ';') {
                        next_state = IsFav;
                        break;
                    }
                    recName[recNameIndex] = InputCharacter;
                    recNameIndex++;
                    break;

                case(IsFav):
                    if (InputCharacter == ';') {
                        next_state = IngCount;
                        break;
                    }
                    recIsFav[recIsFavIndex] = InputCharacter;
                    recIsFavIndex++;
                    break;

                case(IngCount):
                    if (InputCharacter == ';') {
                        next_state = RecipeIngName;
                        break;
                    }
                    recIngCount = InputCharacter - '0';
                    break;

                case(RecipeIngName):
                    /*if(currentIngCount == recIngCount) {
                        next_state = RReturn; //Will kill the program
                        break;
                    }*/
                    if (InputCharacter == ';') {
                        next_state = RecipeIngNumber;
                        break;
                    }
                    recIngName[recIngNameIndex] = InputCharacter;
                    recIngNameIndex++;
                    break;

                case(RecipeIngNumber):
                    if (InputCharacter == ';') {
                        next_state = RecipeIngType;
                        break;
                    }
                    ingNumber = InputCharacter -'0';
                    break;

                case(RecipeIngType):
                    if (InputCharacter == ';') {
                        next_state = CreateRecipeIng;
                        break;
                    }
                    //recIngType[recIngTypeIndex] = InputCharacter;
                    //recIngTypeIndex++;
                    break;

                case(CreateRecipeIng):
                    recIngName[recIngNameIndex] = '\0';
                    //recIngType[recIngTypeIndex + 1] = '\0'; //Ezene a ponton elveszik a recIngName
                    recIngNameIndex = 0;
                    //recIngTypeIndex = 0;
                    if (ReturnRecIng == NULL) {
                        ReturnRecIng = CreateRecipeIngridient(ingNumber, FindIngridientByName(list, recIngName));
                    } else {
                        AddRITo(ReturnRecIng,
                                CreateRecipeIngridient(ingNumber, FindIngridientByName(list, recIngName)));
                    }
                    currentIngCount++;
                    if (currentIngCount == recIngCount) {
                        next_state = RecipeCreation;
                        StrKiller(recIngName);
                        //StrKiller(recIngType);
                        break;
                    }
                    StrKiller(recIngName);
                    //StrKiller(recIngType);
                    next_state = RecipeIngName;
                    break;

                case(RecipeCreation):
                    recName[recNameIndex] = '\0';
                    recIsFav[recIsFavIndex + 1] = '\0';
                    recNameIndex = 0;
                    recIsFavIndex = 0;
                    currentIngCount = 0;

                    if (ReturnRec == NULL) {
                        ReturnRec = CreateRecipe(recName, IsFavChecker(recIsFav));
                    } else {
                        AddRecipeTo(ReturnRec, CreateRecipe(recName, IsFavChecker(recIsFav)));
                    }
                    AssignIngridients(ReturnRec, ReturnRecIng);
                    ReturnRecIng = NULL;
                    StrKiller(recName);
                    StrKiller(recIsFav);

                next_state = RName;
                    break;

                default:
                    break;
            }
        }
        next_state = RReturn;
    }
    recName[recNameIndex] = '\0';
    recIsFav[recIsFavIndex + 1] = '\0';
    AddRecipeTo(ReturnRec, CreateRecipe(recName, IsFavChecker(recIsFav)));
    AssignIngridients(ReturnRec, ReturnRecIng);
    fclose(fp);
    return ReturnRec;
}

bool IsFavChecker(char *TypeString) {
    if (strcmp(TypeString, "true") == 0) {
        return true;
    }
    if (strcmp(TypeString, "false") == 0) {
        return false;
    }
    return -1;
}
