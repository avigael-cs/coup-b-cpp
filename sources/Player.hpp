#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <stdlib.h>
#include <exception>

//using namespace coup;
using std::string;
using std::runtime_error;

namespace coup {
    class Game;

    class Player 
    {
    protected:
        string nameOfPlayer;
        bool alive;
        Game *game;
        int numOfCoins;
        int id;
        bool lastIsForeignAid;
            
    public:
        static const int INIT_COINS = 0;
        static const int MAX_COINS = 10;
        static const int COUP_PRICE = 7;

        Player(Game& game, string name);         
        ~Player() {}

        /* --- getters --- */
        Game* getGame() const;
        string getNameOfPlayer() const;
        
        // bool didForeign() const;
        // bool isInGame(Player &);
        
        bool isAlive() const;
        virtual string role() const;
        int coins() const;
        int getId() const;
        bool inTheGame() const;

        /* --- setters --- */
        void setAlive(bool);
        void plusCoins(int);
        void setId(int);
        virtual void beBlocked();
        void beBlockedForeignAid();

        virtual void coup(Player &player); //to "kill" the player.
        void income();  // get 1 coin from the game                   
        void foreign_aid(); // get 2 coins from the game - this action can be blocked by duke           
        void die();                       
        void revive();                                       

        virtual void block(Player &player);
    };
}