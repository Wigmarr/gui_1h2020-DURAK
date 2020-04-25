#include "card.h"

Card::Card(int m, int c){
    this->mast = m;
    this->cost = c;
}

Card::Card()
{
    this->mast = 0;
    this->cost = 0;
}

