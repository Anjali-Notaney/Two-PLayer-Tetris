#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>   
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
class Block {
    char type;
    std::vector<int> xCoords;
    std::vector<int> yCoords;
    std::pair<int, int> origBottomLeft;
    std::pair<int, int> topLeft;
    std::pair<int, int> newBottomLeft; 
    void shiftCoordinates (std::vector<int> &, int shift);

    protected:
    std::vector<GridCell*> blockCells;
    Grid *grid;
    int generatedLevel;

    public:
<<<<<<< HEAD
    static std::map <char, std::string> colours;
    Block(Grid* g, char type);
=======
    Block(Grid* g, char type, int generatedLevel);
>>>>>>> master
    virtual ~Block() = 0;
    void setUpBlock();
    bool moveLeft();  
    bool moveRight();
    bool moveDown();
    bool rotate(std::string direction);
    void removeCellFromBlock(int x, int y);
    void moveCellsDown(int rowCleared);
    int getGeneratedLevel();
    int numCells();
    void unsetBlock();
};
#endif