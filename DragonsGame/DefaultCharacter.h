#pragma once
#include "ICharacter.h"

class DefaultCharacter : public ICharacter
{
private:

	std::map<std::string, size_t>  _inventory;
	Room* _currRoom;
	size_t _stepLimit = 0;
	Cords _cords;
	char _lastDoor;

	bool _hasKey = false;
	bool _hasTorch = false;
	bool _hasSword = false;

	bool _canSee = false;

	bool _reacted = false;

	bool _win = 0;
	bool _fail = 0;

public:

	DefaultCharacter(Room*, size_t);

	virtual ~DefaultCharacter() { _inventory.clear(); }

	void move(char) override;

	void get(std::string) override;

	void drop(std::string) override;

	void open() override;

	void eat() override;

	size_t getStepLimit()  override { return _stepLimit; }

	void setStepLimit(size_t c) override  { _stepLimit = c; }

	void setReaction(bool a) override { _reacted = a; }

	bool getReaction() override { return _reacted; }

	Room* getRoom() const override { return _currRoom; }

	void setRoom(Room* room) override { _currRoom = room; };

	Cords getCords() override { return _cords; }

	void setCords(Cords c)  override { _cords.x = c.x; _cords.y = c.y; }

	void setLastDoor(char d) override { _lastDoor = d; }

	char getLastDoor() { return _lastDoor; }

	bool getWin() { return _win; }

	bool getFail() { return _fail; }

	bool getSight() { return _currRoom->canSeeInRoom() || _hasTorch; }

};

