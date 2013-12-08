#include "hedz.h"

Player player_init(char *name, int rupies){
		Player person;
		person.name = malloc(sizeof(char)*255);
		person.name = name;
		person.position = 0;
		person.inGame = 1;
		person.rupies = rupies;
return person;
}



int got_dealt(){

return 0;
}

int getStatus(Player *person){
	printf("%s currently has %i rupies\n", person->name, person->rupies);
return 0;
}

int getTableStatus(Player *table[]){
	int i;
	for(i = 0;i<NUM_PLAYERS;i++){
		getStatus(table[i]);

	}
	printf("\n");
return 0;
}

int userFold(Player *player){
	player->inGame = 0;
	player->position = 0;	
return 0;
}
