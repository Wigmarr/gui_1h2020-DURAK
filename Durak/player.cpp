#include "player.h"

Player::Player(QString n)
{
    this->name = n;
    this->name.append('\n');
}

Player::Player()
{
    this->name = "Player1\n";
}
