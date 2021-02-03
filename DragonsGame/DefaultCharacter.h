#pragma once
#include "ICharacter.h"

class DefaultCharacter : public ICharacter
{
private:

	std::map<std::string, size_t>  _inventory;
	Room* _currRoom;
	size_t _stepLimit = 0;
	Cords _cords;

	bool _hasKey = false;
	bool _hasTourchlight = false;
	bool _hasSword = false;

	bool _canSee = false;

	bool _win = 0;
	bool _fail = 0;

public:

	DefaultCharacter(Room*, size_t);

	virtual ~DefaultCharacter() { _inventory.clear(); }

	void move(char) override;

	void get(std::string) override;

	void drop(std::string) override;

	void open() override;

	Room* getRoom() const override { return _currRoom; }

	void setRoom(Room* room) override { _currRoom = room; };

	Cords getCords() override { return _cords; }

	void setCords(Cords c) { _cords.x = c.x; _cords.y = c.y; }

	bool getWin() { return _win; }

	bool getFail() { return _fail; }

	bool getSight() { return _canSee; }

};

