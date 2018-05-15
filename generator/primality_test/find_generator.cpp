#include <iostream>
#include "stack.cpp"

int modular_exponentation(unsigned long long arg, int power, const int modulo)
{
	if(power == 0)
	{
		return 1;
	}
	
	if(power == 1)
	{
		return arg % modulo;
	}
	
	if(power % 2 == 0)
	{
		return modular_exponentation((arg% modulo )*(arg % modulo) %modulo , power/2, modulo) % modulo;
	}
	else
	{
		return arg * modular_exponentation((arg% modulo )*(arg % modulo) %modulo , (power-1)/2, modulo) % modulo;
	}
}

int find_generators(const int PRIME_NUMBER)
{
	Node *root = NULL;
	for(int i = 2; i < PRIME_NUMBER; i++)
	{
		unsigned long long k = i;
		int exp = 1;
		do
		{
			exp++;
			k = modular_exponentation(i, exp, PRIME_NUMBER);	
			
		}
		while(k != i);
			
		if(exp == PRIME_NUMBER)
		{
			push(&root, i);
			std::cout << "Found a new generator: " << i << std::endl;
			
		}
		
	}
	
	
}

int main()
{
	int NUMBER = 1000003;
	find_generators(NUMBER);
}