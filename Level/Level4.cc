#include "Level4.h"
#include <stdlib.h>
#include <time.h>

Level4::Level4(Grid* g):Level(4), g(g){
    #ifdef seed
    srand(seed);
    #endif 
}

Level4::~Level4(){}

char Level4::getNextBlock(){
    char blockChar;
    if(!isRandom){
        //If the sequence string is empty, read again from the file and fill it
        if(sequence == ""){
            std::ifstream inputFile{file};
            getline(inputFile,sequence);
        }
        //Take the first char for the block and remove it from the string
        blockChar = sequence.substr(0,1)[0];
        sequence = sequence.substr(1);
    } else {
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
        //If num blocks since clear is a multiple of five look for an empty
        //space in the center of the screen and make it a *
        if(numBlocksSinceClear % 5 == 0 && numBlocksSinceClear != 0){
            const int x = 5;
            for(int y = 17; y > 2; y--){
                if(!g->getGridCell(x,y)->isUsed){
                    g->getGridCell(x,y)->isUsed = true;
                    g->getGridCell(x,y)->setType('*');
                    break;
                }
            }
        }
        numBlocksSinceClear++;
    }
    return blockChar;  
}

int Level4::getScore(int linesCleared){
    numBlocksSinceClear = 0;
    return (4 + linesCleared)*(4 + linesCleared);
}

void Level4::noRandom(std::string sequencefile){
    sequence = "";
    file = sequencefile;
    isRandom = false;
}

void Level4::random(){
    isRandom = true;
}
