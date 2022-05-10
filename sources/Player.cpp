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
		nameOfPlayer = move(name);
		numOfCoins = INIT_COINS;
		id = game.addPlayer(this);
		this->game = &game;
		alive = true;
		lastIsForeignAid = false;
	}

	Game* Player::getGame() const  
	{
		return game;
	}
	string Player::getNameOfPlayer() const  
	{
		return nameOfPlayer;
	} 
	int Player::coins()const 
	{  
		return numOfCoins;
	}
	void Player::plusCoins(int num) 
	{
		if (/*numOfCoins+num > MAX_COINS ||*/ numOfCoins+num < 0) {
			throw runtime_error("invalid change of coins");
		}

		numOfCoins += num;
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
	void Player::beBlocked() {
		throw runtime_error("player can't be blcoked.");
	}
	void Player::beBlockedForeignAid() {
		if (!lastIsForeignAid) {
			throw runtime_error("player's last action is not foreign aid.");
		}
		plusCoins(-2);
	}
	int Player::getId() const
	{
		return id;
	}
	bool Player::inTheGame() const{
		game->start();
		/*if (!game->isActive()) {
			throw runtime_error("not enough players to start the game!");
		}*/
		return game->turnPlayer() == this;
	}

	void Player::coup(Player& player) {
		if (!player.isAlive()) {
			throw runtime_error("the player is already dead.");
		}

		if (!inTheGame()) {
			throw runtime_error("it is not the player's turn.");
		}

		if (numOfCoins < COUP_PRICE) {
			throw runtime_error("Player does not have enough coins!");
		}

		game->removePlayer(&player);

		plusCoins(-COUP_PRICE);

		lastIsForeignAid = false;

		game->nextTurn();
	}

	void Player::income(){
		if (!inTheGame()) {
			throw runtime_error("it is not the player's turn.");
		}

		if (numOfCoins>=MAX_COINS) {
			throw runtime_error("Player must coup!");
		}
		
		plusCoins(1);

		lastIsForeignAid = false;

		game->nextTurn();
	}

	void Player::foreign_aid(){
		if (!inTheGame()) {
			throw runtime_error("it is not the player's turn.");
		}

		if (numOfCoins>=MAX_COINS) {
			throw runtime_error("Player must coup!");
		}
		
		plusCoins(2);

		lastIsForeignAid = true;

		game->nextTurn();
	}

	void Player::die(){
		game->removePlayer(this);
	}

	void Player::revive(){
		setAlive(true);
		// game->addPlayer(this);
	}

	void Player::block(Player &player){
		throw runtime_error("Player can't block");
	}

	string Player::role() const
	{
		return "Player";
	}
}
