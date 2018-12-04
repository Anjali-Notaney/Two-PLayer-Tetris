#include "Level.h"

Level::Level(int level):level(level){}

Level::~Level(){}

int Level::getScore(int linesCleared){
    return (level + linesCleared)*(level + linesCleared);
}

int Level::getLevel(){
    return level;
}

