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
