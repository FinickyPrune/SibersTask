#include "ConsoleView.h"

ConsoleView::ConsoleView(Model* m)
{
	_model = m;
}

void ConsoleView::printInfo()
{
	system("cls");

	if (!(_model->getCheck()))
	{
		roomInfo();
	}
	else
	{
		if (_model->getCharacter()->getWin())
		{
			winMessage();
		}
		else if (_model->getCharacter()->getFail())
		{
			failMessage();
		}
	}
	
}

void ConsoleView::printStartInfo()
{
	std::cout << "Hello! Ready to explore?" << std::endl;
	std::cout << "Enter maze sizes ([x_size] [y_size]): ";
}

void ConsoleView::darkRoomMessage()
{
	std::cout << "Can't see anything in this dark place!" << std::endl;
}

void ConsoleView::winMessage()
{
	std::cout << "Congrats! You've got the Holy Grail!" << std::endl;
}

void ConsoleView::failMessage()
{
	std::cout << "Oh no! You failed..." << std::endl;
}

void ConsoleView::roomInfo()
{
	if (_model->getCharacter()->getSight() == true)
	{
		Room currRoom = *_model->getCharacter()->getRoom();

		std::cout << "You are in the room [";
		std::cout << currRoom.getCords().x << ", " << currRoom.getCords().y << "]. ";
		std::cout << "There are " << currRoom.getOpenDoors() << " doors: ";

		if (currRoom.getDoors()['E'])
		{
			std::cout << "E ";
		}
		if (currRoom.getDoors()['W'])
		{
			std::cout << "W ";
		}
		if (currRoom.getDoors()['S'])
		{
			std::cout << "S ";
		}
		if (currRoom.getDoors()['N'])
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
	else
	{
		darkRoomMessage();
	}
	
}
