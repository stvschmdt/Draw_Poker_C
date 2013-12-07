#include "hedz.h"


/*was debating a logarithmic scale for hands...lots of 'closeness' between a pair of jacks, 2 low pair and 3 of a kind verse an almost always winning straight flush*/

/*second thought was to build equivalence classes for each choices.type and assign value to them... lets try that*/

Deck create_Monte(Player *person){/*this may be uneccessary if i just keep the monte deck with the person player*/
	 int i, j, s = 0;

	 Deck monte_Carlo_Deck = get_new_Deck();
	 Card temp;
	 for (i=0; i<47; i++){
		  for(j = 0; j<HAND_SIZE;j++){
				if((strcmp(person->hand[j].face, monte_Carlo_Deck.deckCards[i].face) == 0) && (strcmp(person->hand[j].suit, monte_Carlo_Deck.deckCards[i].suit) == 0)){
					 temp = monte_Carlo_Deck.deckCards[i];
					 for(s = i ;s < DECK_SIZE-1; s++){
						  monte_Carlo_Deck.deckCards[s]	= monte_Carlo_Deck.deckCards[s+1];				
					 }
					 monte_Carlo_Deck.deckCards[DECK_SIZE-1] = temp;
				}

		  }
	 }

	 return monte_Carlo_Deck;

}

double  monte_Analysis(Deck *deck, Player *person){
	 int i, j, k, bestType = 0;
	 double maxave = 0.0, ave = 0.0, rank = 0.0, sum = 0.0;
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
	 dummy.hand[0] = person->hand[0];
	 dummy.hand[1] = person->hand[1];
	 dummy.hand[2] = person->hand[2];
	 dummy.hand[3] = person->hand[3];
	 dummy.hand[4] = person->hand[4];

	 for(i = 0;i<32;i++){
		  sum = 0;
		  for(j = 0; j < MCTRIALS; j++){
				dummy.hand[0] = person->hand[0];
				dummy.hand[1] = person->hand[1];
				dummy.hand[2] = person->hand[2];
				dummy.hand[3] = person->hand[3];
				dummy.hand[4] = person->hand[4];
				shuffle(deck, 47);
				for(k = 0; k < HAND_SIZE; k++){
					 if(choices[i][k] == 1){
						  exchangeMC(deck, &dummy, k);
					 }
				}
				rank = handRank(&dummy);
				sum += (double)rank;
		  }
		  ave = (double)sum/(double)MCTRIALS;
		  if(ave > maxave){
				maxave = ave;
				bestType = i;
		  }
	 }
	 person->mc_reco[0] = choices[bestType][0];
	 person->mc_reco[1] = choices[bestType][1];
	 person->mc_reco[2] = choices[bestType][2];
	 person->mc_reco[3] = choices[bestType][3];
	 person->mc_reco[4] = choices[bestType][4];
	 return maxave;
}

void dealMC(Deck *deck){

}
/*
int cpuBIGACTIONS(Player *table[], int bets, Deck *game_deck){
#pragma omp parallel num_threads(4)
	 int z;
	 tid = omp_get_thread_number();
	 for(z=1;z<NUM_PLAYERS;z++){
		  if(tid == 1){
				pot += cpuActions(game_deck, table[1], table[0], bets);
		  }
		  if(tid == 2){
				pot += cpuActions(game_deck, table[2], table[0], bets);
		  }
		  if(tid == 3){
				pot += cpuActions(game_deck, table[3], table[0], bets);
		  }
	 }
}*/
