//
// Created by hejag on 23/11/2024.
//

#ifndef INPUT_H
#define INPUT_H
#include <string.h>

#include "Ingridient.h"
#include "Recipe.h"

Ingridient* IngInput();

Recipe* RecInput(Ingridient* list);

typedef enum IngInputState {
    IName,
    IType,
    CreateIng,
    IReturn
}IngInputState;

typedef enum  RecInputState {
    RName,
    IsFav,
    IngCount,
    RecipeIngName,
    RecipeIngNumber,
    RecipeIngType,
    CreateRecipeIng,
    RecipeCreation,
    RReturn
}RecInputState;

MeasurementType IngTypeEnumerator(char* TypeString);
char* IngTypeDenumerator(MeasurementType Mtype);
bool IsFavChecker(char* TypeString);


void StrKiller(char *str);

#endif //INPUT_H
