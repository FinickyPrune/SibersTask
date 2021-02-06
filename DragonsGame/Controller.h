#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "Model.h"

class Controller
{

public:
	Controller() = default;
	
	virtual ~Controller() = default;

	ICommand* parseCommand(Model* model, bool flag);

	std::string getWord();

	size_t getNumber();

	char getChar();

	Cords getMazeSizes();

};

