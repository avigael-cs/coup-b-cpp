#include "Captain.hpp"

namespace coup {

    Captain::Captain(Game &game, string nameOfPlayer) : Player(game, nameOfPlayer) {
        blockedSteal = false;
    }

    void Captain::steal(Player &player)
    {
        if (blockedSteal) {
            blockedSteal = false;
            return;
        }

        player.plusCoins(-1);
        plusCoins(1);
    }

    void Captain::block(Player &player)
    {
        player.setBlockedSteal(true);
    }

    string Captain::role() const {
        return "Captain";
    }

    void Captain::setBlockedSteal(bool blockedSteal) {
        this->blockedSteal = blockedSteal;
    }
}
