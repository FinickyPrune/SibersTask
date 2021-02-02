#include "Model.h"

void Model::generateMaze(Cords c)
{
	_maze = new Maze(c.x, c.y);
}

void Model::spawnCharacter()
{
	_character = new DefaultCharacter(&(_maze->getField()[rand() % _maze->getXSize()][rand() % _maze->getYSize()]), _maze->getMinSteps());
}


