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
            std::string getNameOfPlayer() const;
            // bool isPlaying() const;
            // bool didForeign() const;
            // bool isInGame(Player &);
            // bool isMaxCoins() const;
            bool isAlive() const;
            virtual std::string role() const;
            int getCoins() const;
            size_t getid() const;

            /* --- setters --- */
            void setAlive(bool);
            void setCoins(int);
            void setId(int);
            virtual void resetPlayer();

            //Player(Game& game, string name);            
            void coup(Player &player);
            void income();                     
            void foreign_aid();            
            void die();                       
            void revive();                     
            int coins();                    
            string role();  
            void block(Player);                          
            ~Player() {}
        };
}