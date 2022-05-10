#include "Ambassador.hpp"
#include "Game.hpp"

namespace coup {

    void Ambassador::transfer(Player &player, Player &to) {
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        /*if(to.coins() >= MAX_COINS) {
            throw runtime_error("the player has too many coins.");
        }*/

        player.plusCoins(-1);
        to.plusCoins(1);

        lastIsForeignAid = false;

        game->nextTurn();
    }
    
    void Ambassador::block(Player &player)
    {
        player.beBlocked();

        // game->nextTurn();
    }

    string Ambassador::role() const {
        return "Ambassador";
    }
}
