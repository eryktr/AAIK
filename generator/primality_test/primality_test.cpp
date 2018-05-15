#include <iostream>
#include <math.h>
bool is_prime(int arg)
{
	if(arg < 2)
	{
		return false;
	}
	
	const int SIZE = arg + 1;
	bool* sieve = new bool[SIZE];
	
	for(int i = 0; i < SIZE; i++)
	{
		sieve[i] = true;
	}
	sieve[0] = false;
	sieve[1] = false;
	
	for(int i = 2; i <= sqrt(arg); i++)
	{
		if(sieve[i])
		{
			for(int j = i * i; j <= arg; j = j + i)
			{
				sieve[j] = false;
			}
		}
	}
	
	return sieve[arg];
	
}

int main()
{
	const int NUMBER = 1000003;
	std::cout << is_prime(number); // Zwraca true.
}