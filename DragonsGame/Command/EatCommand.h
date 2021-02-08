#pragma once
#include "ICommand.h"
class EatCommand : public ICommand
{
public:

	EatCommand() = default;

	virtual ~EatCommand() = default;

	void execute(ICharacter* character) override
	{
		character->eat();
	}
};

