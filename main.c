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
    }IngFileIterator;

    typedef enum RecFileIterator {
        RecName,
        RecIsFav,
        RecIngName,
        RecIngNum,
        RecIngType,
        RecLineBreak
    }RecFileIterator;

    Ingridient* ElsoIngElem = IngInput();
    //PrintIngName(ElsoIngElem, 6);
    Recipe* ElsoRecELem = RecInput(ElsoIngElem);
    if(MainMenu(&ElsoIngElem, &ElsoRecELem) == 0) {
        FILE* FIP = fopen("Osszetevok.txt", "w");
        Ingridient* Copy = ElsoIngElem;
        if(Copy != NULL) {
            IngFileIterator INext_State = IngName;
            while(Copy != NULL) {
                do {
                    switch (INext_State) {
                        case(IngName):
                            fprintf(FIP, Copy->IngName);
                        fprintf(FIP,";");
                        INext_State = IngType;
                        break;

                        case(IngType):
                            char* IngTypeChar = IngTypeDenumerator(Copy->MType);
                            fprintf(FIP, IngTypeChar); // WIll not convert properly
                        fprintf(FIP,";\n");
                        free(IngTypeChar);
                        INext_State = IngLineBreak;
                        break;
                    }
                }while(INext_State != IngLineBreak);
                INext_State = IngName;
                Copy = Copy->NextNode;
            }
        }
        fclose(FIP);
       /* FILE* FRP = fopen("Receptek.txt", "w");
        if(ElsoRecELem != NULL) {
            RecFileIterator RecNext_State = RecName;
            while(ElsoRecELem != NULL) {
                do {
                    switch (RecNext_State) {
                        case(RecName):
                            fprintf(FIP, ElsoRecELem->RecName);
                        fprintf(FIP,";");
                        RecNext_State = RecIsFav;
                        break;

                        case(RecIsFav):
                            char* RecIsFavChar = BoolFavConverter(ElsoRecELem->bIsFavorite);
                            fprintf(FIP, (RecIsFavChar)); // WIll not convert properly
                        fprintf(FIP,";\n");
                        free(RecIsFavChar);
                        RecNext_State = IngLineBreak;
                        break;
                    }
                }while(RecNext_State != RecLineBreak);
                RecNext_State = ;
                ElsoIngElem = ElsoIngElem->NextNode;
            }
        }
        fclose(FIP);*/
    }
    DeleteAllIng(&ElsoIngElem, &ElsoRecELem);
    return 0;
}
