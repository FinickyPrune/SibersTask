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
	Room* room = &(_maze->getField()[rand() % _maze->getXSize()][rand() % _maze->getYSize()]);

	while (room->isMonsterInRoom())
	{
		room = &(_maze->getField()[rand() % _maze->getXSize()][rand() % _maze->getYSize()]);
	}
	
	_character = new DefaultCharacter(room, _maze->getMinSteps());
}

void Model::executeCommand()
{
	_currCommand->execute(_character);
	delete _currCommand;
	_currCommand = nullptr;
}

void Model::updateRoom() //MODEL GIVES CHARACTER ROOM POINTER
{
	Cords charCords = _character->getCords();
	Cords roomCords = _character->getRoom()->getCords();

	if (charCords.x != roomCords.x || charCords.y != roomCords.y)
	{
		Room* newRoom = &_maze->getField()[charCords.x][charCords.y];
		_character->setRoom(newRoom);
	}
}

void Model::randomPlot()
{
	_character->setReaction(true);

	size_t chance = rand() % 3;

	switch (chance = 0)
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

void Model::monsterAttack()
{
	if (_character->getReaction() == false)
	{
		_character->setStepLimit(static_cast<size_t>(_character->getStepLimit() * 0.9)); //DAMAGE CHARACTER
		_character->move(_character->getLastDoor()); //THROWS CHARACTER TO PREVIOUS ROOM
	}
}

void Model::delayMonsterAttack(std::chrono::milliseconds delay) //MONSTER WAITS IN A NEW THREAD
{
	std::thread([=]()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			monsterAttack();
			_character->setReaction(false);
			updateRoom();


		}).detach();

}

void Model::executeStep()
{
	if ((_character->getRoom()->isMonsterInRoom() == true &&_character->getSight()) && _currCommand != nullptr) //IF MONSTER IN THE ROOM AND PLAYER REACTED
	{                                                                                                           //MONSTER "SLEEPS" IF PLAYER CAN'T SEE IT
		randomPlot();
	}

	if (_currCommand != nullptr) //DEFAULT EXECUTION
	{
		executeCommand();
	}

	_check = (_character->getWin() || _character->getFail()); //CHECK IF GAME ENDS
	
	updateRoom(); //IN CASE PLAYER MOVED

	if (_character->getRoom()->isMonsterInRoom() == true && _character->getSight()) //IF MONSTER IN THE ROOM
	{
		delayMonsterAttack(std::chrono::milliseconds(5000)); //MONSTER WAITS FOR PLAYER REACTION
	}
}



