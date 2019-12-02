#include "dominion.h"
#include "rngs.h"
#include "custom_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

	int k[10] = { adventurer, council_room, feast, gardens, mine
	, remodel, smithy, village, baron, great_hall };

	struct gameState G;
	// Set random seed
	srand(time(NULL));
	int seed = rand();
	int p  = 0; // player to test
	int currentScore;
	int expectedScore;

	printf("Running test of scoreFor function when there are the same number of cards in all collections\n\n");

	initializeGame(2, k, seed, &G); //initialize a new game

	// Set the current player
	G.whoseTurn = p;

	// Set the hand count to 5 and manually assign those cards
	G.handCount[p] = 5;
	G.hand[p][0] = curse;
	G.hand[p][1] = estate;
	G.hand[p][2] = province;
	G.hand[p][3] = great_hall;
	G.hand[p][4] = duchy;

	// do the same for discard pile
	G.discardCount[p] = 5;
	G.discard[p][0] = curse;
	G.discard[p][1] = estate;
	G.discard[p][2] = province;
	G.discard[p][3] = great_hall;
	G.discard[p][4] = duchy;

	// and the deck
	G.deckCount[p] = 5;
	G.deck[p][0] = curse;
	G.deck[p][1] = estate;
	G.deck[p][2] = province;
	G.deck[p][3] = great_hall;
	G.deck[p][4] = duchy;

	// Calculate the score for this hand, discard pile, and deck combination
	currentScore = scoreFor(p, &G);

	// We expect the current player to have total score of 30
	expectedScore = 30;

	printf("Calculated score of %d equals expected score of %d: %s\n", 
		currentScore, expectedScore, assert(currentScore, expectedScore)
		);

	printf("\n\n");

	printf("Running test of scoreFor function when there are no cards in discard pile or hand\n\n");

	initializeGame(2, k, seed, &G); //initialize a new game

	// Set the current player
	G.whoseTurn = p;

	// Set the hand count to 0 
	G.handCount[p] = 0;

	// do the same for discard pile
	G.discardCount[p] = 0;

	// but leave deck as is
	G.deckCount[p] = 5;
	G.deck[p][0] = curse;
	G.deck[p][1] = estate;
	G.deck[p][2] = province;
	G.deck[p][3] = great_hall;
	G.deck[p][4] = duchy;

	// Calculate the score for this hand, discard pile, and deck combination
	currentScore = scoreFor(p, &G);

	// We expect the current player to have total score of 10
	expectedScore = 10;

	printf("Calculated score of %d equals expected score of %d: %s\n", 
		currentScore, expectedScore, assert(currentScore, expectedScore)
		);

	printf("\n\n");

	return 0;

}