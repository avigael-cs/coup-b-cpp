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
        static const int INIT_COINS = 0;
        static const int MAX_COINS = 10;
        static const int COUP_PRICE = 7;

        string nameOfPlayer;
        string Role_NameOfPlayer;
        bool alive;
        Game *game;
        int numOfCoins;
        std::map<string , Player*> lastAction;
        int id;
        string last_operation;
        bool blockedForeignAdd;
            
    public:
        Player(Game& game, string name);         
        ~Player() {}

        /* --- getters --- */
        Game* getGame() const;
        string getNameOfPlayer() const;
        
        // bool didForeign() const;
        // bool isInGame(Player &);
        
        bool isAlive() const;
        virtual std::string role() const;
        int getCoins() const;
        int getId() const;
        bool inTheGame() const;

        /* --- setters --- */
        void setAlive(bool);
        void plusCoins(int);
        void setId(int);
        void setBlcokedForeignAdd(bool);
        virtual void setBlockedCoup(bool);
        virtual void setBlockedSteal(bool);
        // virtual void resetPlayer();

        virtual void coup(Player &player); //to "kill" the player.
        void income();  // get 1 coin from the game                   
        void foreign_aid(); // get 2 coins from the game (that action can be blocked by duke)           
        void die();                       
        void revive();                     
        int coins();                    

        virtual void block(Player &player);
    };
}