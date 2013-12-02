#include "hedz.h"

/***********************************************************
 *  array to init the reference deck to mirror the starting *
 *  deck for the isHand analysis. The premise of analysis   *
 *  is to build two bucket arrays representing the 13 faces *
 *  and 4 suits                                             *
 ***********************************************************/


char *faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
char *suits[] = { "♠", "♥", "♦", "♣"};


/***********************************************************
 *  init: initialize the count of each bucket for face and  *
 *        suit to be zero                                   *
 *  check: for each face, if the hand arg has that value,   *
 *         up tick that bucket count of face                *
 *  1: traverse tracking array for face values keeping track*
 *     of high card if 1, pair if 2 and 2nd pair if 2nd 2   *
 *  2. traverse suit tracking array to see if any has val 5 *
 *     meaning all five of one suit or flush                *
 *  3. traverse face tracking array to check for contiguous *
 *     values to give a counter to a val straight for #4    *
 *  4. print via if statements for all possible hand types  *
 *     taking into account ace hi/lo and combos of types    *
 ***********************************************************/

int isHand(Card *hand){
	 int i, j, f, k, s, t, x, y, z, high = 0, pair = 0, three = 0, four = 0,  straight = 0, flush = 0;
	 int facetrack[13];
	 int suittrack[4];
	 /*init*/
	 for(i = 0;i<13;i++){
		  facetrack[i] = 0;
	 }

	 for(i = 0;i<4;i++){
		  suittrack[i] = 0;
	 }
	 /*check*/
	 for(i=0;i<13;i++){
		  for(j=0;j<HAND_SIZE;j++){
				if(strcmp(hand[j].face, faces[i]) == 0) {
					 facetrack[i]++;
				}
		  }
	 }

	 for(i=0;i<4;i++){
		  for(j=0;j<HAND_SIZE;j++){
				if(strcmp(hand[j].suit, suits[i]) == 0) {
					 suittrack[i]++;
				}
		  }
	 }

	 /*1*/
	 for(i=0;i<13;i++){
		  if(facetrack[i] == 1){
				high = i;
		  }
		  else if(facetrack[i] == 2){
				pair++;
				if(pair == 1){
					 x = i;
				}
				else{
					 y = i;
				}
		  }
		  else if(facetrack[i] == 3 ){
				three++;
				t = i;

		  }
		  else if(facetrack[i] == 4){
				four++;
				z = i;
		  }
	 }
	 /*2*/
	 for(k = 0; k<4; k++){
		  if(suittrack[k] == 5){
				flush++;
				f = k;
		  }
	 }
	 /*3*/
	 for(k=0; k<13; k++){
		  if(facetrack[k] == 1){
				straight++;
				s = k;
				if(straight == 5){
					 break;
				}
		  }
		  else{
				straight = 0;
		  }
	 }
	 /*4*/
	 if(straight == 5 && flush == 0){
		  printf("You have a straight to the %s", faces[s]);
	 }
	 else if(straight == 4 && facetrack[0] == 1 && flush == 0){
		  printf("You have a straight to the %s", faces[4]);
	 }
	 else if(straight == 5 && flush == 1){
		  printf("You have a royal flush to the %s", faces[s]);
	 }
	 else if(straight == 4 && facetrack[0] == 1 && flush == 0){
		  printf("You have a straight flush");
	 }

	 else if(pair == 1 && three == 0){
		  printf("You have a pair of %s's", faces[x]);
	 }
	 else if(pair ==2){
		  printf("You have two pair %s's &  %s's", faces[x], faces[y]);
	 }
	 else if(four == 1){
		  printf("You have four of a kind in %s's", faces[z]);
	 }
	 else if(three == 1 && pair == 0){
		  printf("You have three of a kind in %s's", faces[t]);
	 }
	 else if(three ==1 && pair ==1){
		  printf("You have a full house %s's over %s's", faces[t], faces[x]);
	 }
	 else if(flush == 1){
		  printf("You have a flush in %s's", suits[f]);
	 }
	 else{
		  printf("You have high card %s", faces[high]);
	 }
	 printf("\n\n");
	 return high;
}



