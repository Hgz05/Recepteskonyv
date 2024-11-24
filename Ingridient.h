//
// Created by hejag on 23/11/2024.
//

#ifndef INGRIDIENT_H
#define INGRIDIENT_H
#include "debugmalloc.h"
#include <stdlib.h>
#include <string.h>

typedef struct Recipe Recipe;

/**
 * Enum that indicates the ingridient mesurement type.
 */
typedef enum MeasurementType {
    kilogramm,
    liter,
    darab
} MeasurementType;

/**
 * Ingrident struct that stores and Ingridient name, Mesurment Type of the ingridient in the form of an enum and an ingridient pointer that is used to make a linked list.
 */
typedef struct Ingridient {
 /**
  * The ingridients name.
  */
 char IngName[40];
 /**
  * The type of the ingridnient.
  */
 MeasurementType MType;
 /**
  * The pointer to the next Ingridient.
  */
 struct Ingridient *NextNode;
} Ingridient;

/**
 * Creates an Ingridient pointer.
 * @param Name Name of the ingridient.
 * @param Type Mesurment type of the ingridient.
 * @return Ingridient pointer.
 */
Ingridient *CreateIngridient(char *Name, MeasurementType Type);

/**
 * Adds an Ingridient to an already existing Ingridient linked list.
 * @param list The first address of the list.
 * @param ToAdd The Pointer of Ingridient that will be added to the list.
 */
void AddIngridientTo(Ingridient *list, Ingridient *ToAdd);

/**
 * This function is not used.
 * @param list
 * @param ToAdd
 */
void AddOrCreateIng(Ingridient **list, Ingridient *ToAdd);

/**
 * Deletes and element of the linked list.
 * @param listPtr Pointer of the first address.
 * @param ToDelete The list element that will be deleted.
 * @param RecListPtr Pointer of the first element of the Recipe linked list.
 */
void DeleteIngridient(Ingridient **listPtr, Ingridient *ToDelete, Recipe **RecListPtr);

/**
 * Finds an ingridient by name
 * @param list The address of the first element of the ingridient linked list.
 * @param IngName A name of the ingrident that is being searched.
 * @return The address of the Ingridient.
 */
Ingridient *FindIngridientByName(Ingridient *list, char *IngName);

/**
 * Prints the elemnt definded by the index.
 * @param list The address first element of the Ingridient linked list.
 * @param IngridientIndex an index.
 */
void PrintIngNameByIndex(Ingridient *list, int IngridientIndex);

/**
 * Prints all Ingridients.
 * @param list The address of the first element of the Ingridient linked list.
 */
void PrintAllIng(Ingridient *list);

/**
 * Deletes all Ingridients
 * @param list The address of the first element of the Ingridient linked list.
 */
void DeleteAllIng(Ingridient **listPtr, Recipe **RecListPtr);
#endif //INGRIDIENT_H
