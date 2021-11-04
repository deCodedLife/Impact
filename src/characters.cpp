#include "characters.h"

Characters::Characters(QObject *parent) : QObject(parent)
{
}

int Characters::getCurrentID()
{
    return current;
}

Character Characters::getCurrent()
{
    for ( Character hero : heroes )
    {
        if ( hero.id == active[ current ] )
        {
            return hero;
        }
    }

    return Character();
}

void Characters::Add(Character character)
{
    heroes.append( character );
}

void Characters::AddActive(int id, int pos)
{
    active[pos] = id;
}

void Characters::SetCurrent(int character)
{
    current = character;
    emit characterChanged();
}

QList<Character> Characters::get()
{
    return heroes;
}

QJsonArray Characters::getJson()
{
    QJsonArray output;

    for (Character hero : heroes)
    {
        output.append( hero.toJson() );
    }

    return output;
}

QJsonArray Characters::getActive()
{
    QJsonArray output;

    for (int i = 0; i < 4; i++)
    {
        output.append(Character().toJson());
    }


    for ( Character hero : heroes )
    {
        for ( int i = 0; i < 4; i++ )
        {
            if ( hero.id == active[i] )
            {
                output[i] = hero.toJson();
            }
        }
    }

    return output;
}

Character::Character()
{
    id = -1;
    name = "";
    image = "";
    minAttackAnimation = 0;
    minHoldAttackAnimation = 0;
    useTwoHandSword = false;
    jumpCancel = false;
    shiftCancel = false;
}

QJsonObject Character::toJson()
{
    QJsonObject character;

    character["id"] = id;
    character["name"] = name;
    character["image"] = image;
    character["minAttackAnimation"] = minAttackAnimation;
    character["minHoldAttackAnimation"] = minHoldAttackAnimation;
    character["useTwoHandSword"] = useTwoHandSword;
    character["jumpCancel"] = jumpCancel;
    character["shiftCancel"] = shiftCancel;

    return character;
}

Character Character::fromJson(QJsonObject data)
{
    Character newCharacter;

    newCharacter.id = data["id"].toInt();
    newCharacter.name = data["name"].toString();
    newCharacter.image = data["image"].toString();
    newCharacter.minAttackAnimation = data["minAttackAnimation"].toInt();
    newCharacter.minHoldAttackAnimation = data["minHoldAttackAnimation"].toInt();
    newCharacter.useTwoHandSword = data["useTwoHandSword"].toBool();
    newCharacter.jumpCancel = data["jumpCancel"].toBool();
    newCharacter.shiftCancel = data["shiftCancel"].toBool();

    return newCharacter;
}
