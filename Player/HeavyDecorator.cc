#include <iostream>
#include <utility>
#include <stdexcept>
#include "HeavyDecorator.h"

HeavyDecorator::HeavyDecorator(Player *component): player{component}{}

HeavyDecorator::~HeavyDecorator(){
     delete player;
}

Player* HeavyDecorator::getBasePlayer(){
    Player *tmp = player->getBasePlayer();
    if (tmp != player){
        delete player;
    }
    return tmp;
}

bool HeavyDecorator::isHeavyLevel(){
    return player->isHeavyLevel();
}

void HeavyDecorator::setHeavyLevel(bool isHeavy){
    player->setHeavyLevel(isHeavy);
}

std::vector<GridCell>* HeavyDecorator::getRow(int rowNum){
     return player->getRow(rowNum);
}


void HeavyDecorator::printRow (int rowNum) {
    player->printRow(rowNum);
}

bool HeavyDecorator::getPlayerId(){
    return player->getPlayerId();
}

int HeavyDecorator::getLevel(){
    return player->getLevel();
}

int HeavyDecorator::getScore(){
    return player->getScore();
}

char HeavyDecorator::getNextBlock(){
    return player->getNextBlock();
}

void HeavyDecorator::setNextBlock(){
    player->setNextBlock();
}

void HeavyDecorator::moveLeft(int times){
    player->moveLeft(times);
    if (player->getPlayerId() == player->isPlayerOnePlaying()){
        for (int i = 0; i < 2; i++){
            if (!player->moveDown(1)){
                player->drop();
                //playerOnePlaying = (!playerOnePlaying);
                return;
            }
        }
    }
}

void HeavyDecorator::moveRight(int times){
    player->moveRight(times);
    //std::cout << "at 1." << std::endl;
    if (player->getPlayerId() == player->isPlayerOnePlaying()){
      //  std::cout << "at 2." << std::endl;
        for (int i = 0; i < 2; i++){
        //    std::cout << "at 3." << std::endl;
            if (!player->moveDown(1)){
          //      std::cout << "dropping" << std::endl;
                player->drop();
                //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
                return;
            }
        }
    }
}

void HeavyDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool HeavyDecorator::moveDown(int times){
    return player->moveDown(times);
}

void HeavyDecorator::rotate(std::string direction, int times){
    player->rotate(direction, times);
}

int HeavyDecorator::drop(){
    return player->drop();
}

/*
void HeavyDecorator::print(){
    player->print();
}
*/

char HeavyDecorator::getNextBlockChar() {
    return player->getNextBlockChar();
}

void HeavyDecorator::levelUp(int times) {
    return player->levelUp(times);
}

void HeavyDecorator::levelDown(int times) {
    return player->levelDown(times);
}

void HeavyDecorator::noRandom(std::string sequencefile) {
    return player->noRandom(sequencefile);
}

void HeavyDecorator::random() {
    return player->random();
}

void HeavyDecorator::replaceBlock(char c) {
    return player->replaceBlock(c);
};