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

	const std::string getWord();

	const size_t getNumber();

	const char getChar();

	Cords getMazeSizes();

};

