#include <iostream>
#include <utility>
#include <stdexcept>
#include "ForceDecorator.h"

ForceDecorator::ForceDecorator(Player *component, char type): player{component}, blockType{type}{}

ForceDecorator::~ForceDecorator(){
    delete player;
}

std::vector<GridCell>* ForceDecorator::getRow(int rowNum){
    return player->getRow(rowNum);
}

void ForceDecorator::printRow (int rowNum) {
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
    player->setNextBlockChar(this->blockType);
    player->setNextBlock();
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

int ForceDecorator::drop(int times){
    return player->drop(times);
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
    return levelUp(times);
}

void ForceDecorator::levelDown(int times) {
    return levelDown(times);
}

void ForceDecorator::noRandom(std::string sequencefile) {
    return noRandom(sequencefile);
}

void ForceDecorator::random() {
    return random();
}

void ForceDecorator::replaceBlock(char c) {
    return player->replaceBlock(c);
};