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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));

	std::cout << "Hello! Ready to explore?" << std::endl;
	std::cout << "Enter maze sizes ([x_size] [y_size]): ";
}

void ConsoleView::darkRoomMessage()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));

	std::cout << "Can't see anything in this dark place!" << std::endl;
}

void ConsoleView::winMessage()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Green << 4) | Black));

	std::cout << "Congrats! You've got the Holy Grail!" << std::endl;
}

void ConsoleView::failMessage()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Red << 4) | Black));

	std::cout << "Oh no! You failed..." << std::endl;
}

void ConsoleView::roomInfo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));

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

		std::cout << ". Items in the room:" << std::endl << std::endl;

		auto items = currRoom.getItems();

		for (auto it = items.begin(); it != items.end(); it++)
		{
			if (it->first == "GOLD")
			{
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Yellow));

				std::cout << it->first << " : " << it->second << " COINS" << std::endl;

				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
			}
			
			else
			{
				std::cout << it->first << " : " << it->second << std::endl;
			}
		}
	}
	else
	{
		darkRoomMessage();
	}
	
}
