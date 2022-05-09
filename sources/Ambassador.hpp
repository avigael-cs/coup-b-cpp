#pragma once
#include "Player.hpp"


namespace coup {
    class Ambassador : public Player
    {
        private:

        public:
                Ambassador ();
                Ambassador(Game &game, string name): Player(game, name){}
                void transfer(Player &player, Player &to);
                string role();
                void block(Player &player);
                ~Ambassador() {}
    };
        
        
}