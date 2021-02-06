#pragma once
#include "ICharacter.h"

// COMMAND INTERFACE

class ICommand
{
public:

	virtual void execute(ICharacter*) = 0;
};

