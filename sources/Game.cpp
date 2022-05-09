#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Game.hpp"
const int MAX_NUM_OF_PLAYER = 6;
namespace coup {

    Game::Game() {
        started = false;
        finished = false;
        turnOfPlayer = nullptr;
    }

    //get list of players
    vector<string> Game::players()
    {
        vector<string> vecPlayers;
        for (size_t i = 0; i < playersList.size(); i++)
        {
            if (playersList.at(i)!=nullptr) {
                vecPlayers.push_back(playersList.at(i)->getNameOfPlayer());
            }
        }
        return vecPlayers;
    }
    Player* Game::turnPlayer() const{
        return turnOfPlayer;
    }
    
    string Game::turn()
    {
        if (playersList.empty())
        {
            throw "Error - no players !";
        }
        return turnOfPlayer->getNameOfPlayer();
    }
    
    //the function add the player to the game and returns the ID of the player.
    int Game::addPlayer(Player *newPlayer) 
    {
        if(started||finished) {
            throw std::runtime_error("can't add new players at this stage");
        }
        if (playersList.size() == MAX_NUM_OF_PLAYER)
        {
            throw invalid_argument("Error we have max players capacity");
        }
        if (playersList.empty()) {
            turnOfPlayer = newPlayer;
        }
        playersList.push_back(newPlayer);
        //id
        newPlayer->setId(playersList.size()-1);
        return playersList.size()-1;
    }

    //the function is called when a player is couped. 
    void Game::removePlayer(Player *losePlayer) {
        for (size_t i = 0; i < playersList.size(); i++)
        {
            if (playersList.at(i)==losePlayer) {
                cout << "\t\player " << losePlayer->getNameOfPlayer() << "was removed from the game!\n";
                playersList[i] = nullptr;
                break;
            }
        }
        losePlayer->setAlive(false);
        //If only one player remaining - the game is finished
        size_t numOfplayers = 0;
        for (size_t i = 0; i < playersList.size(); i++)
        {
            if (playersList.at(i)!=nullptr) {
                numOfplayers++;
            }
        }
        //the player won
        if (numOfplayers == 1) 
        {
            finished = true;
        } 
    }


    bool Game::isActive() const{
       
    }

    string Game::winner() 
    {
        if (!finished) {
            throw runtime_error("the game is not finish");
        }
        for (size_t i = 0; i < playersList.size(); i++)
        {
            if (playersList.at(i)!=nullptr) {
                return playersList.at(i)->getNameOfPlayer();
            }
        }
        return "error";
    }
}