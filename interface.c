#include "hedz.h"



/***********************************************************
 *  the interface abstract is to interact with the user and *
 *  return a value to be used by the driver to update the   *
 *  status of the players attributes or the deck functions. *
 *  these are welcome/getName/getRupies/betAmount/newCards  *
 ***********************************************************/
void welcome(){
	 printf("\n\nWELCOME TO SCHMIDTCHUNK CASINO\n");
	 printf("--© 1998-2013 Schmidt Enterprises--\n--------------------------\n\n\n");
	 printf("Mario, Link and Taloon are waiting for you to sit down\n\n");
}

char *getName(){
	 char * name = malloc(sizeof(char)*255);
	 printf("Please type in your name and hit enter\nso you won't be a stranger! -->");
	 scanf("%s",name);
	 printf("\n");

	 return name;
}

int getRupies(){
	 int *rupies;
	 int x = 0;
	 rupies = &x;
	 printf("Please enter how many rupies would you like\nto play poker with today-->");
	 scanf("%i", rupies);
	 printf("\n");

	 return *rupies;
}

int betAmount(Player *one){
	 int *bet;
	 int x =0;
	 bet = &x;
	 printf("How much would you like to wager-->");
	 scanf("%i",bet);
	 one->rupies -= (*bet);
	 printf("\n");

	 return *bet;
}

int newCards(Deck *dealer, Player *player){
	 int *new;
	 int x = 0;
	 new = &x;
	 printf("How many cards would you like?-->");
	 scanf("%i",new);
	 swap(dealer, player, *new);
	 return *new;
}

int swap(Deck *dealer, Player *player, int numCards){
	 int c, i, x = numCards;
	 printf("Please type the letter of the card you would like to exchange-->");
	 while(x > 0){
		  c = getchar();
		  if(c == ' '){

		  }

		  else if(c == 'a'){
				i = 0;
				x--;
				exchange(dealer, player, i);
		  }

		  else if(c == 'b'){
				i = 1;
				x--;
				exchange(dealer, player, i);
		  }

		  else if(c == 'c'){
				i = 2;
				x--;
				exchange(dealer, player, i);
		  }

		  else if(c == 'd'){
				i = 3;
				x--;
				exchange(dealer, player, i);
		  }
		  else if(c == 'e'){
				i = 4;
				x--;
				exchange(dealer, player, i);
		  }
	 }

	 return 0;
}

/************************************************************
 *  displayDeck, displayCard and print_Hand are interface   *
 *  functions for interactions with the user. displayDeck   *
 *  is mostly used for testing, but displayCard is of great *
 *  importance for the exchange functions.                  *
 ***********************************************************/

int displayDeck(Deck deck){
	 int i;
	 printf("\n");
	 for(i=0;i<DECK_SIZE;i++){
		  printf("%s%s ",deck.deckCards[i].face, deck.deckCards[i].suit);
	 }
	 printf("\n");

	 return 0;
}

int displayCard(Card card){
	 printf("%s%s", card.face, card.suit);

	 return 0;
}

void displayHand(Player *currentPlayer, Card *hand){
	 int i;
	 for (i=0;i<HAND_SIZE; i++){
		  printf(" %s %s ", hand[i].face, hand[i].suit);
	 }
}

/***********************************************************
 *  this is the main print function for displaying a persons*
 *  hand with user name and format.                   r     *
 ***********************************************************/

void print_Hand(Player *table[], int playerNum){
	 if(playerNum == 1){
		  printf("\n");
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[0]->name, table[0]->hand[0].face, table[0]->hand[0].suit, table[0]->hand[1].face, table[0]->hand[1].suit, table[0]->hand[2].face, table[0]->hand[2].suit, table[0]->hand[3].face, table[0]->hand[3].suit, table[0]->hand[4].face, table[0]->hand[4].suit);
	 }
	 else if(playerNum == 2){
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[1]->name, table[1]->hand[0].face, table[1]->hand[0].suit, table[1]->hand[1].face, table[1]->hand[1].suit, table[1]->hand[2].face, table[1]->hand[2].suit, table[1]->hand[3].face, table[1]->hand[3].suit, table[1]->hand[4].face, table[1]->hand[4].suit);
	 }
	 else if(playerNum == 3){
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[2]->name, table[2]->hand[0].face, table[2]->hand[0].suit, table[2]->hand[1].face, table[2]->hand[1].suit, table[2]->hand[2].face, table[2]->hand[2].suit, table[2]->hand[3].face, table[2]->hand[3].suit, table[2]->hand[4].face, table[2]->hand[4].suit);
	 }
	 else if(playerNum == 4){
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[3]->name, table[3]->hand[0].face, table[3]->hand[0].suit, table[3]->hand[1].face, table[3]->hand[1].suit, table[3]->hand[2].face, table[3]->hand[2].suit, table[3]->hand[3].face, table[3]->hand[3].suit, table[3]->hand[4].face, table[3]->hand[4].suit);
	 }
}

/***********************************************************
 *  print_Dummy and print_Options are interface interaction *
 *  functions which allow the gui to operate as a poker     *
 *  interface should. These are 'easy' calls from the driver*
 *  for game flow.                                          *
 ***********************************************************/

void print_Dummy(Player *player){
	 int i;
	 printf("%s\n", player->name);
	 for(i = 0;i<HAND_SIZE;i++){
		  printf(" 🂠  ");

	 }
	 printf("\n");
}

void print_Options(){

	 printf(" a   b   c   d   e  \n\n");
	 printf("******************************************************\n*please select which cards would you like to exchange*\n*by typing the letter below the card followed by the *\n*space bar. For example:a d                          *\n****************************************************** \n");

}
