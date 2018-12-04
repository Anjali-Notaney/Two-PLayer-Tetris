#ifndef __GRIDCELL_H__
#define __GRIDCELL_H__

#include <iostream>
#include "vector"
#include "GridCell.h"
#include <map>
#include "string.h"

class GridCell{
    std::map<std::string, GridCell*> neighbours;
    int x,y;
    char cellChar;
public:
	bool isUsed;

	// constructors and destructor
	GridCell(int p_x, int p_y);
	~GridCell();
	// methods
	int getX();
	int getY();
	void setX(int p_x);
	void setY(int p_y);
	char getType();
	void setType(char c);
	void setNeighbour(std::string position, GridCell* cell);
	GridCell* getNeighbour(std::string position);

	// io
	friend std::ostream& operator<<(std::ostream& out, GridCell& cell);
};

#endif
