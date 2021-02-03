#include "DefaultCharacter.h"

DefaultCharacter::DefaultCharacter(Room* room, size_t limit)
{
	_currRoom = room;
	_stepLimit = limit;
	_cords = _currRoom->getCords();
}

void DefaultCharacter::move(char c)
{
	if (_stepLimit != 0)
	{
		if (c == 'E' && _currRoom->getDoors().E == true)
		{
			_cords.x += 1;
			_stepLimit -= 1;
		}
		else if (c == 'W' && _currRoom->getDoors().W == true)
		{
			_cords.x -= 1;
			_stepLimit -= 1;
		}
		else if (c == 'N' && _currRoom->getDoors().N == true)
		{
			_cords.y += 1;
			_stepLimit -= 1;
		}
		else if (c == 'S' && _currRoom->getDoors().S == true)
		{
			_cords.y -= 1;
			_stepLimit -= 1;
		}
	}
	else
	{
		_fail = true;
	}
}

void DefaultCharacter::get(std::string item)
{
	if (item != "CHEST") 
	{
		if (_inventory.count(item) == 0 && _currRoom->subItem(item))
		{
			_inventory.insert({ item,1 });
		}
		else if (_currRoom->subItem(item))
		{
			_inventory[item] += 1;
		}
	}
	
}

void DefaultCharacter::drop(std::string item)
{
	if (_inventory.count(item) != 0)
	{
		_inventory[item] -= 1;
		_currRoom->setItem(item);
	}
	if (_inventory[item] == 0)
	{
		_inventory.erase(item);
	}
}

void DefaultCharacter::open()
{
	if (_inventory.count("KEY") != 0 && _currRoom->getItems()["CHEST"] != 0)
	{
		_win = true;
	}
	else if (_currRoom->getItems()["CHEST"] != 0 && (_inventory.count("KEY") == 0 || _inventory["KEY"] == 0))
	{
		_fail = true;
	}
}
