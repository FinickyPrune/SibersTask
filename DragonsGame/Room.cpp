#include "Room.h"

Room::~Room()
{
	_doors.clear();
	_items.clear();
}

void Room::setItem(std::string item, size_t amount)
{
	if (_items.count(item) == 0)
	{
		_items.insert({ item, amount });

		if (item == "TOURCHLIGHT")
		{
			_hasTourchlight = true;
		}
	}
	else
	{
		_items[item] += amount;
	}
}

bool Room::subItem(std::string item, size_t amount)
{
	if (_items.count(item) != 0)
	{
		if (item == "TOURCHLIGHT" && _items["TOURCHLIGHT"] == 1)
		{
			_hasTourchlight = false;
		}
		
		_items[item] -= amount;

		if (_items[item] == 0)
		{
			_items.erase(item);
		}
		return true;
	}
	
	if (_items.count(item) == 0)
	{
		return false;
	}
}
