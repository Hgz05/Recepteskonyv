#include <stdio.h>
#include <string.h>

#include "Ingridient.h"
#include "input.h"
#include "Menu.h"
#include "debugmalloc.h"

int main(void) {
    typedef enum IngFileIterator {
        IngName,
        IngType,
        IngLineBreak
    } IngFileIterator;

    typedef enum RecFileIterator {
        RecName,
        RecIsFav,
        RecIngCount,
        RecIngReader,
        RecLineBreak
    } RecFileIterator;

    Ingridient *ElsoIngElem = IngInput();
    Recipe *ElsoRecELem = RecInput(ElsoIngElem);
    if (MainMenu(&ElsoIngElem, &ElsoRecELem) == 0) {
        FILE *FIP = fopen("Osszetevok.txt", "w");
        Ingridient *IngCopy = ElsoIngElem;
        if (IngCopy != NULL) {
            IngFileIterator INext_State = IngName;
            while (IngCopy != NULL) {
                do {
                    switch (INext_State) {
                        case(IngName):
                            fprintf(FIP, IngCopy->IngName);
                            fprintf(FIP, ";");
                            INext_State = IngType;
                            break;

                        case(IngType):
                            char *IngTypeChar = IngTypeDenumerator(IngCopy->MType);
                            fprintf(FIP, IngTypeChar);
                            fprintf(FIP, ";");
                            if (IngCopy->NextNode != NULL) {
                                fprintf(FIP, "\n");
                            }
                            free(IngTypeChar);
                            INext_State = IngLineBreak;
                            break;

                        case(IngLineBreak):
                            break;
                    }
                } while (INext_State != IngLineBreak);
                INext_State = IngName;
                IngCopy = IngCopy->NextNode;
            }
        }
        fclose(FIP);
        FILE *FRP = fopen("Receptek.txt", "w");
        Recipe *RecCopy = ElsoRecELem;
        if (RecCopy != NULL) {
            RecFileIterator RecNext_State = RecName;
            while (RecCopy != NULL) {
                do {
                    switch (RecNext_State) {
                        case(RecName):
                            fprintf(FRP, RecCopy->RecName);
                            fprintf(FRP, ";");
                            RecNext_State = RecIsFav;
                            break;

                        case(RecIsFav):
                            char *RecIsFavChar = BoolFavConverter(RecCopy->bIsFavorite);
                            fprintf(FRP, (RecIsFavChar));
                            fprintf(FRP, ";");
                            free(RecIsFavChar);
                            RecNext_State = RecIngCount;
                            break;

                        case(RecIngCount):
                            int RecIngCountInt = 0;
                            RecipeIngridient *TmpRecIng = RecCopy->RecIng;
                            while (TmpRecIng != NULL) {
                                RecIngCountInt++;
                                TmpRecIng = TmpRecIng->NextNode;
                            }
                            fprintf(FRP, "%d", RecIngCountInt);
                            fprintf(FRP, ";");
                            RecNext_State = RecIngReader;
                            break;

                        case(RecIngReader):
                            RecipeIngridient *RecIngCopy = RecCopy->RecIng;
                            while (RecIngCopy != NULL) {
                                fprintf(FRP, RecIngCopy->IngData->IngName);
                                fprintf(FRP, ";");
                                fprintf(FRP, "%d", RecIngCopy->IngAmount);
                                fprintf(FRP, ";");
                                char *TmpIngType = IngTypeDenumerator(RecIngCopy->IngData->MType);
                                fprintf(FRP, TmpIngType);
                                free(TmpIngType);
                                fprintf(FRP, ";;");
                                RecIngCopy = RecIngCopy->NextNode;
                            }
                            if (RecCopy->NextNode != NULL) {
                                fprintf(FRP, "\n");
                            }
                            RecNext_State = RecLineBreak;
                            break;

                        case(RecLineBreak):
                            break;
                    }
                } while (RecNext_State != RecLineBreak);
                RecNext_State = RecName;
                RecCopy = RecCopy->NextNode;
            }
        }
        fclose(FRP);
    }
    DeleteAllIng(&ElsoIngElem, &ElsoRecELem);
    return 0;
}
