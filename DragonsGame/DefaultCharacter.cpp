#include "DefaultCharacter.h"

DefaultCharacter::DefaultCharacter(Room* room, size_t limit)
{
	_currRoom = room;
	_stepLimit = limit;
	_cords = _currRoom->getCords();

	_canSee = _currRoom->canSeeInRoom() || _hasTorch;
}

void DefaultCharacter::move(char c)
{
	if (_stepLimit != 0)
	{
		_prevCords.x = _cords.x;
		_prevCords.y = _cords.y;

		if (c == 'E' && _currRoom->getDoors()['E'] == true)
		{
			_cords.x += 1;
			_stepLimit -= 1;
		}
		else if (c == 'W' && _currRoom->getDoors()['W'] == true)
		{
			_cords.x -= 1;
			_stepLimit -= 1;
		}
		else if (c == 'N' && _currRoom->getDoors()['N'] == true)
		{
			_cords.y += 1;
			_stepLimit -= 1;
		}
		else if (c == 'S' && _currRoom->getDoors()['S'] == true)
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
	_canSee = _currRoom->canSeeInRoom() || _hasTorch;

	if (item != "GOLD" && item != "CHEST" && _canSee)
	{
		if (_inventory.count(item) == 0 && _currRoom->subItem(item, 1))
		{
			_inventory.insert({ item,1 });

			if (item == "KEY")
			{
				_hasKey = true;
			}
			if (item == "SWORD")
			{
				_hasSword = true;
			}
			if (item == "TORCH")
			{
				_hasTorch = true;
			}
		}
		else if (_currRoom->subItem(item, 1))
		{
			_inventory[item] += 1;
		}
	}
	else if (item == "GOLD" && _canSee)
	{
		if (_inventory.count(item) == 0 && _currRoom->subItem(item, 1))
		{
			_inventory.insert({ item, _currRoom->getItems()["GOLD"] + 1});
			_currRoom->subItem(item, _currRoom->getItems()["GOLD"]);
		}
		else if (_currRoom->subItem(item, 1))
		{
			_inventory[item] += _currRoom->getItems()["GOLD"] + 1;
		}
	}
	
}

void DefaultCharacter::drop(std::string item)
{
	_canSee = _currRoom->canSeeInRoom() || _hasTorch;
	
	if (_canSee)
	{
		if (_inventory.count(item) != 0)
		{
			_inventory[item] -= 1;
			_currRoom->setItem(item, 1);

			if (item == "KEY")
			{
				_hasKey = false;
			}
		}
		if (_inventory[item] == 0)
		{
			_inventory.erase(item);

			if (item == "SWORD")
			{
				_hasSword = false;
			}
			if (item == "TORCH")
			{
				_hasTorch = false;
			}
		}
	}
	_canSee = _currRoom->canSeeInRoom() || _hasTorch;
}

void DefaultCharacter::open()
{
	if (_inventory.count("KEY") != 0 && _currRoom->getItems()["CHEST"] != 0 && _canSee)
	{
		_win = true;
	}
}

void DefaultCharacter::eat()
{
	if (_currRoom->getItems().count("FOOD") != 0)
	{
		_currRoom->subItem("FOOD", 1);
		_stepLimit = static_cast<size_t>(_stepLimit * 1.2);

	}
	else if (_inventory.count("FOOD") != 0)
	{
		_inventory["FOOD"] -= 1;
		_stepLimit = static_cast<size_t>(_stepLimit * 1.2);

		if (_inventory["FOOD"] == 0)
		{
			_inventory.erase("FOOD");
		}
	}
}
