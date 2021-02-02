#pragma once
#include "ICharacter.h"

class DefaultCharacter : public ICharacter
{
private:


	std::map<std::string, size_t>  _inventory;
	Room* _currRoom;
	size_t _stepLimit = 0;
	Cords _cords;

public:

	DefaultCharacter(Room*, size_t);

	~DefaultCharacter() = default;

	void move(char) override;

	void get() override {};

	void drop() override {};

	//auto getData() const override { return Objects(); }

	Room* getRoom() const override { return _currRoom; }

	void setRoom(Room* room) override { _currRoom = room; };

	Cords getCords() override { return _cords; }

	void setCords(Cords c) { _cords.x = c.x; _cords.y = c.y; }

};

