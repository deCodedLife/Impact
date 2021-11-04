#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    db.setDatabaseName("data.bin");

    if ( db.open() == false )
    {
        qDebug() << "Something went wrong" << db.lastError();
    }
}

QJsonArray Database::getCharacters()
{
    QJsonArray heroes;
    QSqlQuery query;

    query.prepare("select * from Characters");
    query.exec();

    while( query.next() )
    {
        QJsonObject hero;

        hero["id"] = query.value(0).toInt();
        hero["name"] = query.value(1).toString();
        hero["image"] = query.value(2).toString();

        hero["minAttackAnimation"] = query.value(3).toInt();
        hero["minHoldAttackAnimation"] = query.value(4).toInt();

        hero["useTwoHandSword"] = query.value(5).toInt() == 0 ? false : true;
        hero["jumpCancel"] = query.value(6).toInt() == 0 ? false : true;
        hero["shiftCancel"] = query.value(7).toInt() == 0 ? false : true;

        heroes.append(hero);
    }

    return heroes;
}
