#include "game.h"
#include <vector>

Game::Game(Player one, Player two, Desk desk)
{
    for(int i=0; i<12; i++){
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

void Game::step(Player one, Player two, Desk desk)
{

}
