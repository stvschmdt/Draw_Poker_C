#include "hedz.h"

int main(){

int bets = 0, pot = 0;
welcome();

printf("\n");
Deck game_deck = get_new_Deck();
shuffle(&game_deck, DECK_SIZE);

printf("\n");

Player one = player_init(getName(), getRupies());
printf("hi %s, you have %i rupies\n",one.name, one.rupies);
Player two = player_init("Link", 255);
printf("hi %s, you have %i rupies\n",two.name, two.rupies);
Player three = player_init("Mario", 255);
printf("hi %s, you have %i rupies\n",three.name, three.rupies);
Player four = player_init("Taloon", 255);
printf("hi %s, you have %i rupies\n",four.name, four.rupies);

printf("\n");
printf("\n");

Player *table[NUM_PLAYERS];

table[0] = &one;
table[1] = &two;
table[2] = &three;
table[3] = &four;

first_Deal(&game_deck, table, NUM_PLAYERS);

print_Dummy(&two);
printf("\n");
print_Dummy(&three);
printf("\n");
print_Dummy(&four);
print_Hand(table, 1);
print_Options();
isHand(one.hand);
bets = betAmount(&one);
pot += bets;
printf("%s, bets %i rupies\n",one.name, bets);
pot += bets;
printf("%s, bets %i rupies\n",two.name, bets);
pot += bets;
printf("%s, bets %i rupies\n",three.name, bets);
pot += bets;
printf("%s, bets %i rupies\n",four.name, bets);
pot += bets;
printf("The pot size is %i rupies\n",pot);
printf("You have %i rupies left\n\n",one.rupies);
print_Hand(table, 1);
Deck MC_Deck = create_Monte(&one);
printf("Monte says this is what you should look to do: %f \n", monte_Analysis(&MC_Deck, &one));
printf("Recommended exchange is: %i %i %i %i %i\n\n", one.mc_reco[0], one.mc_reco[1],one.mc_reco[2],one.mc_reco[3],one.mc_reco[4]);
newCards(&game_deck,&one);
print_Hand(table, 1);
print_Options();
isHand(one.hand);
printf("\n");
printf("\n");
bets = betAmount(&one);
pot += bets;
isHand(two.hand);
isHand(three.hand);
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
printf("Player one's position point: %i\nPlayer two's position point: %i\nPlayer three's position point: %i\nPlayer four's positions point: %i\n", one.position, two.position, three.position, four.position);
printf("\n%s WINS %i RUPIES\n", winnerIs(table), pot);

	 return 0;
}
