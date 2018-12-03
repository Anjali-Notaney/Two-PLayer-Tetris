#include <iostream>
#include <utility>
#include <stdexcept>
#include "BlindDecorator.h"
#include "../XWindow/XWindow.h"
#include <memory>
#include <cmath>

BlindDecorator::BlindDecorator(Player *component): player{component}{
    this->displayOffset = static_cast<GamePlayer*>(player)->getDisplayOffset();
}

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

void BlindDecorator::printRow (int rowNum, Xwindow* window) {
    std::vector<GridCell> gridRow = *(player->getRow(rowNum));
    for (int i = 0; i < player->getGridWidth(); i++){
        if ((rowNum >= 5) and (rowNum <= 14) and (i >= 2) and (i <= 8)){
            std::cout << "?";
        }
        else{
            std::cout << gridRow.at(i);
        }
    }

    // Xwindow graphics
    const int rows = 18;
    const int cols = 11;

    for (int i = 0; i < gridRow.size(); i++){
         if(rowNum >= 5 && rowNum <= 14 && i >= 2 && i <= 8){
            window->setFill("000000");
            window->fillRectangle(this->displayOffset + (window->getWidth()*(float)((float)i/(float)(cols * 3))), 
            (window->getHeight()*0.15) + ((window->getHeight()*0.85)*(float)((float)rowNum/(float)rows))
                ,ceil((window->getWidth()/3)/cols) + 1, ceil((window->getHeight()*0.85)/rows) + 1);

            window->drawString(this->displayOffset + (window->getWidth()*(float)((float)i/(float)(cols * 3))) + ceil((window->getWidth()/3)/cols)/2, 
            (window->getHeight()*0.15) + ((window->getHeight()*0.85)*(float)((float)rowNum/(float)rows)) + ceil((window->getHeight()*0.85)/rows)/2,
            "?");
        }else if(gridRow.at(i).isUsed){
            window->setFill(Block::colours[gridRow.at(i).getType()]);
            window->fillRectangle(this->displayOffset + (window->getWidth()*(float)((float)i/(float)(cols * 3))), 
            (window->getHeight()*0.15) + ((window->getHeight()*0.85)*(float)((float)rowNum/(float)rows))
                ,ceil((window->getWidth()/3)/cols) + 1, ceil((window->getHeight()*0.85)/rows) + 1);
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

void BlindDecorator::setDisplayOffset(int value){
    this->displayOffset = value;
}