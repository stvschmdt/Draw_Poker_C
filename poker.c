#include "hedz.h"

int main(){

	 int bets = 0, pot = 0;

	 Deck game_deck = get_new_Deck();


	 welcome();

	 printf("\n");
	 hBorder();
	 printf("\n");

	 Player one = player_init(getName(), getRupies());
	 printf("Hi %s, you have %i rupies\n",one.name, one.rupies);
	 Player two = player_init("Link", one.rupies);
	 Player three = player_init("Mario", one.rupies);
	 Player four = player_init("Taloon", one.rupies);
	 getStatus(&two);
	 getStatus(&three);
	 getStatus(&four);
	 printf("\n");
	 printf("\n");
	 hBorder();	 

	 Player *table[NUM_PLAYERS];

	 table[0] = &one;
	 table[1] = &two;
	 table[2] = &three;
	 table[3] = &four;

	 int gamenumber = 1;

	 while(gamenumber == 1){
		  printf("\n");
		  printf("\nREADY -- Here we go...\n\n");
		  shuffle(&game_deck, DECK_SIZE);
		  first_Deal(&game_deck, table, NUM_PLAYERS);
		  gamescene(3, table);

		  print_Hand(table, 1);
		  isHand(one.hand);
		  bets = betAmount(&one);
		  hBorder();
		  pot += bets;
		  printf("%s, bets %i rupies\n",one.name, bets);
		  pot += bets;
		  printf("%s, bets %i rupies\n",two.name, bets);
		  pot += bets;
		  printf("%s, bets %i rupies\n",three.name, bets);
		  pot += bets;
		  printf("%s, bets %i rupies\n",four.name, bets);
		  pot += bets;
		  printf("\n");
		  printf("The pot size is %i rupies\n",pot);
		  printf("\n");
		  printf("You have %i rupies left\n\n",one.rupies);
		  print_Hand(table, 1);
		  print_Options();
		  isHand(one.hand);

		  Deck MC_Deck = create_Monte(&one);
		  printf("Monte says this is what you should look to do: %f \n", monte_Analysis(&MC_Deck, &one));
		  printf("Recommended exchange is: %i %i %i %i %i\n\n", one.mc_reco[0], one.mc_reco[1],one.mc_reco[2],one.mc_reco[3],one.mc_reco[4]);

		  newCards(&game_deck,&one);
		  print_Hand(table, 1);
		  isHand(one.hand);
		  printf("\n");
		  printf("\n");
		  bets = betAmount(&one);
		  pot += bets;
		  hBorder();
		  print_Hand(table, 1);
		  isHand(one.hand);
		  print_Hand(table, 2);
		  isHand(two.hand);
		  print_Hand(table, 3);
		  isHand(three.hand);
		  print_Hand(table, 4);
		  isHand(four.hand);

		  handRank(&one);
		  handRank(&two);
		  handRank(&three);
		  handRank(&four);

		  handCompareTo(&one, &two);
		  handCompareTo(&one, &three);
		  handCompareTo(&one, &four);
		  handCompareTo(&two, &three);
		  handCompareTo(&two, &four);
		  handCompareTo(&three, &four);
		  /*for testing*/
		  printf("Player one's position point: %i\nPlayer two's position point: %i\nPlayer three's position point: %i\nPlayer four's positions point: %i\n", one.position, two.position, three.position, four.position);

		  winnerIs(table, pot);
		  hBorder();
		  printf("\n");

		  gamenumber = playgame();
		  printf("\n");
		  printf("\n");
		  printf("\n");
		  printf("\n");
		  tableRefresh(table);
	 }
	 return 0;
}
