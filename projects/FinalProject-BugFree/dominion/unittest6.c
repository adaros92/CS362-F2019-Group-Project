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
	int discardCountBefore;
	int discardCountAfter;
	int coinsBefore;
	int coinsAfter;
	int bonus = 0;
	int choice1;
	// Choice 2 and 3 are not needed for Feast
	int choice2 = -1;
	int choice3 = -1;

	printf("Running test of cardEffect when the Feast card is played\n\n");

	initializeGame(2, k, seed, &G); //initialize a new game

	// Set the current player
	G.whoseTurn = p;

	// Set the hand count to 5 and manually assign those cards
	G.handCount[p] = 5;
	G.hand[p][0] = feast;
	G.hand[p][1] = estate;
	G.hand[p][2] = province;
	G.hand[p][3] = great_hall;
	G.hand[p][4] = duchy;

	// Choose to gain an estate
	choice1 = estate;

	// Get the coin and discard pile counts before playing the Feast card
	coinsBefore = G.coins;
	discardCountBefore = G.discardCount[p];

	cardEffect(feast, choice1, choice2, choice3, &G, 0, &bonus);

	// Get the coin and discard pile counts after playing the Feast card
	discardCountAfter = G.discardCount[p];
	coinsAfter = G.coins;

	int latestDiscardCard = G.discard[p][discardCountAfter - 1];

	printf("The coins count after playing Feast has remained the same: %s\n", assert(coinsBefore, coinsAfter));
	printf("The discard pile has grown by one: %s\n", assert(discardCountAfter - discardCountBefore, 1));
	printf("The last card in the discard pile is the Estate that was gained: %s\n", assert(latestDiscardCard, estate));

	printf("\n\n");

	return 0;

}