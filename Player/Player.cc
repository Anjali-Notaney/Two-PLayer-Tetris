#include "Player.h"

Player::Player(Grid* grid, Level *level, bool id):grid{grid}, level{level}, playerId{id}{} 

Player::Player(){}

Player::~Player(){}

int Player::getGridWidth(){
    return this->grid->getWidth();
}

int Player::getGridHeight(){
    return this->grid->getHeight();
}

bool Player::playerOnePlaying = true;

bool Player::isPlayerOnePlaying(){
    return playerOnePlaying; 
}


