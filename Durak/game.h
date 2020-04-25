#ifndef GAME_H
#define GAME_H
#include "card.h"
#include "player.h"
#include "desk.h"

class Game
{
public:
    bool isCostOnBoard(Card, Desk);
    void putAttackCard(Player, Card, Desk);
    void putDeffenceCard(Player, Card, Desk);
    void step(Player,Player,Desk);
    void over();
    void next();
    Game(Player,Player,Desk);
};

#endif // GAME_H
