#include "ConsoleView.h"

ConsoleView::ConsoleView(Model* m)
{
	_model = m;
}

void ConsoleView::printInfo()
{
	Room currRoom = *_model->getCharacter()->getRoom();

	std::cout << "You are in the room [";
	std::cout << currRoom.getCords().x << ", " << currRoom.getCords().y << "]";

}

void ConsoleView::printStartInfo()
{
	std::cout << "Hello!" << std::endl;
	std::cout << "Enter maze sizes ([x_size] [y_size]): ";
}
