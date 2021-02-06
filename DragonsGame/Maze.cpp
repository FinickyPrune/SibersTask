#include "Maze.h"

Maze::Maze(size_t x, size_t y)
{
	_XSize = x;
	_YSize = y;

	_field = new Room*[_XSize];

	for (size_t i = 0; i < _XSize; i++)
	{	
		_field[i] = new Room[_YSize];

		for (size_t j = 0; j < _YSize; j++)
		{
			_field[i][j].setCords({ i,j });
		}
	}

	mazeGeneration();
	generateItems();

}

Maze::~Maze()
{
	for (size_t i = 0; i < _XSize; i++)
	{
		delete[] _field[i];
	}

	delete[] _field;
}

void Maze::mazeGeneration()
{

	//TREE ALGORYTHM FOR MAZE GENERATION

	bool** visited = new bool* [_XSize];

	for (size_t i = 0; i < _XSize; i++)
	{
		visited[i] = new bool[_YSize];

		for (size_t j = 0; j < _YSize; j++)
		{
			visited[i][j] = false;
		}
	}

	size_t startX = rand() % _XSize; //CHOOSE START POINT
	size_t startY = rand() % _YSize;

	visited[startX][startY] = true; //MARK AS VISITED

	std::stack<Room> path;
	path.push(_field[startX][startY]); //ADD ON STACK

	while (!path.empty())
	{
		_minSteps += 1;

		Room room = path.top(); //WHILE PATH IS NOT EMPTY CHOOSE TOP ROOM

		Cords roomCords = room.getCords();

		std::vector<Room> nextStep; // ADD TO NEXTSTEP ALL NEARBY NOT VISITED ROOMS

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
			Room next = nextStep[rand() % nextStep.size()]; //CHOOSE RANDOM ROOM FROM NEXTSTEP

			Cords nextCords = next.getCords();

			if (nextCords.x != roomCords.x) //AND OPEN DOOR BETWEEN CURRENT AND CHOSEN ROOM
			{
				if (roomCords.x > nextCords.x)
				{
					_field[roomCords.x][roomCords.y].setDoor('W');
					_field[nextCords.x][nextCords.y].setDoor('E');

					_field[roomCords.x][roomCords.y].addOpenDoor();
					_field[nextCords.x][nextCords.y].addOpenDoor();
				}

				else
				{
					_field[roomCords.x][roomCords.y].setDoor('E');
					_field[nextCords.x][nextCords.y].setDoor('W');

					_field[roomCords.x][roomCords.y].addOpenDoor();
					_field[nextCords.x][nextCords.y].addOpenDoor();
				}
			}

			if (nextCords.y != roomCords.y)
			{
				if (roomCords.y > nextCords.y)
				{
					_field[roomCords.x][roomCords.y].setDoor('S');
					_field[nextCords.x][nextCords.y].setDoor('N');

					_field[roomCords.x][roomCords.y].addOpenDoor();
					_field[nextCords.x][nextCords.y].addOpenDoor();
				}

				else
				{
					_field[roomCords.x][roomCords.y].setDoor('N');
					_field[nextCords.x][nextCords.y].setDoor('S');

					_field[roomCords.x][roomCords.y].addOpenDoor();
					_field[nextCords.x][nextCords.y].addOpenDoor();
				}
			}

			visited[nextCords.x][nextCords.y] = true; //MARK ROOM AS VISITED
			path.push(next); // AND ADD IT ON STACK
		}

		else
		{
			path.pop(); //IF ROOM HAS NO NOT VISITED NEARBY ROOMS
		}
	}

	for (size_t i = 0; i < _XSize; i++)
	{
		delete[] visited[i];
	}

	delete[] visited;
}

void Maze::generateItems()
{
	_field[rand() % _XSize][rand() % _YSize].setItem("CHEST", 1);
	_field[rand() % _XSize][rand() % _YSize].setItem("KEY", 1);
	_field[rand() % _XSize][rand() % _YSize].setItem("SWORD", 1);	
	_field[rand() % _XSize][rand() % _YSize].setMonster(true);
	
	for (size_t i = 0; i < static_cast<size_t>(_XSize*_YSize/4); i++)
	{
		_field[rand() % _XSize][rand() % _YSize].setItem("TORCH",1);
		_field[rand() % _XSize][rand() % _YSize].setDarkRoom();
		_field[rand() % _XSize][rand() % _YSize].setItem("FOOD", 1);		
		_field[rand() % _XSize][rand() % _YSize].setItem("GOLD", rand()%10);
	}
}
