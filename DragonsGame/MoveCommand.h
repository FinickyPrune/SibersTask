#pragma once
#include "ICommand.h"
class MoveCommand : public ICommand
{
private:
	std::string _direction;
public:

	MoveCommand(std::string s) { _direction = s; }

	virtual void execute(ICharacter*) override;
};

