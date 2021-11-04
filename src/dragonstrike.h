#pragma once

#include <QDebug>
#include <QObject>
#include <QThread>

#include "timer.h"
#include "characters.h"

class Dragonstrike : public QObject
{
    Q_OBJECT
public:
    Dragonstrike();

public slots:
    void MakeStrike(int key);
    void SendKeys();

    void ChangeState(bool);
    void SetCharacter(Character);

private:
    bool enabled;
    Character currentCharacter;

    Timer timer;
    QThread timerThread;
};

