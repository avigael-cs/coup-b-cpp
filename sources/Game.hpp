//In the beggining of the game every player that joined the game will get a random role every role has it owns abillities the goal of the game its to coup all the players around with coins and strategy actions with them.

// If player has 10 coins in the beggining of his turn he must coup someone.
// Blocking doesnt need to be in the player's turn (could do it everytime) and doesnt spending turn.
// Turns will be determinate following the join order.

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include "Player.hpp"


//using namespace coup;
//using namespace std;
using std::string;
using std::vector;

namespace coup
{
	class Game{
		bool started;
		bool finished;
		vector<string> playersNames;
		vector<Player*> playersList;
		Player *turnOfPlayer;
		int numOfPlayers;
		
		const int MAX_PLAYER = 6;

	public:
		//getters
		/* --- functions --- */
		Game();
		~Game() {}

		int addPlayer(Player *); //Adding the given player to the game (Cannot be added if the game has been started.)
		void removePlayer(Player *);
		bool isActive() const;
		void nextTurn();
		Player *turnPlayer() const;
		void setTurnPlayer(Player* player);
		std::vector<string> players(); //- returns the active players data structor.
		string turn(); //- returns the name of the player who playing right now.
		string winner(); //returns the winner name only if the game is over.
		void start();
	};
}   
	