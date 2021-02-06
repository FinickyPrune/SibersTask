#pragma once
#include "IView.h"
#include "Model.h"
#include <iostream>
#include <Windows.h>

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Red = 4,
    Yellow = 14,
    White = 15
};

class ConsoleView : public IView
{
private:
    Model* _model;

public:
    ConsoleView(Model*);
    
    virtual ~ConsoleView() = default;

    void printInfo() override;

    void printStartInfo() override;

    void darkRoomMessage() override;

    void winMessage() override;

    void failMessage() override;

    void MonsterMessage() override;

    void RoomStatsMessage() override;

    void roomInfo() override;

};

