#pragma once
#include "IView.h"
#include "Model.h"
#include <iostream>
#include <Windows.h>

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
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

    void roomInfo() override;

};

