#include "DefaultCharacter.h"

DefaultCharacter::DefaultCharacter(Room* room, size_t limit)
{
	_currRoom = room;
	_stepLimit = limit;
	_cords = _currRoom->getCords();
}

void DefaultCharacter::move(char c)
{
	if (c == 'E' && _currRoom->getDoors().E == true)
	{
		_cords.x += 1;
	}
	else if (c == 'W' && _currRoom->getDoors().W == true)
	{
		_cords.x -= 1;
	}
	else if (c == 'N' && _currRoom->getDoors().N == true)
	{
		_cords.y += 1;
	}
	else if (c == 'S' && _currRoom->getDoors().S == true)
	{
		_cords.y -= 1;
	}
}
