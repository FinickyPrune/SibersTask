#pragma once
#include <map>
#include <string>

struct Doors
{
	bool N = false;
	bool S = false;
	bool E = false;
	bool W = false;
};

struct Cords
{
	size_t x = 0;
	size_t y = 0;
};

struct Objects
{
	size_t key = 0;
	size_t chest = 0;
	size_t torchlight = 0;
};

class Room
{
private:

	Doors _doors;
	Objects _items;
	Cords _cords;

public:

	Doors getDoors() { return _doors; }

	void setDoorN(bool val) { _doors.N = val; }
	void setDoorS(bool val) { _doors.S = val; }
	void setDoorE(bool val) { _doors.E = val; }
	void setDoorW(bool val) { _doors.W = val; }

	Objects* getItems() { return &_items; }
	Cords getCords() { return _cords; }
	
	void setCords(Cords c) 
	{ 
		_cords.x = c.x; 
		_cords.y = c.y;
	}
};

