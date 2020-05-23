#include "game.h"
#include <vector>

Game::Game(Player one, Player two, Desk desk)
{
    for(int i=0; i<6; i++){
        one.halberd.push_back(desk.deck.back());
        desk.deck.pop_back();
        two.halberd.push_back(desk.deck.back());
        desk.deck.pop_back();
    }
    desk.trump = desk.deck.back();
    desk.deck.pop_back();
}

bool Game::isCostOnBoard(Card card, Desk desk)
{
    unsigned int i = 0;
    while(i < desk.board.capacity()){
        if (desk.board[i].cost == card.cost){
            return true;
        }
        i++;
    }
    return false;
}

void Game::putAttackCard(Player player, Card card, Desk desk)
{
    if (desk.board.capacity() == 0 || isCostOnBoard(card, desk) == true){
        int j=0;
        std::vector<Card>::iterator i = player.halberd.begin();
        while(i != player.halberd.end()){
            if (player.halberd.at(j).mast == card.mast && player.halberd.at(j).cost == card.cost){
                player.halberd.erase(i);
                desk.board.push_back(card);
            }
            j++;
            i++;
        }
    }
}

void Game::putDeffenceCard(Player player, Card card, Desk desk)
{
    int j=0;
    std::vector<Card>::iterator i = player.halberd.begin();
    while(i != player.halberd.end()){
        if (player.halberd.at(j).mast == card.mast && player.halberd.at(j).cost == card.cost){
            if ((card.mast == desk.trump.mast && desk.trump.mast != desk.board.back().mast) ||
                (card.mast == desk.board.back().mast && card.cost > desk.board.back().cost)){
                player.halberd.erase(i);
                desk.board.push_back(card);
            }

        }
        j++;
        i++;
    }
}

void Game::take(Player player, Desk desk){
    while (desk.board[0].mast != 0) {
        player.halberd.push_back(desk.board.back());
        desk.board.pop_back();
    }
}

void Game::step(Player att, Player def, Desk desk){
    bool flag = true;
    while(flag){
        if(desk.deck.size() >= 2){
            if (att.halberd.size()<6) {
                att.halberd.push_back(desk.deck.back());
                desk.deck.pop_back();
            }
            if(def.halberd.size() <6){
                def.halberd.push_back(desk.deck.back());
                desk.deck.pop_back();
            } else{ flag = false; }
        }
        if(desk.deck.size() == 0){
            if (att.halberd.size()<6) {
                att.halberd.push_back(desk.trump);
                desk.trump = Card(desk.trump.mast,0);
                flag = false;
            }
        }
    }
}
