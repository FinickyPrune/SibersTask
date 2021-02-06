#pragma once

//VIEW INTERFACE

class IView
{
public:

	virtual void printInfo() = 0;
	
	virtual void printStartInfo() = 0;

	virtual void darkRoomMessage() = 0;

	virtual void winMessage() = 0;

	virtual void failMessage() = 0;

	virtual void MonsterMessage() = 0;

	virtual void RoomStatsMessage() = 0;

	virtual void roomInfo() = 0;
};

