#include "Model.h"

Model::~Model()
{
	delete _maze;
	delete _character;
}

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
	//check if monster in the room
	//if (yes) 
	//{
	//5 sec

	if (_character->getRoom()->isMonsterinRoom() == true)
	{
		Timer timer;

		timer.add(std::chrono::milliseconds(6000), monsterAttack, true);
	}

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

void Model::monsterAttack()
{

}


