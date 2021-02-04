#pragma once
#include "Room.h"
class ICharacter
{
public:

	virtual void move(char) = 0;

	virtual void get(std::string) = 0;

	virtual void drop(std::string) = 0;

	virtual void open() = 0;

	virtual void eat() = 0;

	virtual size_t getStepLimit() = 0;

	virtual void setStepLimit(size_t) = 0;

	virtual void setReaction(bool) = 0;

	virtual bool getReaction() = 0;

	virtual Room* getRoom() const = 0;

	virtual void setRoom(Room*) = 0;

	virtual Cords getCords() = 0;

	virtual void setCords(Cords) = 0;

	virtual char getLastDoor() = 0;

	virtual void setLastDoor(char) = 0;

	virtual bool getWin() = 0;

	virtual bool getFail() = 0;

	virtual bool getSight() = 0;
};

