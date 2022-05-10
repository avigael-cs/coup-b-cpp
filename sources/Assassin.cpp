#include "Assassin.hpp"
#include <iostream>
using namespace coup;

namespace coup {
    Assassin::Assassin( Game &game , string name ) : Player(game, name) {
        blockedCoup = false;
    }

    void Assassin::coup(Player &player)
    {
        if (!inTheGame()) {
            throw runtime_error("it is not the player's turn.");
        }

        if (numOfCoins < ASSASSINATION_PRICE) {
            throw runtime_error("Player does not have enough coins!");
        }

        game->removePlayer(&player);

        numOfCoins -= ASSASSINATION_PRICE;

		if (blockedCoup) {
			blockedCoup = false;
			game->addPlayer(&player);
		}
    }

    string Assassin::role() const {
        return "Assassin";
    }

	void Assassin::setBlockedCoup(bool blockedCoup) {
		this->blockedCoup = blockedCoup;
	}
}


