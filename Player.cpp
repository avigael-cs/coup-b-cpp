#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iostream>
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

namespace coup
{
	// class Game;

    Player::Player(Game& game, string name)
    {
        nameOfPlayer = name;
        numOfCoins = INIT_COINS;
        id = game.addPlayer(this);
        this->game = &game;
        alive = true;
		blockedForeignAdd = false;
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
		if (this->numOfCoins+num > MAX_COINS || this->numOfCoins+num < 0) {
			throw runtime_error("invalid change of coins");
		}

        this->numOfCoins+=num;
    }
    bool Player::isAlive() const 
    {
          return alive;
    }     
    void Player::setAlive(bool alive) 
    {
        this->alive = alive;
    }
    void Player::setId(int num) 
    {
        this->id=num;
    }
	void Player::setBlcokedForeignAdd(bool blockedForeignAdd) {
		this->blockedForeignAdd = blockedForeignAdd;
	}
	void Player::setBlockedCoup(bool blockedCoup) {
		throw runtime_error("the player is not assassin.");
	}
	void Player::setBlockedSteal(bool blockedCoup) {
		throw runtime_error("the player is not captain.");
	}
    int Player::getId() const
    {
        return id;
    }
    bool Player::inTheGame() const{    
        if (!game->isActive() && game->players().size()<2) {
            throw runtime_error("not enough players to start the game!");
        } 
        return game->turnPlayer() == this;
    }

    void Player::coup(Player& player){
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        if (numOfCoins < COUP_PRICE) {
            throw runtime_error("Player does not have enough coins!");
        }

        game->removePlayer(&player);

		numOfCoins -= COUP_PRICE;
    }

    void Player::income(){
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        if (numOfCoins>=MAX_COINS) {
            throw runtime_error("Player must coup!");
        }
        
        plusCoins(1);
    }

    void Player::foreign_aid(){
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        if (numOfCoins>=MAX_COINS) {
            throw runtime_error("Player must coup!");
        }
        
        plusCoins(2);

		if (blockedForeignAdd) {
			blockedForeignAdd = false;
			plusCoins(-2);
		}
    }

    void Player::die(){
        game->removePlayer(this);
    }

    void Player::revive(){
        game->addPlayer(this);
    }

    void Player::block(Player &player){
        throw runtime_error("Player can't block");
    }

    int Player::coins(){
        return numOfCoins;
    }

    string Player::role() const
    {
        return "Player";
    }
}
