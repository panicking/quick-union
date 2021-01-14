#include "union-find.hpp"
#include <iostream>

using namespace std;

union_find::union_find(const int n)
{
	array.reserve(n);

	for (int i = 0; i < n; i++)
		array[i] = i;
}
