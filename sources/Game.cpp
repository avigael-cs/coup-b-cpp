//for this assignement i asked for a freind who works in high-tech to help me because it was very difficulte for me to do it alone

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
		numOfPlayers =0;
	}

	//get list of players
	std::vector<string> Game::players() {
		std::vector<string> vecPlayers;
		for (size_t i = 0; i < playersList.size(); i++) {
			if (playersList.at(i)->isAlive()) {
				vecPlayers.push_back(playersList.at(i)->getNameOfPlayer());
			}
		}
		return vecPlayers;
	}

	Player* Game::turnPlayer() const {
		return turnOfPlayer;
	}

	void Game::setTurnPlayer(Player* player) {
		turnOfPlayer = player;
	}
	
	string Game::turn()
	{
		if (playersList.empty())
		{
			throw std::runtime_error("Error - there are no players !");
		}
		//else (playerList.
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
			throw std::invalid_argument("Error - we have max players capacity");
		}
		if (playersList.empty()) {
			turnOfPlayer = newPlayer;
		}
		this->playersList.push_back(newPlayer);
		//this->players_Pointers_array.push_back(p);
		//id
		newPlayer->setId((int)playersList.size()-1);
		return (int)playersList.size()-1;
	}

	//the function is called when a player is couped. 
	void Game::removePlayer(Player *losePlayer) {
		for (size_t i = 0; i < playersList.size(); i++)
		{
			if (playersList.at(i)==losePlayer) {
				// std::cout << "player " << losePlayer->getNameOfPlayer() << " was removed from the game!\n";
				// playersList[i] = nullptr;
				break;
			}
		}

		losePlayer->setAlive(false);

		//If only one player remaining - the game is finished
		size_t numOfplayers = 0;
		for (size_t i = 0; i < playersList.size(); i++)
		{
			if (playersList.at(i)->isAlive()) {
				numOfplayers++;
			}
		}
		//the player won
		if (numOfplayers == 1) 
		{
			finished = true;
		} 
	}

	bool Game::isActive() const {
		return started && !finished;
	}

	string Game::winner() 
	{
		if (!finished) {
			throw runtime_error("The game is not finish");
		}

		for (Player* player : playersList) {
			if (player->isAlive()) {
				return player->getNameOfPlayer();
			}
		}

		throw runtime_error("The game is not finished");
	}

	void Game::start() {
		if (finished) {
			throw runtime_error("The game is finished");
		}

		if (players().size() < 2) {
			throw runtime_error("not enough players to start the game!");
		}

		started = true;
	}

	void Game::nextTurn() {
		unsigned int i = 0;
		for (Player* player : playersList) {
			if (player == turnOfPlayer) {
				break;
			}
			i++;
		}

		while (true) {
			i++;
			if (i == playersList.size()) {
				i = 0;
			}
			turnOfPlayer = playersList.at(i);
			if (turnOfPlayer->isAlive()) {
				break;
			}
		}
	}
}