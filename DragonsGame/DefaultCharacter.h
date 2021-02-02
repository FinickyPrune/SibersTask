#pragma once
#include "ICharacter.h"

class DefaultCharacter : public ICharacter
{
private:

	Objects _inventory;
	Room* _currRoom;

public:

	DefaultCharacter(Room*);

	~DefaultCharacter();

	void move(char) override;

	void get() override;

	void drop() override;

	Objects getData() override; 


};

