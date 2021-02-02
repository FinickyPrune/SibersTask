#pragma once
#include "ICharacter.h"

class DefaultCharacter : public ICharacter
{
private:

	Objects _inventory;
	Room* _currRoom;
	size_t _stepLimit = 0;

public:

	DefaultCharacter(Room*, size_t);

	~DefaultCharacter() = default;

	void move(char) override {};

	void get() override {};

	void drop() override {};

	Objects getData() const override { return Objects(); }

	Room* getRoom() const override { return _currRoom; }


};

