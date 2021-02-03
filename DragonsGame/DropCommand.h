#pragma once
#include "ICommand.h"
class DropCommand : public ICommand
{
private:
	std::string  _item;

public:

	DropCommand(std::string s) { _item = s; }

	virtual ~DropCommand() = default;

	virtual void execute(ICharacter* character) override
	{
		character->drop(_item);
	}
};

