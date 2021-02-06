#include "Controller.h"


ICommand* Controller::parseCommand(Model* model, bool flag)
{
	ICommand* currCommand = nullptr;

	std::string word = getWord();

	if (word == "E" || word == "W" || word == "S" || word == "N")
	{
		currCommand = new MoveCommand(word[0]);
	}

	else if (word == "GET")
	{
		currCommand = new GetCommand(getWord());
	}
	else if (word == "DROP")
	{
		currCommand = new DropCommand(getWord());
	}
	else if (word == "OPEN")
	{
		currCommand = new OpenCommand();
	}
	else if (word == "EAT")
	{
		currCommand = new EatCommand();
	}
	else if (word == "FIGHT")
	{
		currCommand = new FightCommand();
	}


	return currCommand; //COMMAND GOES TO MODEL
}

std::string Controller::getWord()
{
	std::string word;
	std::cin >> word;
	transform(word.begin(), word.end(), word.begin(), toupper); // NO MATTER WHAT PLAYER USES: UPPER OR LOWERCASE
	return word;
}

size_t Controller::getNumber()
{
	size_t number;
	std::cin >> number;
	return number;
}

char Controller::getChar()
{
	char dir;
	std::cin >> dir;
	return dir;
}

Cords Controller::getMazeSizes()
{
	size_t x, y;

	x = getNumber();
	y = getNumber();

	return { x,y };
}
