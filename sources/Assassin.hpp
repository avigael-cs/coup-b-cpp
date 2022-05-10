// Can assisinate (coup) every player for 3 coins intead of 7 , 
//this action can be blocked by Contessa role.

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"
#include "Game.hpp"

// using namespace coup;

namespace coup {

    class Assassin : public Player
    {
        static const int ASSASSINATION_PRICE = 3;

        bool blockedCoup;

    public:
        //constructors 
        Assassin( Game &game , string name );
        ~Assassin() {}

        //getters 
        string role() const override;

        //function
        void coup(Player &player) override;

        void setBlockedCoup(bool blockedCoup) override;
        //deconstructor
    };
}