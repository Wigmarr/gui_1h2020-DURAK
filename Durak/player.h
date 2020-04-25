#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <vector>
#include "card.h"

class Player
{
public:
    QString name;
    std::vector<Card> halberd;
    Player(QString);
    Player();
};

#endif // PLAYER_H
