#include <iostream>
#include <utility>
#include <stdexcept>
#include "LevelDecorator.h"

LevelDecorator::LevelDecorator(Player *component): player{component}{}

LevelDecorator::~LevelDecorator(){
     delete player;
}

Player* LevelDecorator::getBasePlayer(){
    Player *tmp = player->getBasePlayer();
    if (tmp != player){
        delete player;
    }
    return tmp;
}

std::vector<GridCell>* LevelDecorator::getRow(int rowNum){
     return player->getRow(rowNum);
}

bool LevelDecorator::getPlayerId(){
    return player->getPlayerId();
}

int LevelDecorator::getLevel(){
    return player->getLevel();
}

int LevelDecorator::getScore(){
    return player->getScore();
}

char LevelDecorator::getNextBlock(){
    return player->getNextBlock();
}

void LevelDecorator::setNextBlock(){
    player->setNextBlock();
}

void LevelDecorator::moveLeft(int times){
    player->moveLeft(times);
    if (player->getPlayerId() == player->isPlayerOnePlaying()){
        if (!player->moveDown(1)){
            player->drop(1);
            //playerOnePlaying = (!playerOnePlaying);
            return;
        }
    }
}

void LevelDecorator::moveRight(int times){
    player->moveRight(times);
    if (player->getPlayerId() == player->isPlayerOnePlaying()){
        if (!player->moveDown(1)){
            player->drop(1);
            //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
            return;
        }
    }
}

void LevelDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool LevelDecorator::moveDown(int times){
    //bool lastMove = player->moveDown();
    player->moveDown(times);
    if (!player->moveDown(1)){
        player->drop(1);
            return false;
    }
    return true;
}


void LevelDecorator::rotate(std::string direction, int times){
    player->rotate(direction, times);
    if (!player->moveDown(1)){
        player->drop(1);
        //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
        return;
    }
}

void LevelDecorator::printRow (int rowNum) {
    player->printRow(rowNum);
}

int LevelDecorator::drop(int times){
    return player->drop(times);
}

/*
void LevelDecorator::print(){
    player->print();
}
*/

char LevelDecorator::getNextBlockChar() {
    return player->getNextBlockChar();
}

void LevelDecorator::levelUp(int times) {
    return levelUp(times);
}

void LevelDecorator::levelDown(int times) {
    return levelDown(times);
}

void LevelDecorator::noRandom(std::string sequencefile) {
    return noRandom(sequencefile);
}

void LevelDecorator::random() {
    return random();
}

void LevelDecorator::replaceBlock(char c) {
    return player->replaceBlock(c);
};