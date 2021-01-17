#include "union-find.hpp"
#include <iostream>

using namespace std;

union_find::union_find(const int n)
{
	array.resize(n);
	sz.resize(n);

	fill(sz.begin(), sz.end(), 1);

	for (int i = 0; i < n; i++)
		array[i] = i;
}

void union_find::dump_connections()
{
	size_t i = 0;
	std::cout << "Tree dump" << std::endl;

	for (; i < array.size(); i++) {
		int j = i;

		if (is_alone(j)) {
			std::cout << j << std::endl;
			continue;
		}

		do {
			if (array[j] != j)
				std::cout << j << " <-> ";
			j = array[j];
		} while (array[j] != j);

		if (i != j)
			std::cout << j << std::endl;
	}
}
