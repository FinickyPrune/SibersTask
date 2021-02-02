#pragma once
#include "Maze.h"
#include "DefaultCharacter.h"
#include "DropCommand.h"
#include "GetCommand.h"
#include "MoveCommand.h"

class Model
{
private:

	Maze* _maze = nullptr;
	ICharacter* _character = nullptr;
	ICommand* _currCommand = nullptr;
	bool exit = false;

public:

	Model(size_t, size_t);
	virtual ~Model();

	Maze* getMaze() { return _maze; }
	ICharacter* getCharacter() { return _character; }

	ICommand* getCurrCommand() const { return _currCommand; }
	void setCurrCommand(ICommand* ptr) { _currCommand = ptr; }

	void executeStep();

	void spawnCharacter();

	bool getExit() const { return  exit; }

	void setExit(bool value) { exit = value; }
};

