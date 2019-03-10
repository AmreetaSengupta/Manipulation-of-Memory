/****************************************************************************************
* @main.c
* @This file contains algorithm for the random number generator. The user defined seed
* is multiplied with the prime number 173 and then prime number 197 is added to it.
* @Tools used : GCC & GNU make
* @authors Amreeta Sengupta & Ridhi Shah
******************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../Include/random_generator.h"

uint32_t random_generator(uint32_t seed)
{
	uint32_t x = (((seed*173)+197));
	return x;
}
