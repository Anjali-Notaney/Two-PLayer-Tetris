#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "vector"
#include "GridCell.h"
class Grid{
    std::vector<std::vector<GridCell>> cells;
    // xWindow* window;
    
    const int width, height; // for now be constant since there should
    						 // be no resizing of grids
    public:
    Grid(int width=11, int height=18);
    std::vector<GridCell>* getRow(int i);
    int getWidth();
    int getHeight();
    void setGridCell(int x, int y, GridCell& cell);
    GridCell* getGridCell(int x, int y);
    // io
    friend std::ostream& operator<<(std::ostream& out, Grid& grid);
};
#endif

