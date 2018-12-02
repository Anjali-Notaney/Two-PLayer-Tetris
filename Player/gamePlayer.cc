#include "Player.h"
#include "gamePlayer.h"
#include "../Blocks/OBlock.h"
#include "../Blocks/JBlock.h"
#include "../Blocks/IBlock.h"
#include "../Blocks/SBlock.h"
#include "../Blocks/ZBlock.h"
#include "../Blocks/TBlock.h"
#include "../Blocks/LBlock.h"
#include "../Level/Level.h"
#include "../Level/Level0.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Level/Level3.h"
#include "../Level/Level4.h"
#include <sstream>
#include <string>


//GamePlayer::GamePlayer(xWindow &w){}
GamePlayer::GamePlayer(Grid* grid, Level *level, Xwindow* window):grid(grid), level(level), window(window){
  nextBlock = getNextBlock();
  this->displayBounds.first = std::make_pair(0, 0); // top left corner
  this->displayBounds.second = std::make_pair(250, 500); // bottom right corner
}

GamePlayer::~GamePlayer(){
  delete level;
  delete currBlock;
}

std::vector<GridCell>* GamePlayer::getRow(int rowNum){
  return grid->getRow(rowNum);
}

int GamePlayer::getLevel() {
  return level->getLevel();
}

int GamePlayer::getScore() {
  return score;
}

char GamePlayer::getNextBlock() {
  return level->getNextBlock();
}

void GamePlayer::setNextBlock() {
  switch (nextBlock)
  {
    case 'S':
      currBlock = new SBlock(grid);
      break;
    case 'Z':
      currBlock = new ZBlock(grid);
      break;
    case 'T':
      currBlock = new TBlock(grid);
      break;
    case 'L':
      currBlock = new LBlock(grid);
      break;
    case 'J':
      currBlock = new JBlock(grid);
      break;
    case 'O':
      currBlock = new OBlock(grid);
      break;
    case 'I':
      currBlock = new IBlock(grid);
      break;
  }
  nextBlock = getNextBlock();
}

void GamePlayer::moveLeft() {
  currBlock->moveLeft();
}

void GamePlayer::moveRight() {
  currBlock->moveRight();
}

void GamePlayer::moveDown() {
  currBlock->moveDown();
}

void GamePlayer::rotate(std::string direction){
  currBlock->rotate(direction);
}

void GamePlayer::drawXWindowBoard(){
  // Draw the level and the Score
  this->window->drawString(displayBounds.first.first, displayBounds.first.second + 
    (displayBounds.second.second - displayBounds.first.second)*0.05, (std::string)"Level: " + std::to_string(this->getLevel()));
  this->window->drawString(displayBounds.first.first, displayBounds.first.second + 
    (displayBounds.second.second - displayBounds.first.second)*0.1, (std::string)"Score: " + std::to_string(this->getScore()));

  // Draw the grid
  this->window->setFill("000000");
  this->window->fillRectangle(displayBounds.first.first, displayBounds.first.second + 
    (displayBounds.second.second - displayBounds.first.second)*0.15, displayBounds.second.first, displayBounds.second.second);

  // Draw the blocks
  for(int row = 0; row < this->grid->getHeight(); row++){
    for(int col = 0; col < this->grid->getWidth(); col++){
      GridCell* temp_cell = this->grid->getGridCell(col, row);
      if(temp_cell->isUsed){
        // int scaledHeight = (displayBounds.second.second - displayBounds.first.second)*0.15;
        this->window->setFill(Block::colours[temp_cell->getType()]);
        this->window->fillRectangle(displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)col/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)row/(float)this->grid->getHeight()),
          (displayBounds.second.first - displayBounds.first.first)*(1.0/(float)this->grid->getWidth()),
          (displayBounds.second.second - displayBounds.first.second)*(1.0/(float)this->grid->getHeight()));

        // stroke the edge of the blocks with white
        this->window->setFill("ffffff");
        // top
        this->window->drawLine(displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)col/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)row/(float)this->grid->getHeight()),
          displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)(col + 1)/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)row/(float)this->grid->getHeight()));

        // bottom
        this->window->drawLine(displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)col/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)(row + 1)/(float)this->grid->getHeight()),
          displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)(col + 1)/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)(row + 1)/(float)this->grid->getHeight()));

        // left side
        this->window->drawLine(displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)col/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)row/(float)this->grid->getHeight()),
          displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)(col)/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)(row + 1)/(float)this->grid->getHeight()));

        // right side
        this->window->drawLine(displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)(col + 1)/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)row/(float)this->grid->getHeight()),
          displayBounds.first.first + (displayBounds.second.first - displayBounds.first.first)*((float)(col + 1)/(float)this->grid->getWidth()),
          displayBounds.first.second + (displayBounds.second.second - displayBounds.first.second)*((float)(row + 1)/(float)this->grid->getHeight()));
      }
    }
  }
}

//Harsh

