#ifndef WINKEYS_H
#define WINKEYS_H

#include <QObject>
#include <Windows.h>

class WinKeys : public QObject
{
    Q_OBJECT
signals:
    void keyPressed(int);

public:
    explicit WinKeys(QObject *parent = nullptr);
    void CheckKey(int);

private:
    INPUT input;

};

#endif // WINKEYS_H
