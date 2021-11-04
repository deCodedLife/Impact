#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    QJsonArray getCharacters();

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

signals:

};

#endif // DATABASE_H
