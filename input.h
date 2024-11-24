//
// Created by hejag on 23/11/2024.
//

#ifndef INPUT_H
#define INPUT_H
#include <string.h>

#include "Ingridient.h"
#include "Recipe.h"

Ingridient *IngInput();

Recipe *RecInput(Ingridient *list);

/**
 * The states used for "Osszetevok.txt" file reading.
 */
typedef enum IngInputState {
    IName,
    IType,
    CreateIng,
    IReturn
} IngInputState;

/**
 * The states used for "Receptek.txt" file reading.
 */
typedef enum RecInputState {
    RName,
    IsFav,
    IngCount,
    RecipeIngName,
    RecipeIngNumber,
    RecipeIngType,
    CreateRecipeIng,
    RecipeCreation,
    RReturn
} RecInputState;

/**
 * Converts a string to a MeasurementType enum.
 * @param TypeString The that will be converted
 * @return MeasurementType.
 */
MeasurementType IngTypeEnumerator(char *TypeString);

/**
 * Converts MeasurementType enum to a string.
 * @param Mtype MeasurementType enum that will be converted.
 * @return Address of the string.
 */
char *IngTypeDenumerator(MeasurementType Mtype);

/**
 * Converts a string to a true or false value.
 * @param TypeString The string that will be converted.
 * @return True or false value.
 */
bool IsFavChecker(char *TypeString);

/**
 * Empties a string
 * @param str The string.
 */
void StrKiller(char *str);

#endif //INPUT_H
