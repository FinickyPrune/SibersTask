#include "ConsoleView.h"

ConsoleView::ConsoleView(Model* m)
{
	_model = m;
}

void ConsoleView::printInfo()
{
	system("cls");

	Room currRoom = *_model->getCharacter()->getRoom();

	std::cout << "You are in the room [";
	std::cout << currRoom.getCords().x << ", " << currRoom.getCords().y << "]. ";
	std::cout << "There are " << currRoom.getOpenDoors() << " doors: ";

	if (currRoom.getDoors().E)
	{
		std::cout << "E ";
	}
	if (currRoom.getDoors().W)
	{
		std::cout << "W ";
	}
	if (currRoom.getDoors().S)
	{
		std::cout << "S ";
	}
	if (currRoom.getDoors().N)
	{
		std::cout << "N ";
	}

	std::cout << ". Items in the room:" << std::endl;

	auto items = currRoom.getItems();

	for (auto it = items.begin(); it != items.end(); it++)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
}

void ConsoleView::printStartInfo()
{
	std::cout << "Hello!" << std::endl;
	std::cout << "Enter maze sizes ([x_size] [y_size]): ";
}
