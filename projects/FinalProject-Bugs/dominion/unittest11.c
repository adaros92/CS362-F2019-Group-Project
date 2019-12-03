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
	//set up the card array
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	//declare gamestate
	struct gameState G;
	
	int currentPlayer=0;
//	int nextPlayer=1; not used
	srand(time(NULL));
	int seed=rand();
	int bonus=0;
	int returnVal=-1;
	
	
	//making all choices invalid so nothing runs; if statement does not handle an invalid choice
	int choice1=0;
	int choice2=0;
	int choice3=0;

	//tracking player coins
	//shoild not change given function shouuld not execute anything
	int playerCoinsBefore;	
	int playerCoinsAfter;


	printf("Beginning test on minion function\n");

	initializeGame(2, k, seed, &G); //create game

	G.whoseTurn=0;
	
	//gives player a minion card and four silver cards
	//only card that should be changed is the minion card
	G.hand[currentPlayer][0]=minion;
	G.hand[currentPlayer][1]=silver;
	G.hand[currentPlayer][2]=silver;
	G.hand[currentPlayer][3]=silver;
	G.hand[currentPlayer][4]=silver;

	playerCoinsBefore=G.coins;
	
	returnVal = cardEffect(minion, choice1, choice2, choice3, &G, 0, bonus); //running case statement


	playerCoinsAfter=G.coins;

//	printf("%d\n%d\n", playerCoinsBefore, playerCoinsAfter);
	assert(playerCoinsBefore==playerCoinsAfter); //asserts that choice 1 was not ran ; will pass
	assert(G.hand[currentPlayer][1]==silver); //asserts that card was not discarded ; choice two not ran
	assert(returnVal==0); //asserts that the function ran; will pass



	printf("Test Ended, Asserts Passed, function does not run either conditional\n");	

	return 0;
}
