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
