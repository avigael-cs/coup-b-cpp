// Can block the assasinate (Assasin action).
#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "Player.hpp"

namespace coup {

    class Contessa : public Player
    {
    public:
        Contessa(Game &game, string name): Player(game, name) {}
        ~Contessa() {}
        void block(Player &player) override;//contessa can block assassinate
        virtual string role() const override;
    };
}