#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom_assert.h"
#include <math.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "interface.h"


//Test for tribute function	

int main(){
	//set up the card array
	int k[10]={adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	//declare gamestate
	struct gameState G;

	//checking to see if number of actions has changed
	int numActionsBefore;
	int numActionsAfter;
	int bonus=0;

	//none of these are actually used
	int choice1=-1;
	int choice2=-1;
	int choice3=-1;

	int currentPlayer=0;
	int nextPlayer=1;
	srand(time(NULL));
	int seed=rand();

	printf("Beginning test on tribute function\n");
	
	initializeGame(2, k, seed, &G); //create game
	
	G.whoseTurn = currentPlayer;

	numActionsBefore=G.numActions; //save current players number of actions
	
	//manually give the current player a tribute card
	G.hand[currentPlayer][0]=tribute;

	//Manually give the next player two treasure cards
	G.hand[nextPlayer][0]=silver;
	G.hand[nextPlayer][1]=silver;

	cardEffect(tribute, choice1, choice2, choice3, &G, 0, &bonus);


	numActionsAfter=G.numActions; //check to see if number of actions has changed
	assert(numActionsBefore, numActionsAfter);  //assert fails because the second card is automatically read as an action card

	printf("Before: %d\nAfter: %d\n", numActionsBefore, numActionsAfter);
	

	printf("Ending Tests\n");
	return 0;
}
