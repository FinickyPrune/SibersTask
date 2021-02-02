#include "Maze.h"

Maze::Maze(size_t x, size_t y)
{
	_XSize = x;
	_YSize = y;

	_field = new Room*[_XSize];
	bool** visited = new bool*[_XSize];

	for (size_t i = 0; i < _XSize; i++)
	{	
		_field[i] = new Room[_YSize];
		visited[i] = new bool[_YSize];

		for (size_t j = 0; j < _YSize; j++)
		{
			_field[i][j].setCords({ i,j });
			visited[i][j] = false;
		}
	}

	//MAZE GENERATION

	size_t startX = rand() % _XSize;
	size_t startY = rand() % _YSize;

	visited[startX][startY] = true;

	std::stack<Room> path;
	path.push(_field[startX][startY]);

	while (!path.empty())
	{
		Room room = path.top();

		_minSteps += 1;

		Cords roomCords = room.getCords();

		std::vector<Room> nextStep;

		if (roomCords.x > 0 && (visited[roomCords.x - 1][roomCords.y] == false))
		{
			nextStep.push_back(_field[roomCords.x - 1][roomCords.y]);
		}

		if (roomCords.x < _XSize - 1 && (visited[roomCords.x + 1][roomCords.y] == false))
		{
			nextStep.push_back(_field[roomCords.x + 1][roomCords.y]);
		}

		if (roomCords.y > 0 && (visited[roomCords.x][roomCords.y - 1] == false))
		{
			nextStep.push_back(_field[roomCords.x][roomCords.y - 1]);
		}

		if (roomCords.y < _YSize - 1 && (visited[roomCords.x][roomCords.y + 1] == false))
		{
			nextStep.push_back(_field[roomCords.x][roomCords.y + 1]);
		}

		if (!nextStep.empty())
		{
			Room next = nextStep[rand() % nextStep.size()];

			Cords nextCords = next.getCords();

			if (nextCords.x != roomCords.x)
			{
				if (roomCords.x > nextCords.x)
				{
					_field[roomCords.x][roomCords.y].setDoorW(true);
					_field[nextCords.x][nextCords.y].setDoorE(true);
				}

				else
				{
					_field[roomCords.x][roomCords.y].setDoorE(true);
					_field[nextCords.x][nextCords.y].setDoorW(true);
				}
			}

			if (nextCords.y != roomCords.y)
			{
				if (roomCords.y > nextCords.y)
				{
					_field[roomCords.x][roomCords.y].setDoorS(true);
					_field[nextCords.x][nextCords.y].setDoorN(true);
				}

				else
				{
					_field[roomCords.x][roomCords.y].setDoorN(true);
					_field[nextCords.x][nextCords.y].setDoorS(true);
				}
			}

			visited[nextCords.x][nextCords.y] = true;
			path.push(next);
		}

		else
		{
			path.pop();
		}
	}

	for (size_t i = 0; i < _XSize; i++)
	{
		delete[] visited[i];
	}

	delete[] visited;

	//SET ITEMS

	_field[rand() % _XSize][rand() % _YSize].setChest();
	_field[rand() % _XSize][rand() % _YSize].setKey();
}

Maze::~Maze()
{
	for (size_t i = 0; i < _XSize; i++)
	{
		delete[] _field[i];
	}

	delete[] _field;
}
