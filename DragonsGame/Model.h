#pragma once
#include <chrono>
#include <functional>
#include <thread>
#include <iostream>
#include "Maze.h"
#include "DefaultCharacter.h"
#include "Commands.h"

class Model
{
private:

	Maze* _maze = nullptr;
	ICharacter* _character = nullptr;
	ICommand* _currCommand = nullptr;
	
	bool exit = false;
	bool _check = false;

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

	void setNeedCommand(bool value) { exit = value; }

	bool getCheck()  const { return _check; }

	void monsterAttack();

	void delayMonsterAttack(std::chrono::milliseconds delay);

	void executeCommand();

	void randomPlot();
};

