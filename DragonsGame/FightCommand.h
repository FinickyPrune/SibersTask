#pragma once
#include "ICommand.h"
class FightCommand : public ICommand
{

public:

	FightCommand() = default;

	~FightCommand() = default;

	void execute(ICharacter* character) override
	{
		character->fight();
	}
};