//When a block is dropped, we go through all the rows of the grid.
//If the row is full then we loop through the row
//When we loop through the row we call drop(x,y) on every block in the grid
//Drop will check to see if the cell is in the block, if it is it will delete it
//Every cell will shift one block downwards

//isFull(std::vector<GridCell> vec) checks to see if all the cells in
// the given vector are used up
// @param std::vector<GridCell> vec: a row vector given to the grid
bool isFull(std::vector<GridCell>* vec){
  for(auto i: *vec){
      if(!i.isUsed){
          return false;
      }
  }
  return true;
}

//Shift all cells above rowCleared down by one
void GamePlayer::shiftCellsDown(int rowCleared){
  for(int y = rowCleared-1; y >= 3; y--){
    for(int x = 0; x < 11; x++){
      if(grid->getGridCell(x,y)->isUsed) {
        grid->getGridCell(x,y+1)->isUsed = true;
      } else {
        grid->getGridCell(x,y+1)->isUsed = false;
      }
      grid->getGridCell(x,y+1)->setType(grid->getGridCell(x,y)->getType());        
    }
  }

  //Set the block cells to one cell below the current
  // if they're above the cleared row
  for(auto i : blocksOnBoard){
    i->moveCellsDown(rowCleared);
  }
  
}

//If the block is empty (i.e has no cells) delete it
void GamePlayer::removeEmptyBlocks(){
  for(int i = 0; i < (int)blocksOnBoard.size(); i++){
    if(blocksOnBoard.at(i)->numCells() == 0){
      blocksOnBoard.erase(blocksOnBoard.begin() + i);
      i--;
    }
  }
}

int GamePlayer::drop() {
  while(currBlock->moveDown());
  blocksOnBoard.emplace_back(currBlock);
  int numRowsCleared = 0;
  //Go through each row
  for(int y = 17; y >=3; y--){
    //Check to see if the row is full
    
    if(isFull(grid->getRow(y))){
      //Go through every cell in the row
      
      std::vector<GridCell>* row = grid->getRow(y);
      for(int i = 0; i < 11; i++){

        //Go through every block on the board
        for(auto j: blocksOnBoard){
          //Call drop with the coordinates of the cell on the board
          //If the cell is in the block it will be removed from the block
          j->removeCellFromBlock(row->at(i).getX(), row->at(i).getY());
        }

        //Set each cell in the full row to false
        //Set the character to ' '
        row->at(i).isUsed = false;
        row->at(i).setType(' ');
      }
      
      //Remove any blocks that may have been emptied
      removeEmptyBlocks();

      //Move all cells above current row down one
      shiftCellsDown(y);

      //Increment numRowsCleared;
      numRowsCleared++;

      //Start from a row lower if the row you are on got cleared
      y++;
    }
  }
  //Add to the score
  if(numRowsCleared!= 0) score += level->getScore(numRowsCleared);
  
  //Return the num rows cleared
  return numRowsCleared;
}

void GamePlayer::printBlock(){
    switch (nextBlock)
  {
    case 'S':
      std::cout << " SS" << std::endl;
      std::cout << "SS " << std::endl;
      break;
    case 'Z':
      std::cout << "ZZ " << std::endl;
      std::cout << " ZZ" << std::endl;
      break;
    case 'T':
      std::cout << "TTT" << std::endl;
      std::cout << " T " << std::endl;
      break;
    case 'L':
      std::cout << "  L" << std::endl;
      std::cout << "LLL" << std::endl;
      break;
    case 'J':
      std::cout << "J  " << std::endl;
      std::cout << "JJJ" << std::endl;
      break;
    case 'O':
      std::cout << "OO" << std::endl;
      std::cout << "OO" << std::endl;
      break;
    case 'I':
      std::cout << "IIII" << std::endl;
      break;
  }
}

void GamePlayer::print(){
  std::cout << "Level:    " << getLevel() << std::endl;
  std::cout << "Score:    " << score << std::endl;
  std::cout << "-----------" << std::endl;
  for(int y = 0; y < 18; y++){
    for(int x = 0; x <11; x++){
      std::cout << *(grid->getGridCell(x,y));
    }
    std::cout << std::endl;
  }
  std::cout << "-----------" << std::endl;
  std::cout << "Next:" << std::endl;
  printBlock();
}

int main(){
  Grid *g = new Grid();
  Level *l = new Level0("sequence1.txt");
  Player *p = new GamePlayer(g,l);
  p->setNextBlock();
  p->getNextBlock();
  p->print();
  while(!std::cin.fail() || !std::cin.eof()){
    std::string s;
    std::cin >> s;
    if(s == "l"){
      p->moveLeft();
    } else if (s == "r"){
      p->moveRight();
    } else if (s == "do"){
      p->moveDown();
    } else if (s == "dr"){
      p->drop();
      p->setNextBlock();
    } else if (s == "rtc"){
      p->rotate("CW");
    } else if (s == "rtcw"){
      p->rotate("CCW");
    } else {
      break;
    }
    p->print();
  }
}