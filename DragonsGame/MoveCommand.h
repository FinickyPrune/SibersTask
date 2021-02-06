#pragma once
#include "ICommand.h"
class MoveCommand : public ICommand
{
private:
	char _direction;
public:

	MoveCommand(char s) { _direction = s; }

	virtual ~MoveCommand() = default;

	void execute(ICharacter* character) override
	{
		character->move(_direction);
	}
};

