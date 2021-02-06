#include "Model.h"
#include "Controller.h"
#include "ConsoleView.h"
#include <time.h>

int main()
{
	srand(time(nullptr)); //FOR RANDOM IVENTS LIKE MAZE GENERATION AND MONSTERS ATTACKS

	Model model = Model();
	ConsoleView console = ConsoleView(&model);
	Controller controller = Controller();

	console.printStartInfo();
	model.generateMaze(controller.getMazeSizes());
	model.spawnCharacter();

	while (true)
	{
		console.printInfo();
		model.setCurrCommand(controller.parseCommand(&model, 1));
		model.executeStep();
	}

	return 0;
}
