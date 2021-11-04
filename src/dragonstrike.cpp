#include "dragonstrike.h"

Dragonstrike::Dragonstrike()
{
    timer.Pause();
    timer.SetTime(200);
    timer.Configure(timerThread);
    timer.moveToThread(&timerThread);
    timerThread.start();

    connect(&timer, &Timer::timeout, this, &Dragonstrike::SendKeys);
}

void Dragonstrike::MakeStrike(int key)
{
    if ( key != 0x01 )
    {
        return;
    }

    if ( currentCharacter.useTwoHandSword == false )
    {
        return;
    }

    timer.Start();
}

void Dragonstrike::SendKeys()
{
    timer.Pause();
}

void Dragonstrike::ChangeState(bool state)
{
    enabled = state;
}

void Dragonstrike::SetCharacter(Character character)
{
    currentCharacter = character;
}
