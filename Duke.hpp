//Can take tax of 3 coins from the treasury , 
//this action cannot be blocked by no one in addition the duke could block foreign_aid from every player.
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "Player.hpp"
//using namespace coup;
using namespace std;

namespace coup {
    class Duke : public Player
    {
    public:
        //contructor
        Duke(Game& game, string name): Player(game, name) {}
    
        //functions
        void tax();
        string role() const override;
        void block(Player &player) override;
        ~Duke() {}
    };
}