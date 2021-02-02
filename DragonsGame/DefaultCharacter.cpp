#include "DefaultCharacter.h"

DefaultCharacter::DefaultCharacter(Room* room, size_t limit)
{
	_currRoom = room;
	_stepLimit = limit;
}
