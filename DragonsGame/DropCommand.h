#pragma once
#include "ICommand.h"
class DropCommand : public ICommand
{
public:

	virtual void execute(ICharacter*) override;
};

