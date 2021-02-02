#pragma once
#include "ICommand.h"
class MoveCommand : public ICommand
{
public:

	virtual void execute() override;
};

