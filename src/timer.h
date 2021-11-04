#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QThread>

class Timer : public QObject
{
    Q_OBJECT
signals:
    void timeout();

public:
    explicit Timer(int timems = 100, QObject *parent = nullptr);
    ~Timer();
    void Configure(QThread &);
    void Pause();
    void Start();
    void SetTime(int);

public slots:
    void Countdown();

private:
    int sleepms;
    bool isPaused;

};

#endif // TIMER_H
