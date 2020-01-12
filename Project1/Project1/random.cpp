#include "random.h"

int generateRandom(int max)
{
	int randomNumber = rand();
	float random = randomNumber %max;
	int myRandom = random;
	return myRandom;
}