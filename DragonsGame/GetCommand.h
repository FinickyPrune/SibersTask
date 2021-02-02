#pragma once
#include "ICommand.h"
class GetCommand : public ICommand
{
public:
	virtual void execute() override;
};

