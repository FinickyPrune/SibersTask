#pragma once
#include <chrono>
#include <functional>
#include <thread>
#include "Maze.h"
#include "DefaultCharacter.h"
#include "DropCommand.h"
#include "GetCommand.h"
#include "MoveCommand.h"
#include "OpenCommand.h"
#include "EatCommand.h"
#include "FightCommand.h"
#include <iostream>


class Model
{
private:

	Maze* _maze = nullptr;
	ICharacter* _character = nullptr;
	ICommand* _currCommand = nullptr;
	bool exit = false;
	bool _check = false;
	bool _needCommand = true;

public:

	Model() = default;
	virtual ~Model();

	void generateMaze(Cords);
	void spawnCharacter();

	Maze* getMaze() const { return _maze; }
	
	ICharacter* getCharacter() const { return _character; }

	ICommand* getCurrCommand() const { return _currCommand; }
	
	void setCurrCommand(ICommand* ptr) { _currCommand = ptr; }

	void executeStep();

	void updateRoom();

	bool getNeedCommand() const { return  _needCommand; }

	void setNeedCommand(bool value) { exit = value; }

	bool getCheck() { return _check; }

	void monsterAttack();

	void delayMonsterAttack(std::chrono::milliseconds delay);

	void executeCommand();
};

