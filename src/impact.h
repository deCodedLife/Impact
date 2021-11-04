#ifndef IMPACT_H
#define IMPACT_H

#include <QDebug>
#include <QObject>

#include "timer.h"
#include "winkeys.h"
#include "database.h"
#include "characters.h"
#include "dragonstrike.h"

class Impact : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentCharacter READ getCurrentCharacter NOTIFY currentCharacterChanged)
    Q_PROPERTY(QJsonArray activeCharacters READ getActiveCharacters NOTIFY activeCharactersChanged)
    Q_PROPERTY(bool enabled READ getCurrentState WRITE Toggle NOTIFY enabledChanged)
    Q_PROPERTY(bool ignoring READ getIgnoreState NOTIFY ignoreStateChanged)
    Q_PROPERTY(bool dragonstrike READ getDragonstrikeState WRITE ToggleDragonstrike NOTIFY dragonstrikeChanged)
    Q_PROPERTY(bool cancelAnimations READ getCancelAnimationsState WRITE ToggleCancelAnimations NOTIFY cancelAnimationsChanged)

signals:
   void enabledChanged(bool);
   void dragonstrikeChanged(bool);
   void cancelAnimationsChanged(bool);
   void ignoreStateChanged(bool);
   void currentCharacterChanged(int);
   void activeCharactersChanged(QJsonArray);

public:
   explicit Impact(QObject *parent = nullptr);
   ~Impact();

   void Toggle(bool);
   void ToggleDragonstrike(bool);
   void ToggleCancelAnimations(bool);

   Q_INVOKABLE QJsonArray getCharacters();
   Q_INVOKABLE QJsonArray getActiveCharacters();
   Q_INVOKABLE void addCharacter(int id, int pos);

public slots:
    void Run();
    void ToggleState();
    void ToggleIgnoring();
    void KeyListener(int);
    void EmitNewCharacter();

private:
    int getCurrentCharacter();
    bool getCurrentState();
    bool getIgnoreState();
    bool getDragonstrikeState();
    bool getCancelAnimationsState();

    Timer timer;
    Timer *countDown;
    WinKeys keys;
    Characters heroes;
    Dragonstrike strike;
    Database db;

    QThread timerThread;
    QThread countDownThread;

    bool isEnabled;
    bool shouldIgnore;

    bool dragonstrikeEnabled;
    bool cancelAnimations;
};

#endif // IMPACT_H
