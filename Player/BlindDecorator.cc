#include <iostream>
#include <utility>
#include <stdexcept>
#include "BlindDecorator.h"
#include <memory>

BlindDecorator::BlindDecorator(Player *component): player{component}{}

BlindDecorator::~BlindDecorator(){
    delete player;
}

Player* BlindDecorator::getBasePlayer(){
    Player *tmp = player->getBasePlayer();
    if (tmp != player){
        delete player;
    }
    return tmp;
}

std::vector<GridCell>* BlindDecorator::getRow(int rowNum){
    return player->getRow(rowNum);
}

bool BlindDecorator::isHeavyLevel(){
    return player->isHeavyLevel();
}

void BlindDecorator::setHeavyLevel(bool isHeavy){
    player->setHeavyLevel(isHeavy);
}

void BlindDecorator::printRow (int rowNum) {
    std::vector<GridCell> gridRow = *(player->getRow(rowNum));
    for (int i = 0; i < player->getGridWidth(); i++){
        if ((rowNum >= 6) and (rowNum <= 15) and (i >= 3) and (i <= 9)){
            std::cout << "?";
        }
        else{
            std::cout << gridRow.at(i);
        }
    }
}

void BlindDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool BlindDecorator::getPlayerId(){
    return player->getPlayerId();
}

int BlindDecorator::getLevel(){
    return player->getLevel();
}

int BlindDecorator::getScore(){
    return player->getScore();
}

char BlindDecorator::getNextBlock(){
    return player->getNextBlock();
}

void BlindDecorator::setNextBlock(){
    player->setNextBlock();
}

void BlindDecorator::moveLeft(int times){
    player->moveLeft(times);
}

void BlindDecorator::moveRight(int times){
    player->moveRight(times);
}

bool BlindDecorator::moveDown(int times){
    return player->moveDown(times);
}

void BlindDecorator::rotate(std::string direction, int times){
    player->rotate(direction, times);
}

int BlindDecorator::drop(){
    return player->drop();
}

char BlindDecorator::getNextBlockChar() {
    return player->getNextBlockChar();
}

void BlindDecorator::levelUp(int times) {
    return player->levelUp(times);
}

void BlindDecorator::levelDown(int times) {
    return player->levelDown(times);
}

void BlindDecorator::noRandom(std::string sequencefile) {
    return player->noRandom(sequencefile);
}

void BlindDecorator::random() {
    return player->random();
}

void BlindDecorator::replaceBlock(char c){
    return player->replaceBlock(c);
};