#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "interface.h"



int main(){
	
	//set up card array
	int k[10]={adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	//declare gamestate
	struct gameState G;

	int currentPlayer=0;
//	int nextPlayer=1; was not needed
	int bonus=0;	

	int choice1=4; //choice for what card to reveal from hand
	int choice2=2; //choice of how many cards are to be removed
	int choice3=-1; //not used


	srand(time(NULL));
	int seed=rand();
	int passed=0; //variable to see if negative 1 is returned by the function


	initializeGame(2, k, seed, &G); //create game

	G.whoseTurn = currentPlayer; //setting player turn

	printf("Testing Ambassador function\n");

	G.hand[currentPlayer][3]=copper; //giving player two cards to ambassador
	G.hand[currentPlayer][4]=copper;
	G.hand[currentPlayer][0]=ambassador; //giving player an ambassador card
	
	passed = cardEffect(ambassador, choice1, choice2, choice3, &G, 0, bonus);

	assert(passed!=-1); //assert fails because the for loop does not correctly add up the number of cards in the players hand


	printf("Did it pass: %d\n", passed);
	printf("Tests Ended\n");

	return 0;
}
