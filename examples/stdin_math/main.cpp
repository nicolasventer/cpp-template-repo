#include <math_lib.hpp>

#include <iostream>

int main()
{
	double x = 0.0;

	// Reads `x` from stdin until EOF and prints `mult2(x)`.
	while (std::cin >> x)
	{
		std::cout << math_lib::mult2(x) << '\n';
	}

	return 0;
}
