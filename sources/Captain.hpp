#pragma once
#include <string>
#include <map>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;
using namespace coup;

namespace coup {
    class Captain : public Player
    {
        private:

        public:
            Captain(Game &game, string nameOfPlayer);
            void steal(Player &player);
            void block(Player &player);
            ~Captain() {}
    };
}