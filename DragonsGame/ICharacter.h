#pragma once
#include "Room.h"
class ICharacter
{
public:

	virtual void move(char) = 0;

	virtual void get() = 0;

	virtual void drop() = 0;

	//virtual auto getData() const = 0; //не воид

	virtual Room* getRoom() const = 0;

	virtual void setRoom(Room*) = 0;

	virtual Cords getCords() = 0;

	virtual void setCords(Cords) = 0;

};

