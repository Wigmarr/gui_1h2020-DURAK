#include "desk.h"
#include <random>
#include <algorithm>
#include <iterator>
Desk::Desk()
{
    int k = 0;
    for (int i=1; i<=4; i++){
        for(int j=6; j<=14; j++){
            this->deck.push_back(Card(i,j));
            k++;
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->deck[0], this->deck[35], g);
}
