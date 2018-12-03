#include "Level3.h"
#include <stdlib.h>
#include <time.h>

Level3::Level3():Level(3){
    #ifdef seed
    srand(seed);
    #endif 
}

Level3::~Level3(){}

char Level3::getNextBlock(){
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
    }else{
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
    }
    return blockChar;  
}

void Level3::noRandom(std::string sequencefile){
    sequence = "";
    file = sequencefile;
    isRandom = false;
}

void Level3::random(){
    isRandom = true;
}
