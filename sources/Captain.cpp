#include "Captain.hpp"
#include "Game.hpp"

namespace coup {

    Captain::Captain(Game &game, string name) : Player(game, std::move(name)) {
        stealed = nullptr;
    }

    void Captain::steal(Player &player) {
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        int coins = player.coins() > 1 ? 2 : 1;
        player.plusCoins(-coins);
        plusCoins(coins);

        stealed = &player;

        game->nextTurn();

        lastIsForeignAid = false;
    }

    void Captain::block(Player &player)
    {
        player.beBlocked();

        // game->nextTurn();
    }

    string Captain::role() const {
        return "Captain";
    }

    void Captain::beBlocked() {
        stealed->plusCoins(2);
        plusCoins(-2);
        stealed = nullptr;
    }
}
