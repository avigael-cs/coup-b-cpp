#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
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
        bool alive;
        Game *game;
        int numOfCoins;
        map <string , Player*> lastAction;
        int id;
        string last_operation;
            
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
            Player::Player();            
            void coup(Player &player); //to "kill" given player.
            void income();  // recieving 1 coin from the treasury                   
            void foreign_aid(); // receiving 2 coins from the treasury (that action can be blocked by duke)           
            void die();                       
            void revive();                     
            int coins();                    
            string role();  
            void block(Player &player);                          
            ~Player() {}
        };
}