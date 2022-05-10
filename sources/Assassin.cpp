#include <iostream>
#include "Assassin.hpp"

namespace coup {
	Assassin::Assassin( Game &game , string  name) : Player(game, std::move(name)) {
		killed = nullptr;
	}

	void Assassin::coup(Player &player)
	{
		if (coins() >= COUP_PRICE) {
			Player::coup(player);
			return;
		}

		if (!inTheGame()) {
			throw runtime_error("it is not the player's turn.");
		}

		if (!player.isAlive()) {
			throw runtime_error("the player is already dead.");
		}

		if (!inTheGame()) {
			throw runtime_error("it is not the player's turn.");
		}

		if (numOfCoins < ASSASSINATION_PRICE) {
			throw runtime_error("Player does not have enough coins!");
		}

		game->removePlayer(&player);

		plusCoins(-ASSASSINATION_PRICE);

		game->nextTurn();

		killed = &player;

		lastIsForeignAid = false;
	}

	void Assassin::beBlocked()
	{
		if (killed == nullptr) {
			throw runtime_error("kill can't be blocked.");
		}

		killed->revive();
		killed = nullptr;
	}

	string Assassin::role() const {
		return "Assassin";
	}
}


