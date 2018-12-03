#include "Grid.h"
// Constructors
/* Currently, the position strings can be top, right, left, bottom
   top-right, top-left, bottom-right and bottom-left*/
Grid::Grid(int p_width, int p_height): width{p_width}, height{p_height}{
	for(int h = 0; h < p_height; h++){
		std::vector<GridCell> grid_row; // creates a row
		for(int w = 0; w < p_width; w++){
			grid_row.emplace_back(GridCell(w, h)); // places the new GridCells in the row
		}
		this->cells.emplace_back(grid_row);
	}
	// Loop through again to set neighbours
	// Must be done on the second run because previous grid cells may have
	// been reallocated to new spaces in memory
	for(int h = 0; h < p_height; h++){
		std::vector<GridCell> grid_row; // creates a row
		for(int w = 0; w < p_width; w++){
			if(w > 0){ // set left cell
				this->cells.at(h).at(w).setNeighbour("left", &(this->cells.at(h).at(w - 1)));
				this->cells.at(h).at(w - 1).setNeighbour("right", &(this->cells.at(h).at(w)));
			}
			if(h > 0 && w > 0){// set top-left cell
				this->cells.at(h).at(w).setNeighbour("top-left", &(this->cells.at(h - 1).at(w - 1)));
				this->cells.at(h - 1).at(w - 1).setNeighbour("bottom-right", &(this->cells.at(h).at(w)));
			}
			if(h > 0){// set top cell
				this->cells.at(h).at(w).setNeighbour("top", &(this->cells.at(h - 1).at(w)));
				this->cells.at(h - 1).at(w).setNeighbour("bottom", &(this->cells.at(h).at(w)));
			}
			if(h > 0 && w < p_width - 1){// set top-right cell
				this->cells.at(h).at(w).setNeighbour("top-right", &(this->cells.at(h - 1).at(w + 1)));
				this->cells.at(h - 1).at(w + 1).setNeighbour("bottom-left", &(this->cells.at(h).at(w)));
			}
		}
	}
}
// Methods
std::vector<GridCell>* Grid::getRow(int i){
	return &cells.at(i);
}
int Grid::getWidth(){
	return this->width;
}
int Grid::getHeight(){
	return this->height;
}
void Grid::setGridCell(int x, int y, GridCell& cell){
	try{
		if((x < 0 || x > this->width) || (y < 0 || y > this->height)){
			throw;
		}
		this->cells.at(x).at(y) = cell;
	}catch(...){
		// error handling for if x and/or y is an invalid value
	}
}
GridCell* Grid::getGridCell(int x, int y){
	return &(cells.at(y).at(x));
}
// io
std::ostream& operator<<(std::ostream& out, Grid& grid){
	for(int i = 0; i < grid.getHeight() - 1; i++){
		for(int j = 0; j < grid.getWidth() - 1; j++){
			std::vector<GridCell>* temp = grid.getRow(i);
			std::cout << temp->at(j);
		}
		std::cout << std::endl;
	}
	return out;
}