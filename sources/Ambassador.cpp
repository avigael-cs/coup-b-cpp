#include "Ambassador.hpp"
#include "Captain.hpp"
namespace coup {
    void Ambassador::transfer(Player &player, Player &to)
    {
        player.plusCoins(-1);
        to.plusCoins(1);
    }
    
    void Ambassador::block(Player &player)
    {
        player.setBlockedSteal(true);
    }

    string Ambassador::role() const {
        return "Ambassador";
    }
}
