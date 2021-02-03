#pragma once
#include "IView.h"
#include "Model.h"
#include <iostream>

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

