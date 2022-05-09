#pragma once
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>
using namespace coup;
using namespace std;
namespace coup {
    class Assassin : public Player
    {
        
        private:
            

        public:
            //constructors 
            Assassin( Game &game , string name );
            //getters 
            string role() const override;
            bool isCouped() const;
            Player *getCoupedPlayer() const;
            //setters
            void setPlayer();


            //function
            void coup(Player &player);
            //deconstructor
            ~Assassin() {}
    };
}