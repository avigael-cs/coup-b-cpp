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
        Duke(Game, string): Player(){}
        
        
        //functions
        void tax();
        string role() const override;
        void block(Player &player);
        ~Duke() {}
    };
}