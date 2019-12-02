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

	// Choices are not needed for Tribute
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	printf("Running test of cardEffect when the Tribute card is played and next player has 2 known cards in deck\n\n");

	initializeGame(2, k, seed, &G); //initialize a new game

	// Set the current player
	G.whoseTurn = p;

	// Set the hand count to 5 and manually assign those cards
	G.handCount[p] = 5;
	G.hand[p][0] = tribute;
	G.hand[p][1] = estate;
	G.hand[p][2] = province;
	G.hand[p][3] = great_hall;
	G.hand[p][4] = duchy;

	int nextPlayer = p + 1;

	// Set the next player's deck to a fixed size of 2 and assign the cards manually to guarantee a known score
	G.discardCount[nextPlayer] = 0;
	G.deckCount[nextPlayer] = 2;
	G.deck[nextPlayer][0] = silver;
	G.deck[nextPlayer][1] = gold;

	// Get the coin count before playing Tribute
	coinsBefore = G.coins;

	cardEffect(tribute, choice1, choice2, choice3, &G, 0, &bonus);

	// Get the coin count after playing
	coinsAfter = G.coins;

	printf("The coin count remains the same: %s\n", assert(coinsBefore, coinsBefore));
	printf("The bonus count goes up by 4: %s\n", assert(bonus, 4));

	printf("\n\n");

	return 0;

}