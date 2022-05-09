#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "Player.hpp"
const int MAX_PLAYER = 6;
//using namespace coup;
using namespace std;

namespace coup
{
    class Game{
        bool gameStart;
        bool gameFinish;
        vector<Player *> allPlayers;
        Player *turnOfPlayer;
        private:   

        public:
            //getters
              /* --- functions --- */
            void revivePlayer(Player *);
            int addPlayer(Player *);
            void removePlayer(Player *);
            bool Game::isActive() const;
            void nextTurn();
            Player *turnPlayer() const;
            Game();
            //void add_player(Player &player);
            vector<string> players();
            string turn();
            string Game::winner();
            ~Game() {}
    };
    
    
}

   
    