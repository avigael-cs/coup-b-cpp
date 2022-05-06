#pragma once
#include "Player.hpp"


namespace coup {
    class Ambassador : public Player
    {
        private:

        public:
                Ambassador ();
                Ambassador(Game &game, string): Player(){}
                void transfer(Player &player, Player &to);
                void block(Player &player);
                ~Ambassador() {}
    };
        
        
}