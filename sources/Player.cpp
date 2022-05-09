#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
//#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
using namespace coup;
const int INIT_COINS = 0;
const int MAX_COINS = 10;
const int COUP_PRICE = 7;

namespace coup
{
    Player::Player(Game & game, string name)
    {
        nameOfPlayer = std::move(name);
        numOfCoins = INIT_COINS;
        id = game.addPlayer(this);
        this->game = &game;
        alive = true;
    }
    Game* Player::getGame() const  
    {
        return game;
    }
    string Player::getNameOfPlayer() const  
    {
        return nameOfPlayer;
    } 
    int Player::getCoins()const 
    {  
        return numOfCoins;
    }
    void Player::plusCoins(int num) 
    {
        this->numOfCoins+=num;
    }
    bool Player::isAlive() const 
    {
          return (alive);
    }     
    void Player::setAlive(bool alive) 
    {
        this->alive = alive;
    }
    void Player::setId(int num) 
    {
        this->id=num;
    }
    int Player::getId() const
    {
        return id;
    }
    bool Player::inTheGame() const{    
        if (!game->isActive()&&game->players().size()<2) {
            throw std::runtime_error("not enough players to start the game!");
        } 
        return game->turnPlayer()==this;
    }








    void Player::coup(Player &player){
        
    }

    void Player::income(){
        if (inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }
        if (numOfCoins>=MAX_COINS) {
            throw runtime_error("Player must coup!");
        }
        
        plusCoins(1);
        game->nextTurn;
        //not finished
    }

    void Player::foreign_aid(){

    }

    void Player::die(){

    }

    void Player::revive(){
        
    }

    void Player::block(Player &player){
        throw runtime_error("Player can't steal");
    }

    int Player::coins(){
        return numOfCoins;
    }

    string Player::role()
    {
        return "Player";
    }

    

}
