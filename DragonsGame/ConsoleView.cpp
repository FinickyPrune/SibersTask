#include "ConsoleView.h"

ConsoleView::ConsoleView(Model* m)
{
	_model = m;
}

void ConsoleView::printInfo()
{
	system("cls");

	if (!(_model->getCheck()))  //IF NOT THE END OF GAME
	{
		roomInfo();
	}
	else
	{
		if (_model->getCharacter()->getWin()) //IF WIN
		{
			winMessage();
		}
		else if (_model->getCharacter()->getFail()) //IF FAIL 
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

void ConsoleView::printStepLimitInfo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));

	size_t stepLimit = _model->getCharacter()->getStepLimit();

	std::cout << "Your step limit for this game: " << stepLimit << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
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

void ConsoleView::MonsterMessage()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Red));

	std::cout << std::endl << "There is an evil TROLL in the room!" << std::endl;

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
}

void ConsoleView::RoomStatsMessage()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
	
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

void ConsoleView::roomInfo()
{
	
	if (_model->getCharacter()->getSight() == true) //IF CAN SEE IN THE ROOM
	{
		RoomStatsMessage();

		if (_model->getCharacter()->getRoom()->isMonsterInRoom() == true) //IF MONSTER IN THE ROOM
		{
			MonsterMessage();
		}
	}
	else //IF DARK ROOM
	{
		darkRoomMessage();
	}
	
}
