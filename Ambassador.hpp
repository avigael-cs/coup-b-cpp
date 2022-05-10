//Can transfer one coin from player to player , 
//in addition Ambassador can block steal action (Captain action).
#pragma once
#include "Player.hpp"


namespace coup {
    class Ambassador : public Player
    {
    public:
        Ambassador(Game &game, string name): Player(game, name){}
        ~Ambassador() {}
        void transfer(Player &player, Player &to);
        string role() const override;
        void block(Player &player) override;
    };
        
        
}