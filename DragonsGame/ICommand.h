#pragma once
#include "ICharacter.h"
class ICommand
{
public:
	virtual void execute(ICharacter*) = 0;
};

