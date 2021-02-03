#include "Model.h"

void Model::generateMaze(Cords c)
{
	_maze = new Maze(c.x, c.y);
}

void Model::spawnCharacter()
{
	_character = new DefaultCharacter(&(_maze->getField()[rand() % _maze->getXSize()][rand() % _maze->getYSize()]), _maze->getMinSteps());
}

void Model::executeStep()
{
	if (_currCommand != nullptr)
	{
		_currCommand->execute(_character);
		delete _currCommand;
	}

	_check = (_character->getWin() || _character->getFail());
	updateRoom();
}

void Model::updateRoom()
{
	Cords charCords = _character->getCords();
	Cords roomCords = _character->getRoom()->getCords();

	if (charCords.x != roomCords.x || charCords.y != roomCords.y)
	{
		Room* newRoom = &_maze->getField()[charCords.x][charCords.y];
		_character->setRoom(newRoom);
	}
}


