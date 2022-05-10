// #include "Ambassador.hpp"
// #include "Assassin.hpp"
// #include "Captain.hpp"
// #include "Contessa.hpp"
// #include "Duke.hpp"
// #include "Game.hpp"
// #include "Player.hpp"
// #include "doctest.h"
// #include <iostream>
// #include <stdexcept>
// #include <vector>

// using namespace coup;
// using namespace std;

// Game game{};


//     Captain captain{game, "Player1_"};
// 	Duke duke{game, "Player2_"};
// 	Assassin assassin{game, "Player3_"};
// 	Ambassador ambassador{game, "Player4_"};
// 	Contessa contessa{game, "Player5_"};
//     Captain captain2{game, "Player6_"};
// 	vector<string> players = game.players();
    
// TEST_CASE("Good input - Scalar multiplication") {
//     CHECK((players.at(0)) == "Player1_");
// 	CHECK((players.at(1)) == "Player2_");
// 	CHECK((players.at(2)) == "Player3_");
// 	CHECK((players.at(3)) == "Player4_");
// 	CHECK((players.at(4)) == "Player5_");
// 	CHECK((players.at(5)) == "Player6_");
//     captain.income();
//     CHECK((game.turn()) == "Player2_");
// 	duke.tax();
//     captain.income();
//     CHECK((game.turn()) == "Player5_");
// 	duke.tax();
// }
// TEST_CASE("checkDuke") {
//     Game gameBoard{};
//     Duke duke{gameBoard, "Player1_Avi"};
//     Assassin assassin{gameBoard, "Player2_Ron"};
// 	Ambassador ambassador{gameBoard, "Player3_Leo"};
// 	Captain captain{gameBoard, "Player4_Dom"};
// 	Contessa contessa{gameBoard, "Player5_Ori"};
//     CHECK_THROWS(duke.coins());
//     CHECK_THROWS(duke.die());
//     CHECK_THROWS(duke.foreign_aid());
//     CHECK_THROWS(duke.income());
//     CHECK_THROWS(duke.coins());
//     CHECK_THROWS(duke.die());
//     CHECK_THROWS(duke.tax());
//     CHECK_THROWS(duke.revive());
//     CHECK_THROWS(duke.role());
// }

// TEST_CASE("checkAssassin") {
//     Game gameBoard{};
//     Duke duke{gameBoard, "Player1_Avi"};
// 	Assassin assassin{gameBoard, "Player2_Roni"};
// 	//Ambassador ambassador{gameBoard, "Player3_Leo"};
// 	Captain captain{gameBoard, "Player4_Dom"};
// 	Contessa contessa{gameBoard, "Player5_Ori"};
//     CHECK_THROWS(assassin.coins());
//     CHECK_THROWS(assassin.die());
//     CHECK_THROWS(assassin.foreign_aid());
//     CHECK_THROWS(assassin.income());
//     CHECK_THROWS(assassin.revive());
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player2_Roni");
// 	duke.tax();
//     CHECK_THROWS(assassin.role());
// }
// TEST_CASE("checkAmbssador") {
//     Game gameBoard{};
//     Duke duke{gameBoard, "Player1_Avi"};
// 	Assassin assassin{gameBoard, "Player2_Roni"};
// 	Ambassador ambassador{gameBoard, "Player3_Leo"};
// 	Captain captain{gameBoard, "Player4_Dom"};
// 	Contessa contessa{gameBoard, "Player5_Ori"};
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player5_Ori");
// 	duke.tax();
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player4_Dom");
// 	duke.tax();
//     CHECK_THROWS(assassin.role());
//     CHECK_THROWS(ambassador.coins());
//     CHECK_THROWS(ambassador.die());
//     CHECK_THROWS(ambassador.foreign_aid());
//     CHECK_THROWS(ambassador.income());
//     CHECK_THROWS(ambassador.revive());
//     CHECK_THROWS(ambassador.role());
// }
// TEST_CASE("checkCaptain") {
//     Game gameBoard{};
//     Duke duke{gameBoard, "Player1_Avi"};
// 	Assassin assassin{gameBoard, "Player2_Roni"};
// 	Ambassador ambassador{gameBoard, "Player3_Leo"};
// 	Captain captain{gameBoard, "Player4_Dom"};
// 	Contessa contessa{gameBoard, "Player5_Ori"};
//     CHECK_THROWS(captain.coins());
//     CHECK_THROWS(captain.die());
//     CHECK_THROWS(captain.foreign_aid());
//     CHECK_THROWS(captain.income());
//     CHECK_THROWS(captain.revive());
//     CHECK_THROWS(captain.role());
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player1_Avi");
// 	duke.tax();
// }
// TEST_CASE("checkContessa") {
//     Game gameBoard{};
//     Duke duke{gameBoard, "Player1_Avi"};
// 	Assassin assassin{gameBoard, "Player2_Roni"};
// 	Ambassador ambassador{gameBoard, "Player3_Leo"};
// 	Captain captain{gameBoard, "Player4_Dom"};
// 	Contessa contessa{gameBoard, "Player5_Ori"};
//     CHECK_THROWS(contessa.coins());
//     CHECK_THROWS(contessa.die());
//     CHECK_THROWS(contessa.foreign_aid());
//     CHECK_THROWS(contessa.income());
//     CHECK_THROWS(contessa.revive());
//     CHECK_THROWS(contessa.role());
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player1_Avi");
// 	duke.tax();
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player2_Roni");
// 	duke.tax();
//     captain.income();
//     CHECK((gameBoard.turn()) == "Player3_Leo");
// 	duke.tax();
//     //CHECK_THROWS(contessa.block());
// }