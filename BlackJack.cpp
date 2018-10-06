#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// Enumerations
enum CardRank
{
	RANK_2 = 0,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
};

enum Suit
{
	SUIT_CLUBS = 1, // Suit Enumeration must begin at 1 to ensure deck creation does not lead to undefined behaviour
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES,
};

enum BlackjackResult
{
    BLACKJACK_PLAYER_WIN,
    BLACKJACK_DEALER_WIN,
    BLACKJACK_TIE
};

// Structs
struct Card
{
	CardRank rank;
	Suit suit;
};

// global variable
int constexpr deckSize{52};


// Functions
void printCard(const Card &card) {
	std::string res{};
	switch(card.rank) {
		case RANK_2:
		res+= "2";
		break;
		case RANK_3:
		res+= "3";
		break;
		case RANK_4: 
		res+= "4";
		break;
		case RANK_5:
		res+= "5";
		break;
		case RANK_6:
		res+="6";
		break;
		case RANK_7:
		res+="7";
		break;
		case RANK_8:
		res+="8";
		break;
		case RANK_9:
		res+="9";
		break;
		case RANK_10:
		res+="10";
		break;
		case RANK_JACK:
		res+="J";
		break;
		case RANK_QUEEN:
		res+="Q";
		break;
		case RANK_KING:
		res+="K";
		break;
		case RANK_ACE:
		res+="A";
		break;
		default:
		std::cout << "Invalid Card\n";
		break; 
	} 

	switch(card.suit) {
		case SUIT_CLUBS:
		res+="C";
		break;
		case SUIT_DIAMONDS:
		res+="D";
		break;
		case SUIT_HEARTS:
		res+="H";
		break;
		case SUIT_SPADES:
		res+="S";
		break;
		default:
		break;
	}
	std::cout << res;
}
void printDeck(const std::array<Card,deckSize> &deck) {
	for (auto &card : deck) {
		printCard(card);
	}
}

void swapCard(Card &a, Card &b) {
	Card temp;
	temp = a;
	a = b;
	b = temp;
}

// Function introduced from lesson 5.9
int getRandomNumber(int min, int max) {
	static const double fraction = 1.0/ (RAND_MAX +1.0);
	return min + static_cast<int>((max - min +1) * (std::rand() *fraction));
}

void shuffleDeck(std::array<Card,deckSize> &deck) {
	for (int i{0}; i < deck.size(); ++i) {
		std::swap(deck[i], deck[getRandomNumber(0,51)]);
	}
}

int getCardValue(Card const &card) {
	switch(card.rank) {
		case RANK_ACE:
		return 11;
		case RANK_KING: 
		return 10;
		case RANK_JACK:
		return 10;
		case RANK_QUEEN:
		return 10;
		default:
		return (card.rank+2);
	}
}

BlackjackResult getWinner(const int a, const int b) {
	if(a > b) {
		return BLACKJACK_PLAYER_WIN;
	} else if (a == b) {
		return BLACKJACK_TIE;
	} else {
		return BLACKJACK_DEALER_WIN;
	}
}

BlackjackResult playBlackJack(std::array<Card,deckSize> &deck) {
	Card *cardPtr{&deck[0]};
	int playerScore{0};
	int dealerScore{0};
	bool isOver{false};

	std::cout << "Let's play BlackJack!\n";

	dealerScore+=getCardValue(*cardPtr++);
	std::cout << "Dealer's score: " << dealerScore << '\n';
	playerScore+=getCardValue(*cardPtr++);
	playerScore+=getCardValue(*cardPtr++);
	
		
		std::string playerChoice{};

		// @std::string::operator==(const char*) is a thing for l168
		while (playerChoice != "stand") {
			std::cout << "Your current score: " << playerScore << '\n';
			std::cout<< "Do you choose to \"hit\" or \"stand\"?\n";
			std::cin >> playerChoice;

			if(playerChoice == "hit") {
				playerScore+=getCardValue(*cardPtr++);
			} else if(playerChoice != "stand") {
				std::cout << "Wrong Input! Try again \n";
			}
			

			if(playerScore > 21) {
				std::cout << "Your current score: " << playerScore << "\nBUST!\n";
				return BLACKJACK_DEALER_WIN;
			}
		}

		while(dealerScore < 17) {
			dealerScore+=getCardValue(*cardPtr++);
			if(dealerScore > 21) {
				std::cout << "Dealer hit over 21!\n";
				return BLACKJACK_PLAYER_WIN;
			}
		}
		std::cout <<"Dealer's score: " << dealerScore << '\n';

	return getWinner(playerScore,dealerScore);
}

int main() {

	// Variables
	int currSuit{0}; 
	int currRank{0};
	std::array<Card,deckSize> deck;
	std::srand(static_cast<unsigned int>(std::time(0)));

	for(int i{0}; i< deckSize; ++i) {
		if(i % 13 == 0) { // 13 is a magic number to refresh card rank and repeat the process for the next suit
			++currSuit; 
			currRank = 0;
		}
		Card currCard;
		currCard.rank = static_cast<CardRank>(currRank);
		currCard.suit = static_cast<Suit>(currSuit);
		deck[i] = currCard;
		++currRank;
	}

	shuffleDeck(deck);
	
	switch(playBlackJack(deck)) {
		case BLACKJACK_PLAYER_WIN:
			std::cout << "You win!\n";
			break;
		case BLACKJACK_DEALER_WIN:
			std::cout << "You lose!\n";
			break;
		case BLACKJACK_TIE:
			std::cout << "A tie !\n";
			break;
	}

	return 0;
}

/* === SUMMARY =====
Original Imeplementation : sacrifice readability for efficiency
void printCard(const Card &card) {
	std::string res{""};
	switch(card.rank) {
		case 9:
			res+= "J";
			break;
		case 10:
			res+= "Q";
			break;
		case 11: 
			res+= "K";
			break;
		case 12:
			res+= "A";
			break;
		default:
			std::string var = std::to_string(card.rank+2);
			res+= var;
			break; 
	} 

	switch(card.suit) {
		case 1:
			res+="C";
			break;
		case 2:
			res+="D";
			break;
		case 3:
			res+="H";
			break;
		case 4:
			res+="S";
			break;
		default:
			break;
	}
	std::cout << res << '\n';
}
 */ 
