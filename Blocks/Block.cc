#include "Block.h"
#include <algorithm>

<<<<<<< HEAD
Block::Block(Grid* g, char c):type(c), grid(g){}
=======
Block::Block(Grid* g, char c, int generatedLevel):grid(g),type(c),generatedLevel(generatedLevel){}
>>>>>>> master

Block::~Block(){}

void Block::setUpBlock(){
    //Set the character type for all cells that this block occupies
    for(auto i: blockCells){
        i->setType(type);
        i->isUsed = true;
    }
}
//Struct that holds an operator to compare cell X values
struct CompareX {
  bool const operator()(GridCell* c1, GridCell* c2) {
      return (c1->getX()<c2->getX());
  } 
};
//Struct that holds an operator to compare cell Y values
struct CompareY {
  bool const operator()(GridCell* c1, GridCell* c2) {
      return (c1->getY()<c2->getY());
  } 
};
// Function that is responsible for moving the cell left
bool Block::moveLeft(){
  //We check to see that the block is not obstructed by a wall or a cell
  for(auto i: blockCells){
      if(i->getX() == 0 || i->getNeighbour("left")->isUsed){
          if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("left")) == blockCells.end()){
              return false;
          }
      }
  }
  //We sort the cells by their x values
  std::sort(blockCells.begin(), blockCells.end(), CompareX());
  char c = blockCells.at(0)->getType();
  //We go through the cells and change their pointers to new cells
  for(int i = 0; i < (int)blockCells.size(); i++){
      blockCells.at(i)->isUsed = false;
      blockCells.at(i)->setType(' ');
      blockCells.at(i) = blockCells.at(i)->getNeighbour("left");
      blockCells.at(i)->setType(c);
      blockCells.at(i)->isUsed = true;
  }
  return true;
}
// Function that is responsible for moving the cell right
bool Block::moveRight(){
  //We check to see that the block is not obstructed by a wall or a cell
  for(auto i: blockCells){
      if(i->getX() == 10 || i->getNeighbour("right")->isUsed){
          if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("right")) == blockCells.end()){
              return false;
          }
      }
  }
  //We sort the cells by their x values
  std::sort(blockCells.begin(), blockCells.end(), CompareX());
  char c = blockCells.at(0)->getType();
  //We go through the cells and change their pointers to new cells
  for(int i = blockCells.size()-1; i >= 0; i--){
      blockCells.at(i)->isUsed = false;
      blockCells.at(i)->setType(' ');
      blockCells.at(i) = blockCells.at(i)->getNeighbour("right");
      blockCells.at(i)->setType(c);
      blockCells.at(i)->isUsed = true;
  }
  return true;
}
// Function that is responsible for moving the cell right
bool Block::moveDown(){
  //We check to see that the block is not obstructed by a wall or a cell
  for(auto i: blockCells){
      if(i->getY() == 17 || i->getNeighbour("bottom")->isUsed){
          if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("bottom")) == blockCells.end()){
              return false;
          }
      }
  }
  //We sort the cells by their y values
  std::sort(blockCells.begin(), blockCells.end(), CompareY());
  char c = blockCells.at(0)->getType();
  //We go through the cells and change their pointers to new cells
  for(int i = blockCells.size()-1; i >= 0; i--){
      blockCells.at(i)->isUsed = false;
      blockCells.at(i)->setType(' ');
      blockCells.at(i) = blockCells.at(i)->getNeighbour("bottom");
      blockCells.at(i)->setType(c);
      blockCells.at(i)->isUsed = true;
  }
  return true;
}
void Block::shiftCoordinates (std::vector<int> &vec, int shift){
  for (auto &i: vec){
      i += shift;
  }    
}
bool Block::rotate(std::string direction){
  //storing xCoordinates and yCoordinates of each blockCell
  //in xCoords and yCoords respectively
  for(auto i: blockCells){
      xCoords.emplace_back(i->getX());
      yCoords.emplace_back(i->getY());
  }
  //finding bottom left corner of the smallest rectangle containing the Block
  auto xMinMax = std::minmax_element(xCoords.begin(), xCoords.end());
  auto yMinMax = std::minmax_element(yCoords.begin(), yCoords.end());
  origBottomLeft.first = *xMinMax.first;
  origBottomLeft.second = *yMinMax.second;
  //finding the topLeft corner of the smallest rectangle containing the Block
  topLeft.first = *xMinMax.first;
  topLeft.second = *yMinMax.first;
  
  //Making top left corner the origin (0,0)
  shiftCoordinates (xCoords, -(topLeft.first));
  shiftCoordinates (yCoords, -(topLeft.second));
  
  //Transpose of the block:
  xCoords.swap(yCoords);
  //For clockwise rotation
  if (direction == "CW"){
      //Reflecting coordinates vertically to the right
      int xMax = *(std::max_element(std::begin(xCoords), std::end(xCoords))); 
      for(auto &i: xCoords){
          i += 2 * (xMax - i);
      }
  }
  //For counter-clockwise rotation
  else if (direction == "CCW"){
      //Reflecting coordinates horizontally downwards
      int yMax = *(std::max_element(std::begin(yCoords), std::end(yCoords))); 
      for(auto &i: yCoords){
          i += 2 * (yMax - i);
      }
  }
  //Re-adjusting xCoordinates back to the top left origin
  xMinMax = std::minmax_element(xCoords.begin(), xCoords.end());
  yMinMax = std::minmax_element(yCoords.begin(), yCoords.end());
  topLeft.first = *xMinMax.first;
  topLeft.second = *yMinMax.first;  
  shiftCoordinates (xCoords, -(topLeft.first));
  shiftCoordinates (yCoords, -(topLeft.second));
  //finding the new bottom left corner of the smallest recatangle containing the Block
  newBottomLeft.first = *(std::min_element(std::begin(xCoords), std::end(xCoords)));
  newBottomLeft.second = *(std::max_element(std::begin(yCoords), std::end(yCoords)));
  int xDiff = origBottomLeft.first - newBottomLeft.first;
  int yDiff = origBottomLeft.second - newBottomLeft.second;
  //Readjusting the coordinates to reflect the actual position on the grid
  shiftCoordinates (xCoords, xDiff);
  shiftCoordinates (yCoords, yDiff);
  
  //Now xCoords and yCoords have the new coordinates for the blockCells
  //If they are out of grid's bounds, then return without rotation
  xMinMax = std::minmax_element(xCoords.begin(), xCoords.end());
  yMinMax = std::minmax_element(yCoords.begin(), yCoords.end());
  if (((*xMinMax.first) < 0) or ((*yMinMax.first) < 0) or ((*xMinMax.second) >= grid->getWidth()) or ((*yMinMax.second) >= grid->getHeight())){
      return false;
  }
  //Checking if new coordinates are used by any other blocks
  int unUsedCells = 0; 
  for (int i = 0; i < 4; i++){
      if (!(grid->getGridCell(xCoords.at(i), yCoords.at(i))->isUsed)){
            unUsedCells++;
      }
      else if(std::find(blockCells.begin(), blockCells.end(), grid->getGridCell(xCoords.at(i), yCoords.at(i))) != blockCells.end()){
          unUsedCells++;
      }
  }
  
  //the new coordinates are avalaible, rotate the Block
  if (unUsedCells == 4){
      //make the current blockCells available
      for (auto i: blockCells){
          i->isUsed = false;
      }
      for(int i = 0; i < 4; i++){ 
          blockCells.at(i) = this->grid->getGridCell(xCoords.at(i), yCoords.at(i));
          blockCells.at(i)->setType(this->type);
          blockCells.at(i)->isUsed = true; 
      }
      return true;   
  }
  return false;
}
//Remove reference to cell in the blockCells vector
void Block::removeCellFromBlock(int x, int y){
    for(int i = 0; i < (int)blockCells.size(); i++){
        if(blockCells.at(i)->getX() == x && blockCells.at(i)->getY() == y){
            blockCells.erase(blockCells.begin() + i);
        }
    }
}
//Set each cell in the block to be its downwards neighbour
void Block::moveCellsDown(int rowCleared){
    for(int i = 0; i < (int)blockCells.size(); i++){
        if(blockCells.at(i)->getY() < rowCleared){
            blockCells.at(i) = blockCells.at(i)->getNeighbour("bottom");
        }
    }
}

//Get number of cells in the block
int Block::numCells(){
    return blockCells.size();
}

void Block::unsetBlock(){
    for(auto i: blockCells){
        i->isUsed = false;
        i->setType(' ');
    }   
}

int Block::getGeneratedLevel(){
    return generatedLevel;
}


