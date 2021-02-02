#pragma once
#include "IView.h"
#include "Model.h"

class ConsoleView : public IView
{
private:
    Model* _model;

public:
    ConsoleView(Model*);
    virtual ~ConsoleView() = default;

    void printInfo() override;

};

