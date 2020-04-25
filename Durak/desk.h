#ifndef DESK_H
#define DESK_H
#include "card.h"
#include<vector>

class Desk
{
public:
    std::vector<Card> board; //на столе
    std::vector<Card> bito; //бито
    std::vector<Card> deck; //в колоде
    Card trump;
    Desk();
};

#endif // DESK_H
