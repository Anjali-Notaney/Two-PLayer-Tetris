#include "Level3.h"
#include <stdlib.h>
#include <vector>
#include "../Grid/GridCell.h"
#include <time.h>

Level3::Level3():Level(3){
    srand(time(NULL));
}

Level3::~Level3(){}

Block* Level3::getNextBlock(){
    char blockChar;
    int random = rand() % 9;
    //We generate a number from 0-9, 
    //then we assign a character to each number
    //some characters have more numbers are they are more probable
    if(random == 0 || random == 1){blockChar = 'S';}
    else if (random == 2 || random == 3){blockChar = 'Z';}
    else if (random == 4){blockChar = 'T';}
    else if (random == 5){blockChar = 'J';}
    else if (random == 6){blockChar = 'L';}
    else if (random == 7){blockChar = 'O';}
    else if (random == 8){blockChar = 'I';}
    std::vector<GridCell*> retVec;
    return new Block(nullptr, retVec, blockChar);  
}