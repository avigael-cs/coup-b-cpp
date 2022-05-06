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
    Game* Player::getGame() const  {
        return game;
        }
    string Player::getNameOfPlayer() const  {
        return nameOfPlayer;
        }
    int Player::getCoins()const {  
        return numOfCoins;
        }
    void Player::setCoins(int num) {
        this->numOfCoins+=num;
    }
    bool Player::isAlive() const {
          return alive;
          }     
    void Player::setAlive(bool isAlive) {
        alive = true;
    }
    void Player::setId(int num) {
        this->id=num;
    }












    void Player::coup(Player &player){
        
    }

    void Player::income(){

    }

    void Player::foreign_aid(){

    }

    void Player::die(){

    }

    void Player::revive(){
        
    }

    void Player::block(Player ){

    }

    int Player::coins(){
        int coins=9;
        return coins;
    }

    string Player::role()
    {
        return "Player";
    }

    

}
