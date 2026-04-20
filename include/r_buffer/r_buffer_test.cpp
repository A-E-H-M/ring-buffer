#include <iostream>

#include "r_buffer.hpp"

using namespace R_BUFFER;

int main()
{
	Ring_buffer<int, 3> int_buffer;

	int_buffer.append(5);
	int_buffer.append(23);

	int_buffer.assign(1, 8);

	std::cout << int_buffer.at(0);
	std::cout << int_buffer.at(1);
	
	return 0;
};