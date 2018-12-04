#include "GridCell.h"

// constructors
GridCell::GridCell(int p_x, int p_y){
	this->x = p_x;
	this->y = p_y;
	this->cellChar = 'x'; //This is for testing, Block constructor will override this
	this->isUsed = false;
}

// destructors
GridCell::~GridCell(){
	// neighbours should be deleted by the Grid object to avoid double deletion
}

// methods

int GridCell::getX(){
	return this->x;
}

int GridCell::getY(){
	return this->y;
}

void GridCell::setX(int p_x){
	this->x = p_x;
}

void GridCell::setY(int p_y){
	this->y = p_y;
}

char GridCell::getType(){
	return this->cellChar;
}

void GridCell::setType(char c){
	this->cellChar = c;
}

void GridCell::setNeighbour(std::string position, GridCell* p_neighbour){
	std::pair<std::string, GridCell*> value(position, p_neighbour);
	(this->neighbours).emplace(value);
}

GridCell* GridCell::getNeighbour(std::string position){
	auto it = this->neighbours.find(position);
	try{
		if(it == this->neighbours.end()){ // if the neighbour cannot be found
			std::string message = (std::string)("Cell for key ") + position + (std::string)(".");
			throw message;
		}
	}catch(std::string err){ 
		return nullptr;
	}
	return it->second;
}

// io operators

std::ostream& operator<<(std::ostream& out, GridCell& cell){
	if(cell.isUsed){
		out << cell.cellChar;
	} else {
		out << " ";
	}
	return out;
}

