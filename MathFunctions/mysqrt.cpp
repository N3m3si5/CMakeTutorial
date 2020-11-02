#include "MathFunctions.h"

/**
  * heron sqrt 
  */
const double heron_sqrt(double initial, double guess)
{
	for(int i = 1 ; i < 9 ; i++)
		guess = (guess + (initial / guess)) / 2;
	return guess;
}

const double mysqrt(double i_powered_2)
{
	return heron_sqrt(i_powered_2, i_powered_2 / 2);
}