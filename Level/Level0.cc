#include "Level0.h"
#include "../Blocks/Block.h"
#include "../Grid/GridCell.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

Level0::Level0(std::string file):Level(0), file(file){}

Level0::~Level0(){}

Block* Level0::getNextBlock(){
    //If the sequence string is empty, read again from the file and fill it
    if(sequence == ""){
        std::ifstream inputFile{file};
        getline(inputFile,sequence);
    }
    //Take the first char for the block and remove it from the string
    char blockChar = sequence.substr(0,1)[0];
    sequence = sequence.substr(1);
    std::vector<GridCell*> retVector;
    return new Block(nullptr,retVector,blockChar);
}


