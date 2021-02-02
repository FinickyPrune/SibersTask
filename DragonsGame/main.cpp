#include "Model.h"
#include "Controller.h"
#include "ConsoleView.h"
#include <time.h>

int main()
{
	srand(time(nullptr));

	Model model = Model();
	ConsoleView console = ConsoleView(&model);
	Controller controller = Controller();

	console.printStartInfo();
	model.generateMaze(controller.getMazeSizes());
	model.spawnCharacter();

	while (true)
	{
		console.printInfo();
		
	}

	return 0;
}