#pragma once
#include "Room.h"
#include <time.h>
#include <stack>
#include <vector>
class Maze
{
private:
	size_t _XSize = 0;
	size_t _YSize = 0;
	Room** _field = nullptr;
	size_t _minSteps = 0;

public:

	Maze(size_t, size_t);
	virtual ~Maze();

	size_t getYSize()  const { return _YSize; }
	size_t getXSize()  const { return _XSize; }
	Room** getField() { return _field; }
	size_t getMinSteps() const { return _minSteps; }

	void mazeGeneration();

	void generateItems();

};
