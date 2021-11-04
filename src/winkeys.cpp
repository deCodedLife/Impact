#include "winkeys.h"

WinKeys::WinKeys(QObject *parent) : QObject(parent)
{

}

void WinKeys::CheckKey(int key)
{
    if ( GetKeyState(key) & 0x8000 )
    {
        emit keyPressed(key);
    }
}
