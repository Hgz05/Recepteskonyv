#include <stdio.h>
#include <string.h>

#include "Ingridient.h"
#include "input.h"
#include "Menu.h"

int main(void) {
    typedef enum IngFileIterator {
        IngName,
        IngType,
        IngLineBreak
    }IngFileIterator;

    Ingridient* ElsoIngElem = IngInput();
    //PrintIngName(ElsoIngElem, 6);
    Recipe* ElsoRecELem = RecInput(ElsoIngElem);
    if(MainMenu(&ElsoIngElem, &ElsoRecELem) == 0) {
        FILE* FIP = fopen("Osszetevok.txt", "w");
        if(ElsoIngElem != NULL) {
            IngFileIterator INext_State = IngName;
            while(ElsoIngElem != NULL) {
                do {
                    switch (INext_State) {
                        case(IngName):
                            fprintf(FIP, ElsoIngElem->IngName);
                        fprintf(FIP,";");
                        INext_State = IngType;
                        break;

                        case(IngType):
                            fprintf(FIP, IngTypeDenumerator(ElsoIngElem->MType)); // WIll not convert properly
                        fprintf(FIP,";\n");
                        INext_State = IngLineBreak;
                        break;
                    }
                }while(INext_State != IngLineBreak);
                INext_State = IngName;
                ElsoIngElem = ElsoIngElem->NextNode;
            }
        }
        fclose(FIP);
    }
    return 0;
}
