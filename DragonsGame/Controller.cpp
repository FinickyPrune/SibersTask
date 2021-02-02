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
		word = getWord();
	}
	else if (word == "DROP")
	{
		word = getWord();
	}

	return currCommand;
}

const std::string Controller::getWord()
{
	std::string word;
	std::cin >> word;
	transform(word.begin(), word.end(), word.begin(), toupper);
	return word;
}

const size_t Controller::getNumber()
{
	size_t number;
	std::cin >> number;
	return number;
}

const char Controller::getChar()
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
