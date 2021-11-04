#include "timer.h"

Timer::Timer(int timems, QObject *parent) : QObject(parent)
{
    if ( timems > 0 )
    {
        sleepms = timems;
    }
}

Timer::~Timer()
{
    this->deleteLater();
    QThread::currentThread()->quit();
}

void Timer::Configure(QThread &thread)
{
    connect(&thread, &QThread::started, this, &Timer::Countdown);
}

void Timer::Pause()
{
    isPaused = true;
}

void Timer::Start()
{
    isPaused = false;
}

void Timer::SetTime(int timems)
{
    if ( timems > 0 )
    {
        sleepms = timems;
    }
}

void Timer::Countdown()
{
    while (true)
    {
        QThread::currentThread()->msleep(sleepms);

        if ( isPaused )
        {
            continue;
        }

        emit timeout();
    }
}
