#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Game.hpp"
const int MAX_NUM_OF_PLAYER = 6;
namespace coup {

    Game::Game() {
        gameStart = false;
        gameFinish = false;
        playerTurn = nullptr;
    }

    //get list of players
    vector<string> Game::players()
    {
        vector<string> vecPlayers;
        for (size_t i = 0; i < allPlayers.size(); i++)
        {
            if (allPlayers.at(i)!=nullptr) {
                vecPlayers.push_back(allPlayers.at(i)->getNameOfPlayer());
            }
        }
        return vecPlayers;
    }

    string Game::turn()
    {
        if (allPlayers.empty())
        {
            throw "Error - no players !";
        }
        return playerTurn->getNameOfPlayer();
    }
    
    //the function add the player to the game and returns the ID of the player.
    int Game::addPlayer(Player *newPlayer) 
    {
        if(gameStart||gameFinish) {
            throw std::runtime_error("can't add new players at this stage");
        }
        if (allPlayers.size() == MAX_NUM_OF_PLAYER)
        {
            throw invalid_argument("Error we have max players capacity");
        }
        if (allPlayers.empty()) {
            playerTurn = newPlayer;
        }
        allPlayers.push_back(newPlayer);
        //id
        newPlayer->setId(allPlayers.size()-1);
        return allPlayers.size()-1;
    }

    //the function is called when a player is couped. 
    void Game::removePlayer(Player *losePlayer) {
        for (size_t i = 0; i < allPlayers.size(); i++)
        {
            if (allPlayers.at(i)==losePlayer) {
                std::cout << "\t\player " << losePlayer->getNameOfPlayer() << "was removed from the game!\n";
                allPlayers[i] = nullptr;
                break;
            }
        }
        losePlayer->setAlive(false);
        //If only one player remaining - the game is finished
        size_t numOfplayers = 0;
        for (size_t i = 0; i < allPlayers.size(); i++)
        {
            if (allPlayers.at(i)!=nullptr) {
                numOfplayers++;
            }
        }
        //the player won
        if (numOfplayers == 1) 
        {
            gameFinish = true;
        } 
    }

    string Game::winner() 
    {
        if (!gameFinish) {
            throw runtime_error("the game is not finish");
        }
        for (size_t i = 0; i < allPlayers.size(); i++)
        {
            if (allPlayers.at(i)!=nullptr) {
                return allPlayers.at(i)->getNameOfPlayer();
            }
        }
        return "error";
    }
}