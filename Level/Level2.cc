#include "Level2.h"
#include <stdlib.h>
#include <time.h>

Level2::Level2(int seed):Level(2){
    if(seed != -1){
    srand(seed);
    }
}

Level2::~Level2(){}

char Level2::getNextBlock(){
    char blockChar;
    int random = rand() % 70;
    //We generate a number from 0-70, 
    //then we assign a character to each number
    if(random >= 0 && random < 10){blockChar = 'S';}
    else if (random >= 10 && random < 20){blockChar = 'Z';}
    else if (random >= 20 && random < 30){blockChar = 'T';}
    else if (random >= 30 && random < 40){blockChar = 'J';}
    else if (random >= 40 && random < 50){blockChar = 'L';}
    else if (random >= 50 && random < 60){blockChar = 'O';}
    else if (random >= 60 && random < 70){blockChar = 'I';}
    return blockChar;  
}

void Level2::noRandom(std::string sequencefile){}

void Level2::random(){}