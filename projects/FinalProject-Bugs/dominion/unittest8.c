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
	int coinsBefore;
	int coinsAfter;
	int bonus = 0;
	int choice1;
	int choice2 = -1;
	int choice3 = -1;

	printf("Running test of cardEffect when Baron is played and the player chooses to discard Estate\n\n");

	initializeGame(2, k, seed, &G); //initialize a new game

	G.whoseTurn = p;

	// Set the hand count to 5 and manually assign those cards
	G.handCount[p] = 5;
	G.hand[p][0] = baron;
	G.hand[p][1] = estate;
	G.hand[p][2] = province;
	G.hand[p][3] = great_hall;
	G.hand[p][4] = duchy;

	// Choose to discard an estate
	choice1 = 1;

	// Get the coin and discard pile counts before playing the Baron card
	coinsBefore = G.coins;

	cardEffect(feast, choice1, choice2, choice3, &G, 0, &bonus);

	// Get the coin and discard pile counts after playing the Feast card
	coinsAfter = G.coins;

	printf("The coins count after playing Baron has remained the same: %s\n", assert(coinsBefore, coinsAfter));
	printf("The current player has gained 4 bonus coins for discarding the available Estate: %s\n", assert(bonus, 4));

	printf("\n\n");

	return 0;

}