#include "fast_integer_exponentiation.h"

uint64_t power(uint64_t x, uint64_t y)
{
	uint64_t res = 1;     // Initialize result 

	while (y > 0)
	{
		// If y is odd, multiply x with result 
		if (y & 1)
			res = res * x;

		// y must be even now 
		y = y >> 1; // y = y/2 
		x = x * x;  // Change x to x^2 
	}
	return res;
}

uint64_t powermod(uint64_t x, uint64_t y, uint64_t p){
	return power(x,y)%p;
}