//Name: Alex Swider
//Date: 11/10/19
//Description: unittest1.c for assignment 

//mine and tribute bug
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

int p;
int currentPlayer = 0;
//int nextPlayer = 1;
int result;

printf("Begin Testing mine and tribute cards:\n");

//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);



/* TEST: Mine and Tribute fail to discardCard in cardEffect function */
//test mine difference is less than 3
memset(&state, 23, sizeof(struct gameState)); // set the game state
int r = initializeGame(2, k, 2, &state); // initialize a new game
//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
state.hand[currentPlayer][0] = estate;
state.hand[currentPlayer][4] = mine;
state.handCount[currentPlayer] = 4;
state.discardCount[currentPlayer] = 0;
//choice 2 is feast (should pass)
result = cardEffect(mine, 0, feast, 0, &state, 4, 0);
printf("Result of cardEffect does not equal -1 %s\n", assert(result, 0));
printf("Discard count is equal to 0 %s\n", assert(state.discardCount, 0));

//test mine difference is more than 3
memset(&state, 23, sizeof(struct gameState)); // set the game state
r = initializeGame(2, k, 2, &state); // initialize a new game
state.hand[currentPlayer][0] = estate;
state.hand[currentPlayer][4] = mine;
state.handCount[currentPlayer] = 4;
state.discardCount[currentPlayer] = 0;
//choice 2 is province (should return -1)
result = cardEffect(mine, 0, province, 0, &state, 4, 0);
printf("Result of cardEffect does not equal -1 %s\n", assert(result, 0));
printf("Discard count is equal to 0 %s\n", assert(state.discardCount, 0));

//test tribute difference less than 3
memset(&state, 23, sizeof(struct gameState)); // set the game state
r = initializeGame(2, k, 2, &state); // initialize a new game
//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
state.hand[currentPlayer][0] = estate;
state.discardCount[1] = 4;
state.deckCount[1] = 4;
state.deck[1][feast];
//choice 2 is feast (should pass)
result = cardEffect(tribute, 0, feast, 0, &state, 0, 0);
printf("Result of cardEffect does not equal -1 %s\n", assert(result, 0));
printf("Discard count is equal to 0 %s\n", assert(state.discardCount, 0));

//test tribute difference greater than 3
memset(&state, 23, sizeof(struct gameState)); // set the game state
r = initializeGame(2, k, 2, &state); // initialize a new game
state.hand[currentPlayer][0] = estate;
state.discardCount[1] = 4;
state.deckCount[1] = 4;
state.deck[1][province];
//choice 2 is province (should return -1)
result = cardEffect(tribute, 0, province, 0, &state, 0, 0);
printf("Result of cardEffect does not equal -1 %s\n", assert(result, 0));
printf("Discard count is equal to 0 %s\n", assert(state.discardCount, 0));


printf("Test completed!\n");


}