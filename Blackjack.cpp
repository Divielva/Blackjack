#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

int Player;
int House;
int gameWon;
char gameStart;
int playerScore = 0;
int houseScore = 0;
int Card;
int Ace;
int playerCapital = 100;
int houseCapital = 100;
int playerBet;


int main() {
    
	srand(time(NULL));
	std::cout << "------------------------" << std::endl;
	std::cout << "| WELCOME TO BLACKJACK |" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "                        " << std::endl;
	std::cout << "It will be 10$ to play  " << std::endl;
	std::cout << "You Have " << playerCapital << "$" << std::endl;
	std::cout << "The house has " << houseCapital << "$" << std::endl;
	std::cout << "                        " << std::endl;
	std::cout << "Do you want to play? y/n : ";
	std::cin >> gameStart;

	if (gameStart == 'y' || gameStart == 'Y') {
		playerCapital -= 10;
		houseCapital -= 10;
		std::cout << "You have " << playerCapital << "$" << std::endl;

		while (gameStart == 'y' || gameStart == 'Y') {

			playerScore = 0;
			houseScore = 0;

			while (playerScore < 21) {
				std::cout << "                           " << std::endl;
				std::cout << "-----------------------" << std::endl;
				std::cout << "| 1. Draw a card      |" << std::endl;
				std::cout << "| 2. Stay (End round) |" << std::endl;
				std::cout << "-----------------------" << std::endl;
				std::cout << "Player answer : ";
				std::cin >> Player;

				if (Player == 1) {
					Card = rand() % 13 + 1;
					std::cout << "     " << std::endl;
					std::cout << "You drew : " << Card << std::endl;

					//if the player draws 1, the if statement below starts
					//the player can choose if they want ace to be 1 or 11
					if (Card == 1) {
						std::cout << "                                 " << std::endl;
						std::cout << "You drew a Ace, it can be 1 or 11" << std::endl;
						std::cout << "Your choice : ";
						std::cin >> Ace;
						std::cout << "                                  " << std::endl;
						if (Ace == 1) {
							Card = 1;
						}
						if (Ace == 11) {
							Card = 11;
						}
						else {
							std::cout << "                           " << std::endl;
							std::cout << "That is not a valid number for the Ace" << std::endl;
						}
					}
					else if (Card > 10) {
						std::cout << "                   " << std::endl;
						std::cout << "You drew a face card, those counts as 10" << std::endl;
						Card = 10;
					}

					//adds the playerscore together and shows the player after each draw
					playerScore += Card;
					std::cout << "|--------------- " << std::endl;
					std::cout << "| Player score : " << playerScore << std::endl;
					std::cout << "|--------------- " << std::endl;
				}
				if (Player == 2) {
					std::cout << "Ending Player round";
					std::cout << "                   " << std::endl;
					break;
				}
				else if (Player >= 3) {
					std::cout << "That is not a valid answer" << std::endl;
				}
			}

			//Check if player has blackjack or has lost
			if (playerScore > 21) {
				std::cout << "                        " << std::endl;
				std::cout << "YOU LOST, THE HOUSE WINS" << std::endl;
				std::cout << "                        " << std::endl;
				houseCapital += 20;
				char temp = 'y';
				std::cout << "                        " << std::endl;
				std::cout << "To play again it will be 10$" << std::endl;
				std::cout << "Would you like to play again? y/n: ";
				std::cin >> temp;
				if (temp == 'y') {
					playerCapital -= 10;
					std::cout << "                        " << std::endl;
					std::cout << "|-----------------------" << std::endl;
					std::cout << "| Your current capital :" << playerCapital << "$" << std::endl;
					std::cout << "|-----------------------" << std::endl;
					std::cout << "                           " << std::endl;
					continue;
				} else
					break;
			}
			else if (playerScore == 21) {
				std::cout << "                           " << std::endl;
				std::cout << "BLACKJACK! THE PLAYER WINS!" << std::endl;
				playerCapital += 20;
				std::cout << "                           " << std::endl;
				std::cout << "|---------------------" << std::endl;
				std::cout << "| Your current score :" << playerCapital << "$" << std::endl;
				std::cout << "|---------------------" << std::endl;
				std::cout << "                           " << std::endl;
				char temp = 'y';
				std::cout << "Would you like to play again? y/n: ";
				std::cin >> temp;
				if (temp == 'y')
					continue;
				else
					break;
			}
			else {
				//placing your bet before the house begins its turn
				//you can bet up to the houses $
				std::cout << "                  " << std::endl;
				std::cout << "|---------------| " << std::endl;
				std::cout << "| BETTING ROUND | " << std::endl;
				std::cout << "|---------------| " << std::endl;
				std::cout << "                  " << std::endl;
				std::cout << "Place a bet       " << std::endl;
				std::cout << "You can bet up to " << (houseCapital < playerCapital ? houseCapital : playerCapital) << "$" << std::endl;
				std::cout << "You bet : ";
				std::cin >> playerBet;
				std::cout << "                    " << std::endl;
				std::cout << "|------------------ " << std::endl;
				std::cout << "| Your placed bet : " << playerBet << "$" << std::endl;
				std::cout << "|------------------ " << std::endl;
				std::cout << "                    " << std::endl;
				playerCapital -= playerBet;
				houseCapital -= playerBet;
			}
			Card = 0;
				while (houseScore <= 21) {
					if (houseScore > playerScore) {
						break;
					}

					std::cout << "                     " << std::endl;
					std::cout << "The house draws cards" << std::endl;
					Card = rand() % 13 + 1;

					//if the house has 10 or less in total score it will choose 11 if it draws a ace
					//whilst if it has above 10, it will choose 1 to not lose instantly
					std::cout << "                 " << std::endl;
					std::cout << "The house drew : " << Card << std::endl;
					if (Card == 1) {
						if (houseScore > 10) {
							Card = 1;
						}
						else if (houseScore <= 10) {
							Card = 11;
						}
					}
					else if (Card > 10) {
						Card = 10;
					}
					houseScore += Card;
					std::cout << "                 " << std::endl;
					std::cout << "|----------------" << std::endl;
					std::cout << "| Houses score : " << houseScore << std::endl;
					std::cout << "|----------------" << std::endl;
				}

			//Compare player and house to see if player wins, loses or there's a draw
			if (houseScore > 21) {
				std::cout << "                            " << std::endl;
				std::cout << "THE HOUSE LOSES, PLAYER WINS" << std::endl;
				std::cout << "                            " << std::endl;
				playerCapital += playerBet * 2;
				std::cout << "|-----------------------" << std::endl;
				std::cout << "| Your current capital :" << playerCapital << "$" << std::endl;
				std::cout << "| The houses capital   :" << houseCapital << "$" << std::endl;
				std::cout << "|-----------------------" << std::endl;
				if (houseCapital <= 0) {
					std::cout << "                                                     " << std::endl;
					std::cout << "THE HOUSE HAS GONE BANKRUPT, THE PLAYER WINS THE GAME" << std::endl;
					std::cout << "CONGRATULATIONS PLAYER, YOU ARE INCREDIBLE           " << std::endl;
					std::cout << "                                                     " << std::endl;
					return 0;
				}
				else if (houseCapital > 0) {
					continue;
				}
			}
			else if (playerScore > houseScore) {
				std::cout << "                            " << std::endl;
				std::cout << "THE HOUSE LOSES, PLAYER WINS" << std::endl;
				std::cout << "                            " << std::endl;
				playerCapital += playerBet *2;
				std::cout << "|-----------------------" << std::endl;
				std::cout << "| Your current capital :" << playerCapital << "$" << std::endl;
				std::cout << "| The houses capital   :" << houseCapital << "$" << std::endl;
				std::cout << "|-----------------------" << std::endl;
				if (houseCapital <= 0) {
					std::cout << "                                                     " << std::endl;
					std::cout << "THE HOUSE HAS GONE BANKRUPT, THE PLAYER WINS THE GAME" << std::endl;
					std::cout << "CONGRATULATIONS PLAYER, YOU ARE INCREDIBLE           " << std::endl;
					std::cout << "                                                     " << std::endl;
					return 0;
				}
				else if (houseCapital > 0) {
					continue;
				}
			}
			else if (houseScore > playerScore) {
				std::cout << "                                  " << std::endl;
				std::cout << " THE HOUSE WINS, THE PLAYER LOSES " << std::endl;
				std::cout << "                                  " << std::endl;
				houseCapital += playerBet * 2;
				std::cout << "|-----------------------" << std::endl;
				std::cout << "| Your current capital :" << playerCapital << "$" << std::endl;
				std::cout << "| The houses capital   :" << houseCapital << "$" << std::endl;
				std::cout << "|-----------------------" << std::endl;
				if (playerCapital < 10) {
					std::cout << "                                                     " << std::endl;
					std::cout << "THE PLAYER HAS RUN OUT OF MONEY, THE HOUSE WINS      " << std::endl;
					std::cout << "BETTER LUCK NEXT TIME                                " << std::endl;
					std::cout << "                                                     " << std::endl;
					return 0;
				}
				else if (playerCapital >= 10) {
					std::cout << "                                                     " << std::endl;
					char temp = 'y';
					std::cout << "Would you like to try your luck again?" << std::endl;
					std::cout << "It will be 10$ to try again : ";
					std::cin >> temp;
					if (temp == 'y') {
						playerCapital -= 10;
						continue;
					} else
						break;
				}
			}
			else if (playerScore == houseScore) {
				std::cout << "ITS A TIE" << std::endl;
				std::cout << "                                   " << std::endl;
				char temp = 'y' || 'Y';
				std::cout << "Do you want to play again? y/n : ";
				std::cin >> temp;
				if (temp == 'y' || temp == 'Y')
					continue;
			}
			else
				break;
			
		}

			
	} 
    else {
    std::cout << "Goodbye";
    return 0;
    }
	
}