double handRank(Player *player){
	 int i, j, f, k, s, t, y, z,  four = 0, high = 0, pair = 0, three = 0, straight = 0, flush = 0;
	 double x, rank = 0.0;
	 int facetrack[13];
	 int suittrack[4];
	 for(i = 0;i<13;i++){
		  facetrack[i] = 0;
	 }

	 for(i = 0;i<4;i++){
		  suittrack[i] = 0;
	 }
	 for(i=0;i<13;i++){
		  for(j=0;j<HAND_SIZE;j++){
				if(strcmp(player->hand[j].face, faces[i]) == 0) {
					 facetrack[i]++;
				}
		  }
	 }

	 for(i=0;i<4;i++){
		  for(j=0;j<HAND_SIZE;j++){
				if(strcmp(player->hand[j].suit, suits[i]) == 0) {
					 suittrack[i]++;
				}
		  }
	 }
	 for(i=0;i<13;i++){
		  if(facetrack[i] == 1){
				high = i;
		  }
		  else if(facetrack[i] == 2){
				pair++;
				if(pair == 1){
					 x = i;
				}
				else{
					 y = i;

				}
		  }
		  else if(facetrack[i] == 3 ){
				three++;
				t = i;
		  }
		  else if(facetrack[i] == 4){
				four++;
				z = i;
		  }
	 }
	 for(k = 0; k<4; k++){
		  if(suittrack[k] == 5){
				flush++;
				f = k;
		  }
	 }
	 for(k=0; k<13; k++){
		  if(facetrack[k] == 1){
				straight++;
				s = k;
				if(straight == 5){
					 break;
				}
		  }
		  else{
				straight = 0;
		  }
	 }
	 if(straight == 5 && flush == 0){
		  rank = 67 + s;/*straight*/
	 }
	 else if(straight == 4 && facetrack[0] == 1 && flush == 0){
		  rank = 67 + 5;/*straight to the 5*/
	 }
	 else if(straight == 5 && flush == 1){
		  rank = 132 + s;/*straight flush*/
	 }
	 else if(straight == 4 && facetrack[0] == 1 && flush == 1){
		  rank = 132 + 5;/*straight flush*/
	 }
	 else if(four ==1){
		  rank = 118 + z;
	 }
	 else if(pair == 1 && three == 0){
		  rank = 12 +  x;/*1 pair*/
	 }
	 else if(pair ==2){
		  rank = 24+ 2*y + ((double)x/13.0);/*two pair*/
	 }
	 else if(three == 1 && pair == 0){
		  rank = 52 + t;/*three of kind*/
	 }
	 else if(three ==1 && pair ==1){
		  rank = 91 + t + x;/*full house*/
	 }
	 else if(flush == 1){
		  rank = 79 + high;/*flush*/
	 }
	 else{
		  rank = high;/*high card*/
	 }
	 player->rank = rank;
	 return rank;
}


int handCompareTo(Player *p1, Player *p2){
	 int i, high1, high2, j, high;

	 if(p1->rank > p2->rank){
		  p1->position++;
	 }
	 else if(p2->rank > p1->rank){
		  p2->position++;
	 }
	 else{
		  int facetrack1[13];
		  int facetrack2[13];
		  /*init*/
		  for(i = 0;i<13;i++){
				facetrack1[i] = 0;
				facetrack2[i] = 0;
		  }

		  /*check*/
		  for(i=0;i<13;i++){
				for(j=0;j<HAND_SIZE;j++){
					 if(strcmp(p1->hand[j].face, faces[i]) == 0) {
						  facetrack1[i]++;
					 }
				}
		  }

		  for(i=0;i<13;i++){
				for(j=0;j<HAND_SIZE;j++){
					 if(strcmp(p2->hand[j].face, faces[i]) == 0) {
						  facetrack2[i]++;
					 }
				}
		  }

		  /*1*/
		  for(i=0;i<13;i++){
				if(facetrack1[i] == 1){
					 high1 = i;
				}
				if(facetrack2[i] == 1){
					 high2 =i;
				}

		  }
		  if (high2 > high1){
				p2->position++;
		  }
		  else if(high1 > high2){

				p1->position++;
		  }
		  else{
				high = high1;
				for(i=0;i<high;i++){
					 if(facetrack1[i] == 1){
						  high1 = i;
					 }
					 if(facetrack2[i] == 1){
						  high2 =i;
					 }

				}
				if (high2 > high1){
					 p2->position++;
				}
				else if(high1 > high2){

					 p1->position++;
				}



		  }
	 }
	 return 0;

}

char * winnerIs(Player *table[], int pot){
	   int i;
		for(i = 0;i<NUM_PLAYERS;i++){
			if (table[i]->inGame == 0){
				table[i]->position = 0;
			}

		}
		if(table[0]->position > table[1]->position && table[0]->position > table[2]->position && table[0]->position > table[3]->position){
			table[0]->rupies += pot;
			printf("\n%s WINS %i RUPIES\n", table[0]->name, pot);
			getStatus(table[0]);
			return table[0]->name;
		}

		if(table[1]->position > table[0]->position && table[1]->position > table[2]->position && table[1]->position > table[3]->position){
			table[1]->rupies += pot;
			printf("\n%s WINS %i RUPIES\n", table[1]->name, pot);
			getStatus(table[1]);
			return table[1]->name;
		}
		if(table[2]->position > table[0]->position && table[2]->position > table[1]->position && table[2]->position > table[3]->position){
			table[2]->rupies += pot;
			printf("\n%s WINS %i RUPIES\n", table[2]->name, pot);
			getStatus(table[2]);
			return table[2]->name;
		}

		if(table[3]->position > table[0]->position && table[3]->position > table[1]->position && table[3]->position > table[2]->position){
			table[3]->rupies += pot;
			printf("\n%s WINS %i RUPIES\n", table[3]->name, pot);
			getStatus(table[3]);
			return table[3]->name;
		}
		else{
			return "you have a bug";
		}
}
