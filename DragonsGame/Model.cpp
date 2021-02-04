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
	if (_character->getRoom()->isMonsterInRoom() == true && _currCommand != nullptr)
	{
		_character->setReaction(true);

		size_t chance = rand() % 3;

		switch (chance)
		{
		case 0:
		{
			executeCommand();
			break;
		}
		case 1:
		{
			_character->setStepLimit(static_cast<size_t>(_character->getStepLimit() * 0.9));
			executeCommand();

			break;
		}
		case 2:
		{
			_character->setStepLimit(static_cast<size_t>(_character->getStepLimit() * 0.9));
			_character->move(_character->getLastDoor());

			break;
		}
		default:
			break;
		}


	}

	if (_currCommand != nullptr)
	{
		executeCommand();
	}

	_check = (_character->getWin() || _character->getFail());
	
	updateRoom();

	if (_character->getRoom()->isMonsterInRoom() == true)
	{

		delayMonsterAttack(std::chrono::milliseconds(5000));		
	}
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
	if (_character->getReaction() == false)
	{
		_character->setStepLimit(static_cast<size_t>(_character->getStepLimit() * 0.9));
		_character->move(_character->getLastDoor());
	}
}

void Model::delayMonsterAttack(std::chrono::milliseconds delay)
{
	std::thread([=]()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			std::cout << "Time is up";
			monsterAttack();
			_character->setReaction(false);

		}).detach();
		
}

void Model::executeCommand()
{
	_currCommand->execute(_character);
	delete _currCommand;
	_currCommand = nullptr;
}


