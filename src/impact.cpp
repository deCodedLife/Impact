#include "impact.h"

Impact::Impact(QObject *parent) : QObject(parent)
{
    isEnabled = false;
    shouldIgnore = false;
    cancelAnimations = false;
    dragonstrikeEnabled = false;

    heroes.SetCurrent(-1);
    QJsonArray heroesArray = db.getCharacters();

    for ( QJsonValueRef hero : heroesArray )
    {
        Character newCharacter = Character::fromJson( hero.toObject() );
        heroes.Add( newCharacter );
    }

    timer.SetTime(100);
    timer.Configure(timerThread);
    timer.moveToThread(&timerThread);
    timerThread.start();

    countDown = new Timer(2000);
    countDown->Configure(countDownThread);
    countDown->moveToThread(&countDownThread);
    countDownThread.start();

    connect(&timer, &Timer::timeout, this, &Impact::Run);
    connect(countDown, &Timer::timeout, this, &Impact::ToggleIgnoring);
    connect(&keys, &WinKeys::keyPressed, this, &Impact::KeyListener);
    connect(&heroes, &Characters::characterChanged, this, &Impact::EmitNewCharacter);
    connect(&keys, &WinKeys::keyPressed, &strike, &Dragonstrike::MakeStrike);
}

Impact::~Impact()
{
    this->deleteLater();
    timer.deleteLater();
    timerThread.terminate();
    timerThread.quit();
}

void Impact::Toggle(bool state)
{
    isEnabled = state;

    emit enabledChanged(isEnabled);
}

void Impact::ToggleDragonstrike(bool state)
{
    dragonstrikeEnabled = state;

    emit dragonstrikeChanged(state);
}

void Impact::ToggleCancelAnimations(bool state)
{
    cancelAnimations = state;

    emit cancelAnimationsChanged(state);
}

QJsonArray Impact::getCharacters()
{
    return heroes.getJson();
}

QJsonArray Impact::getActiveCharacters()
{
    return heroes.getActive();
}

void Impact::addCharacter(int id, int pos)
{
    heroes.AddActive(id, pos);

    emit activeCharactersChanged( heroes.getActive() );
}

void Impact::ToggleState()
{
    if ( shouldIgnore )
    {
        return;
    }

    isEnabled = !isEnabled;
    shouldIgnore = true;
    countDown->Start();

    emit enabledChanged(isEnabled);
    emit ignoreStateChanged(shouldIgnore);
}

void Impact::ToggleIgnoring()
{
    shouldIgnore = false;
    countDown->Pause();

    emit ignoreStateChanged(shouldIgnore);
}

void Impact::KeyListener(int key)
{
    if ( key == VK_INSERT )
    {
        ToggleState();
    }

    // TODO: Rewrite properly

    if ( key == 0x31 )
    {
        heroes.SetCurrent(0);
    }

    if ( key == 0x32 )
    {
        heroes.SetCurrent(1);
    }

    if ( key == 0x33 )
    {
        heroes.SetCurrent(2);
    }

    if ( key == 0x34 )
    {
        heroes.SetCurrent(3);
    }
}

void Impact::EmitNewCharacter()
{
    emit currentCharacterChanged( heroes.getCurrentID() );
    strike.SetCharacter( heroes.getCurrent() );
}

int Impact::getCurrentCharacter()
{
    return heroes.getCurrentID();
}

bool Impact::getCurrentState()
{
    return isEnabled;
}

bool Impact::getIgnoreState()
{
    return shouldIgnore;
}

bool Impact::getDragonstrikeState()
{
    return dragonstrikeEnabled;
}

bool Impact::getCancelAnimationsState()
{
    return cancelAnimations;
}

void Impact::Run()
{
    keys.CheckKey(VK_INSERT);
    keys.CheckKey(0x31);
    keys.CheckKey(0x32);
    keys.CheckKey(0x33);
    keys.CheckKey(0x34);
    keys.CheckKey(VK_LBUTTON);
}
