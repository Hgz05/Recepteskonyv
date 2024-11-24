#include <stdio.h>
#include <string.h>

#include "Ingridient.h"
#include "input.h"
#include "Menu.h"

int main(void) {
    Ingridient* ElsoIngElem = IngInput();
    //PrintIngName(ElsoIngElem, 6);
    Recipe* ElsoRecELem = RecInput(ElsoIngElem);
    if(MainMenu(&ElsoIngElem, &ElsoRecELem) == 0) {
        return 0;
    }
}
