#include "Level1.h"
#include <stdlib.h>

Level1::Level1():Level(1){
    #ifdef seed
    srand(seed);
    #endif 
}

Level1::~Level1(){}

char Level1::getNextBlock(){
    char blockChar;
    int random = rand() % 12;
    //We generate a number from 0-11, then we assign a character to each
    //number, giving more numbers to those with higher probability
    if(random == 0){blockChar = 'S';}
    else if (random == 1){blockChar = 'Z';}
    else if (random >= 2 && random <= 3){blockChar = 'T';}
    else if (random >= 4 && random <= 5){blockChar = 'J';}
    else if (random >= 6 && random <= 7){blockChar = 'L';}
    else if (random >= 8 && random <= 9){blockChar = 'O';}
    else if (random >= 10 && random <= 11){blockChar = 'I';}
    return blockChar;  
}

void Level1::noRandom(std::string sequencefile){}

void Level1::random(){}