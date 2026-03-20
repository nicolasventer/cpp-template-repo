#include <common/math/add.hpp>

#include <iostream>

int main()
{
	std::cout << "Enter two numbers to add, enter any non-numeric value to exit" << '\n';

	double a = 0.0;
	double b = 0.0;

	// Reads pairs `<a> <b>` from stdin until EOF and prints `add(a, b)`.
	while (std::cin >> a >> b)
	{
		std::cout << a << " + " << b << " = " << common::math::add(a, b) << '\n';
	}

	return 0;
}
