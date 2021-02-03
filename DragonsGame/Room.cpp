#include "Room.h"

Room::~Room()
{
	_doors.clear();
	_items.clear();
}

void Room::setItem(std::string item)
{
	if (_items.count(item) == 0)
	{
		_items.insert({ item, 1 });

		if (item == "TOURCHLIGHT")
		{
			_hasTourchlight = true;
		}
	}
	else
	{
		_items[item] += 1;
	}
}

bool Room::subItem(std::string item)
{
	if (_items.count(item) != 0)
	{
		if (item == "TOURCHLIGHT" && _items["TOURCHLIGHT"] == 1)
		{
			_hasTourchlight = false;
		}
		
		_items[item] -= 1;
		return true;
	}
	if (_items[item] == 0)
	{
		_items.erase(item);
		return false;
	}
	if (_items.count(item) == 0)
	{
		return false;
	}
}
