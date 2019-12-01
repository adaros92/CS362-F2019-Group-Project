CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

custom_assert.o: custom_assert.h custom_assert.c
	gcc -c custom_assert.c -g $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittest5: unittest5.c dominion.o rngs.o custom_assert.o
	gcc -o unittest5 -g unittest5.c dominion.o rngs.o custom_assert.o $(CFLAGS)

unittest6: unittest6.c dominion.o rngs.o custom_assert.o
	gcc -o unittest6 -g unittest6.c dominion.o rngs.o custom_assert.o $(CFLAGS)

unittest7: unittest7.c dominion.o rngs.o custom_assert.o
	gcc -o unittest7 -g unittest7.c dominion.o rngs.o custom_assert.o $(CFLAGS)

unittest8: unittest8.c dominion.o rngs.o custom_assert.o
	gcc -o unittest8 -g unittest8.c dominion.o rngs.o custom_assert.o $(CFLAGS)

unittestresults: unittest5 unittest6 unittest7 unittest8
	#./unittest1 &> unittest1result.out
	#gcov dominion.c -f >> unittest1result.out
	#./unittest2 &> unittest2result.out
	#gcov dominion.c -f >> unittest2result.out
	#./unittest3 &> unittest3result.out
	#gcov dominion.c -f >> unittest3result.out
	#./unittest4 &> unittest4result.out
	#gcov dominion.c -f >> unittest4result.out
	./unittest5 &> unittest5result.out
	gcov dominion.c -bf >> unittest5result.out
	./unittest6 &> unittest6result.out
	gcov dominion.c -bf >> unittest6result.out
	./unittest7 &> unittest7result.out
	gcov dominion.c -bf >> unittest7result.out
	./unittest8 &> unittest8result.out
	gcov dominion.c -bf >> unittest8result.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -rf *.o playdom.exe playdom player player.exe unittest[123456789] *10 *11 *.out *.dSYM  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
