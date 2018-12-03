#include <iostream>
#include <utility>
#include <stdexcept>
#include "ForceDecorator.h"

ForceDecorator::ForceDecorator(Player *component, char type): player{component}, blockType{type}{}

ForceDecorator::~ForceDecorator(){
    delete player;
}

Player* ForceDecorator::getBasePlayer(){
    Player *tmp = player->getBasePlayer();
    if (tmp != player){
        delete player;
    }
    return tmp;
}

std::vector<GridCell>* ForceDecorator::getRow(int rowNum){
    return player->getRow(rowNum);
}

bool ForceDecorator::isHeavyLevel(){
    return player->isHeavyLevel();
}

void ForceDecorator::setHeavyLevel(bool isHeavy){
    player->setHeavyLevel(isHeavy);
}

void ForceDecorator::printRow (int rowNum) {
    player->replaceBlock(blockType);
    player->printRow(rowNum);
}

void ForceDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool ForceDecorator::getPlayerId(){
    return player->getPlayerId();
}

int ForceDecorator::getLevel(){
    return player->getLevel();
}

int ForceDecorator::getScore(){
    return player->getScore();
}

char ForceDecorator::getNextBlock(){
    return player->getNextBlock();
}

void ForceDecorator::setNextBlock(){
    //player->setNextBlockChar(this->blockType);
    player->setNextBlock();
}

void ForceDecorator::setPlayerOneActive(){
    player->setPlayerOneActive();
}

void ForceDecorator::moveLeft(int times){
    player->moveLeft(times);
}

void ForceDecorator::moveRight(int times){
    player->moveRight(times);
}

bool ForceDecorator::moveDown(int times){
    return player->moveDown(times);
}

void ForceDecorator::rotate(std::string direction, int times){
    player->rotate(direction, times);
}

int ForceDecorator::drop(){
    return player->drop();
}

/*
void ForceDecorator::print(){
    player->print();
}
*/

char ForceDecorator::getNextBlockChar() {
    return player->getNextBlockChar();
}

void ForceDecorator::levelUp(int times) {
    player->levelUp(times);
}

void ForceDecorator::levelDown(int times) {
    player->levelDown(times);
}

void ForceDecorator::noRandom(std::string sequencefile) {
    player->noRandom(sequencefile);
}

void ForceDecorator::random() {
    player->random();
}

void ForceDecorator::replaceBlock(char c) {
    return player->replaceBlock(c);
};