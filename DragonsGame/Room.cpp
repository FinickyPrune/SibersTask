#include "Room.h"

void Room::setItem(std::string item)
{
	if (_items.count(item) == 0)
	{
		_items.insert({ item, 1 });
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
