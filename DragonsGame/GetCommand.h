#pragma once
#include "ICommand.h"
class GetCommand : public ICommand
{
private:
	std::string  _item;

public:

	GetCommand(std::string s) { _item = s; }

	virtual ~GetCommand() = default;

	virtual void execute(ICharacter* character) override
	{
		character->get(_item);
	}
};

