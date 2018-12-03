#include "OBlock.h"
#include <vector>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

OBlock::OBlock(Grid *g, int generatedLevel): Block(g, 'O',generatedLevel){
    std::vector<GridCell*> tmp;
    tmp.emplace_back(g->getGridCell(0,2));
    tmp.emplace_back(g->getGridCell(0,3));
    tmp.emplace_back(g->getGridCell(1,2));
    tmp.emplace_back(g->getGridCell(1,3));
    for (auto i : tmp){
        if (i->isUsed){
            throw std::exception();
        }
    }
    blockCells = tmp;
    setUpBlock();
}

OBlock::~OBlock(){}