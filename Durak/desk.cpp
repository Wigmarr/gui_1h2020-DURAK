#include "desk.h"
#include "card.h"
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <QDebug>

Desk::Desk()
{
    int k = 0;
    for (int i=1; i<=4; i++){
        for(int j=6; j<=14; j++){
            this->deck.push_back(Card(i,j));
            k++;
        }
    }
    int size = deck.size();
    for (int i = 0; i < size - 1; i++) {
       int j = i + rand() % (size - i);
       std::swap(deck[i], deck[j]);
    }

}
