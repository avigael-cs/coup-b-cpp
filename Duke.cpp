
#include "Duke.hpp"

using namespace coup;

namespace coup {

    void Duke::tax() {
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        if (numOfCoins>=MAX_COINS) {
            throw runtime_error("Player must coup!");
        }
        
        plusCoins(3);   
    }

    void Duke::block(Player& player) {
        player.setBlcokedForeignAdd(true);
    }

    string Duke::role() const {
        return "Duke";
    }

}
