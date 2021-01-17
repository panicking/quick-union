#include <quick-union.hpp>
#include <iostream>

int main(int argc, char **argv)
{
	quick_union myunion(20);

	myunion.add_union(0, 3);
	myunion.add_union(7, 4);
	myunion.add_union(3, 4);
	myunion.add_union(5, 3);
	myunion.add_union(1, 3);
	myunion.add_union(12, 3);
	myunion.add_union(4, 5);
	myunion.add_union(5, 13);
	myunion.add_union(13, 18);

	std::cout << myunion.is_connected(1, 18);
	return 0;
}
