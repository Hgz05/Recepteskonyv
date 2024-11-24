//
// Created by hejag on 23/11/2024.
//

#ifndef INGRIDIENT_H
#define INGRIDIENT_H
#include <stdlib.h>
#include <string.h>

typedef struct Recipe Recipe;

typedef enum MeasurementType {
    kilogramm,
    liter,
    darab
}MeasurementType;

typedef struct Ingridient {
    char IngName[40];
    MeasurementType MType;
    struct Ingridient* NextNode;
}Ingridient;

Ingridient* CreateIngridient(char* Name, MeasurementType Type);
void AddIngridientTo(Ingridient* list, Ingridient* ToAdd);
void AddOrCreateIng(Ingridient** list, Ingridient* ToAdd);
void DeleteIngridient(Ingridient** listPtr, Ingridient* ToDelete, Recipe** RecListPtr);
Ingridient* FindIngridientByName(Ingridient* list, char* IngName);
void PrintIngNameByIndex(Ingridient* list, int IngridientIndex);
void PrintAllIng(Ingridient* list);
void DeleteAllIng(Ingridient* list);
#endif //INGRIDIENT_H
