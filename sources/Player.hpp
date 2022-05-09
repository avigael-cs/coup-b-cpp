#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>
#include <exception>
#include "Game.hpp"
//using namespace coup;
using namespace std;

namespace coup {
    class Player 
    {
        
        string nameOfPlayer;
        string Role_NameOfPlayer;
        bool alive;;
        Game *game;
        int numOfCoins;
        int id;
            
            
        public:

            /* --- getters --- */
            Game* getGame() const;
            string getNameOfPlayer() const;
            
            // bool didForeign() const;
            // bool isInGame(Player &);
          
            bool isAlive() const;
            virtual std::string role() const;
            int getCoins() const;
            int getId() const;
            bool Player::inTheGame() const;

            /* --- setters --- */
            void setAlive(bool);
            void plusCoins(int);
            void setId(int);
            virtual void resetPlayer();

            Player(Game& game, string name);            
            void coup(Player &player);
            void income();                     
            void foreign_aid();            
            void die();                       
            void revive();                     
            int coins();                    
            string role();  
            void block(Player &player);                          
            ~Player() {}
        };
}