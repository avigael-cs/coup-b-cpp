#include <string>
#include "Contessa.hpp"

namespace coup {
    string Contessa::role() const {
        return "Contessa";
    }

    void Contessa::block(Player &player) {
        player.setBlockedCoup(true);
    }
}