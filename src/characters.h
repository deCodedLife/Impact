#pragma once

#include <QDebug>
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>

class Character
{
public:
    Character();

    int id;
    QString name;
    QString image;
    int minAttackAnimation;
    int minHoldAttackAnimation;
    bool useTwoHandSword;
    bool jumpCancel;
    bool shiftCancel;

    int firstSkillCooldown;
    int ultimateCooldown;

    QJsonObject toJson();
    static Character fromJson(QJsonObject);
};

class Characters : public QObject
{
    Q_OBJECT

signals:
    void characterChanged();

public:
    Characters(QObject *parent = nullptr);

    int getCurrentID();
    Character getCurrent();

    void Add(Character);
    void AddActive(int id, int pos);
    void SetCurrent(int);

    QList<Character> get();
    QJsonArray getJson();
    QJsonArray getActive();

private:
    int current;
    QList<int> active;
    QList<Character> heroes;
};
