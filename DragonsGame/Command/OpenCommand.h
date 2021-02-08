#pragma once
#include "ICommand.h"
class OpenCommand : public ICommand
{
public:
	OpenCommand() = default;

	virtual ~OpenCommand() = default;

	void execute(ICharacter* character) override
	{
		character->open();
	}
};

