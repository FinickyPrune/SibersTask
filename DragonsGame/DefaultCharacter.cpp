#include "DefaultCharacter.h"

DefaultCharacter::DefaultCharacter(Room* room, size_t limit)
{
	_currRoom = room;
	_stepLimit = limit;
	_cords = _currRoom->getCords();
	_lastDoor = 'E';
	_canSee = _currRoom->canSeeInRoom() || _hasTorch;
}

void DefaultCharacter::move(char c)
{
	if (_stepLimit != 0)
	{

		if (c == 'E' && _currRoom->getDoors()['E'] == true)
		{
			_cords.x += 1;
			_stepLimit -= 1;
			_lastDoor = 'W';
		}
		else if (c == 'W' && _currRoom->getDoors()['W'] == true)
		{
			_cords.x -= 1;
			_stepLimit -= 1;
			_lastDoor = 'E';

		}
		else if (c == 'N' && _currRoom->getDoors()['N'] == true)
		{
			_cords.y += 1;
			_stepLimit -= 1;
			_lastDoor = 'S';

		}
		else if (c == 'S' && _currRoom->getDoors()['S'] == true)
		{
			_cords.y -= 1;
			_stepLimit -= 1;
			_lastDoor = 'N';

		}
	}
	else
	{
		_fail = true;
	}
}

void DefaultCharacter::get(std::string item)
{
	_canSee = _currRoom->canSeeInRoom() || _hasTorch; //PLAYER MUST HAVE ABILITY TO SEE IN CASE HE WANTS TO GET ITEMS

	if (item != "GOLD" && item != "CHEST" && _canSee)
	{
		if (_inventory.count(item) == 0 && _currRoom->subItem(item, 1)) //IF PLAYER DOESNT HAVE THIS OBJECT BEFORE
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
		else if (_currRoom->subItem(item, 1)) //IF PLAYER ALREADY HAS OBJECT OF THIS TYPE
		{
			_inventory[item] += 1;
		}
	}
	else if (item == "GOLD" && _canSee) //IF ITEM IS GOLD GRAB ALL COINS WITH 1 "GET" COMMAND
	{
		if (_inventory.count(item) == 0 && _currRoom->subItem(item, 1))
		{
			_inventory.insert({ item, _currRoom->getItems()["GOLD"] + 1});
			_currRoom->subItem(item, _currRoom->getItems()["GOLD"]);
		}
		else if (_currRoom->subItem(item, 1))
		{
			_inventory[item] += _currRoom->getItems()["GOLD"] + 1;
			_currRoom->subItem(item, _currRoom->getItems()["GOLD"]);
		}
	}
	
}

void DefaultCharacter::drop(std::string item)
{
	_canSee = _currRoom->canSeeInRoom() || _hasTorch; //PLAYER MUST HAVE ABILITY TO SEE IN CASE HE WANTS TO DROP ITEMS
	
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
			_inventory.erase(item); //ERASE THIS TYPE OF OBJECT FROM INVENTORY

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
	_canSee = _currRoom->canSeeInRoom() || _hasTorch; //UPDATE INFO ABOUT ABILITY TO SEE IN CASE PLAYER DROP TORCH
}

void DefaultCharacter::open()
{
	_canSee = _currRoom->canSeeInRoom() || _hasTorch;
	
	if (_inventory.count("KEY") != 0 && _currRoom->getItems()["CHEST"] != 0 && _canSee)
	{
		_win = true;
	}
}

void DefaultCharacter::eat()
{
	_canSee = _currRoom->canSeeInRoom() || _hasTorch;

	if (_currRoom->getItems().count("FOOD") != 0 && _canSee) //IF FOOD IS IN ROOM
	{
		_currRoom->subItem("FOOD", 1);
		_stepLimit = static_cast<size_t>(_stepLimit * 1.2); //I DECIDED TO INCREASE STEPLIMIT ON 20%

	}
	else if (_inventory.count("FOOD") != 0 && _canSee) //IF FOOD IS IN INVENTORY
	{
		_inventory["FOOD"] -= 1;
		_stepLimit = static_cast<size_t>(_stepLimit * 1.2);

		if (_inventory["FOOD"] == 0)
		{
			_inventory.erase("FOOD");
		}
	}
}

void DefaultCharacter::fight()
{
	if (_inventory.count("SWORD") != 0)
	{
		_currRoom->setMonster(false);
	}
}
