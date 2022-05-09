// Can block the assasinate (Assasin action).
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;



namespace coup {

    class Contessa : public Player
    {
    public:
        //Contessa(Game &game, string nameOfPlayer);
        //Contessa(Game &game, string nameOfPlayer): Player(){}
        ~Contessa() {}
    };
}