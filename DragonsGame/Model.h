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
//#include "Timer.h"

class Timer
{
public:
	Timer() = default;

	void add(std::chrono::milliseconds delay, std::function<void()> callback, bool asynchronous)
	{
		{
			if (asynchronous)
			{
				std::thread([=]()
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(delay));
						callback();
					}).detach();
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(delay));
				callback();
			}
		}
	}
};

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

	bool getExit() const { return  exit; }

	void setExit(bool value) { exit = value; }

	bool getCheck() { return _check; }

	void monsterAttack();
};

