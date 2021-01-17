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
