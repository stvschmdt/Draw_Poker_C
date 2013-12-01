#include "hedz.h"


/*id like to NOT build out every instance of hands, but use comparisions to build a heap? or other data structure to compare to */


/*was debating a logarithmic scale for hands...lots of 'closeness' between a pair of jacks, 2 low pair and 3 of a kind verse an almost always winning straight flush*/

/*second thought was to build equivalence classes for each choices.type and assign value to them... lets try that*/
/*i can multiply the high card or pair or three of a kind by a scalar function say * 5 for a five or * 9 for a nine and pump up the value depending on the kickers, this can be 
  built into later functions*/



Deck create_Monte(Player *person){/*this may be uneccessary if i just keep the monte deck with the person player*/
	 int i, j, k=0, s = 0;

	 Deck monte_Carlo_Deck = get_new_Deck();
	 Card temp;
	 for (i=0; i<52; i++){
		  for(j = 0; j<HAND_SIZE;j++){
				if((strcmp(person->hand[j].face, monte_Carlo_Deck.deckCards[i].face)) != 0 && (strcmp(person->hand[j].suit, monte_Carlo_Deck.deckCards[i].suit) != 0)){
					k++;
				}
				else{
					 temp = monte_Carlo_Deck.deckCards[k];
					 for(s = k ;s < DECK_SIZE-2; s++){
							monte_Carlo_Deck.deckCards[s]	= monte_Carlo_Deck.deckCards[s+1];				
					 }
					 monte_Carlo_Deck.deckCards[DECK_SIZE-1] = temp;
				}
		  }
	 }

	 return monte_Carlo_Deck;

}

float monte_Analysis(Deck *deck){
	 int i, j, k, bestType = 0, rank = 0, ave = 0, sum = 0, maxave = 0;
printf("hi\n");
	 float val = 0.0;
	 Player dummy = player_init("Dummy", 255);
	 int choices[][5] = {
{0,0,0,0,1},
{0,0,0,1,0},
{0,0,0,1,1},
{0,0,1,0,0},
{0,0,1,0,1},
{0,0,1,1,0},
{0,0,1,1,1},
{0,1,0,0,0},
{0,1,0,0,1},
{0,1,0,1,0},
 {0,1,0,1,1},
 {0,1,1,0,0},
 {0,1,1,0,1},
 {0,1,1,1,0},
 {0,1,1,1,1},
 {1,0,0,0,0},
 {1,0,0,0,1},
 {1,0,0,1,0},
 {1,0,0,1,1},
 {1,0,1,0,0},
 {1,0,1,0,1},
 {1,0,1,1,0},
 {1,0,1,1,1},
 {1,1,0,0,0},
 {1,1,0,0,1},
 {1,1,0,1,0},
 {1,1,0,1,1},
 {1,1,1,0,0},
 {1,1,1,0,1},
 {1,1,1,1,0},
 {1,1,1,1,1},
 {0,0,0,0,0},
	 };

	 for(i = 0;i<32;i++){
		  for(j = 0; j < MCTRIALS; j++){
				shuffle(deck, 47);
				for(k = 0; k < HAND_SIZE; k++){
					 if(choices[i][k] == 1){
						  exchangeMC(deck, &dummy, k);
					 }
				}
				rank = handRank(&dummy);
				sum += rank;
		  }
		  ave = (double)sum/(double)MCTRIALS;
		  if(ave > maxave){
				maxave = ave;
				bestType = i;
		  }
	 }
	 
	 return val;
}

void dealMC(Deck *deck){

}
