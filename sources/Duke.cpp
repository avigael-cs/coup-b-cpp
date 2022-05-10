#include "Duke.hpp"
#include "Game.hpp"

namespace coup {

    void Duke::tax() {
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }
        
        plusCoins(3);

        game->nextTurn();

        lastIsForeignAid = false;
    }

    void Duke::block(Player& player) {
        player.beBlockedForeignAid();

        // game->nextTurn();
    }

    string Duke::role() const {
        return "Duke";
    }

}
