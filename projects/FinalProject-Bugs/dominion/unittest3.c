//Name: Alex Swider
//Date: 11/10/19
//Description: unittest3.c for assignment 

//remodel bug
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

int p;
int currentPlayer = 0;
int nextPlayer = 1;
int result;

printf("Begin Testing remodel card:\n");



/* TEST: Remodel card improper choice evaluation */

memset(&state, 23, sizeof(struct gameState)); // set the game state
int r = initializeGame(2, k, 2, &state); // initialize a new game

//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

//test remodel difference is less than 3
memset(&state, 23, sizeof(struct gameState)); // set the game state
int r = initializeGame(2, k, 2, &state); // initialize a new game
//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
state.hand[currentPlayer][0] = estate;
state.hand[currentPlayer][4] = remodel;
state.handCount[currentPlayer] = 4;
state.discardCount[currentPlayer] = 0;
//choice 2 is feast (should pass)
result = cardEffect(remodel, 0, feast, 0, &state, 4, 0);
assert(result != -1);


//test remodel difference is more than 3
memset(&state, 23, sizeof(struct gameState)); // set the game state
int r = initializeGame(2, k, 2, &state); // initialize a new game
state.hand[currentPlayer][0] = estate;
state.hand[currentPlayer][4] = remodel;
state.handCount[currentPlayer] = 4;
state.discardCount[currentPlayer] = 0;
//choice 2 is province (should return -1)
result = cardEffect(remodel, 0, province, 0, &state, 4, 0);
assert(result == -1);


printf("Test completed!\n");


}