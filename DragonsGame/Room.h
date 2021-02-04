#pragma once
#include <map>
#include <string>

struct Cords
{
	size_t x = 0;
	size_t y = 0;
};

//struct Monster
//{
//	bool alive  = false;
//	bool sleeping = true;
//	bool attacking = false;
//};

class Room
{
private:

	std::map<char, bool> _doors;
	
	std::map<std::string, size_t> _items;

	bool _darkRoom = false;
	bool _hasTorch = false;
	bool _hasMonster = false;

	Cords _cords;
	size_t _OpenDoors = 0;

public:

	Room() = default;

	virtual ~Room();

	void setDarkRoom() { _darkRoom = true; }

	bool canSeeInRoom() { return !_darkRoom || _hasTorch; }

	bool isMonsterInRoom() { return _hasMonster; }

	void addOpenDoor() { _OpenDoors += 1; }

	size_t getOpenDoors() { return _OpenDoors; }

	auto getDoors() const { return _doors; }

	void setDoor(char s) { _doors[s] = true; }

	auto getItems() const { return _items; }

	void setItem(std::string, size_t);

	bool subItem(std::string, size_t);

	//Monster getMonster() { return _monster; }

	void setMonster(bool a) { _hasMonster = a; }


	/*void setMonster(bool has, bool alive, bool attack, bool sleep)
	{
		_hasMonster = has;
		_monster.alive = alive;
		_monster.attacking = attack;
		_monster.sleeping = sleep;
	}*/

	Cords getCords() const { return _cords; }
	
	void setCords(Cords c) 
	{ 
		_cords.x = c.x; 
		_cords.y = c.y;
	}
};

