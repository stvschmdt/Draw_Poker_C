#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define HAND_SIZE 5
#define NUM_PLAYERS 4
#define DECK_SIZE 52
#define CARDS_PER_HAND 5
#define MCTRIALS 1000

typedef struct card{
	 char *face;
	 char *suit;

} Card;

typedef struct deck{
	 Card deckCards[DECK_SIZE];
	 int cardsDealt;
	 int cardsLeft;
} Deck;

typedef struct player{
	 char *name;
	 Card hand[HAND_SIZE];
	 double handRank;
	 int rupies;
	 int maxBet;
	 int minBet;
	 double rank;
	 int position;
	 int inGame;
	 Card monteCards[DECK_SIZE - HAND_SIZE];
	 float bestPotential;
	 int mc_reco[5];
} Player;

typedef struct table{
	 Player gambler[NUM_PLAYERS];

} Table;

Player player_init(char *name, int rupies);
Deck get_new_Deck();
void shuffle(Deck *newDeck, int deckSize);
int first_Deal(Deck *dealer, Player *table[], int numPlayers);
Card dequeue(Deck playDeck);
void update(Deck *queue);
int exchange(Deck *toDeal, Player *person, int cardNum);
int swap(Deck *dealer, Player *player, int numCards);
int newCards(Deck *dealer, Player *player);
int displayDeck(Deck deck);
int displayCard(Card card);
void displayHand(Player *currentPlayer, Card *hand);
char * getName();
int getRupies();
void welcome();
int betAmount();
void print_Hand(Player *table[], int playerNum);
int got_dealt();
int isHand(Card *hand);
Deck create_Monte(Player *person);
void print_Options();
double monte_Analysis(Deck *deck, Player *person);
void dealMC(Deck *deck);
void print_Dummy(Player *player);
double handRank(Player *player);
int handCompareTo(Player *p1, Player *p2);
char * winnerIs(Player *table[]);
int exchangeMC(Deck *toDeal, Player *person, int cardNum);
void updateMC(Deck *queue);
