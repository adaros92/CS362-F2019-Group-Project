//Name: Alex Swider
//Date: 11/10/19
//Description: unittest4.c for assignment 

//isGameOver bug
#include <stdio.h>
#include <stdlib.h>
#include "custom_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "interface.h"
#include "rngs.h"



int main()
{


// set your card array
int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

// declare the game state
struct gameState state;

// declare the arrays
int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];

int i;
int p;
int currentPlayer = 0;
int nextPlayer = 1;
int result;

printf("Begin Testing isGameOver:\n");



/* TEST:   isGameOver function does not loop past 25 cards*/

memset(&state, 23, sizeof(struct gameState)); // set the game state
int r = initializeGame(2, k, 2, &state); // initialize a new game
state.supplyCount[province] = 1;
for(i=0; i<24; i++)
{
	state.supplyCount[i] = 1;
}
state.supplyCount[24] = 0;
state.supplyCount[25] = 0;
state.supplyCount[26] = 0;
result = isGameOver(&state);
//game should be over
printf("Game is over %s\n", assert(result, 1));

//standard game over (no bug)
memset(&state, 23, sizeof(struct gameState)); // set the game state
r = initializeGame(2, k, 2, &state); // initialize a new game
state.supplyCount[province] = 1;
for(i=0; i<24; i++)
{
	state.supplyCount[i] = 0;
}
state.supplyCount[24] = 0;
state.supplyCount[25] = 0;
state.supplyCount[26] = 0;
result = isGameOver(&state);
//game should be over
printf("Game is over %s\n", assert(result, 1));

//game not over
memset(&state, 23, sizeof(struct gameState)); // set the game state
r = initializeGame(2, k, 2, &state); // initialize a new game
state.supplyCount[province] = 1;
for(i=0; i<24; i++)
{
	state.supplyCount[i] = 1;
}
state.supplyCount[24] = 1;
state.supplyCount[25] = 1;
state.supplyCount[26] = 1;
result = isGameOver(&state);
//game should be over
printf("Game is not over %s\n", assert(result, 0));


printf("Test completed!\n");


}