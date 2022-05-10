#include <string>
#include "Contessa.hpp"
#include "Game.hpp"

namespace coup {
    string Contessa::role() const {
        return "Contessa";
    }

    void Contessa::block(Player &player) {
        player.beBlocked();

        // game->nextTurn();
    }
}