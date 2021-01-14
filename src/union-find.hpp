#ifndef __UNION_FIND__
#define __UNION_FIND__

#include <vector>

class union_find {
	std::vector<int> array;

public:
	union_find(const int n);
	~union_find() = default;

	void add_union(int a, int b) {
		int a_v = array[a];
		int b_v = array[b];

		for (int i = 0; i < array.capacity(); i++)
			if (array[i] == a_v) array[i] = b_v;
	};

	bool is_connected(int a, int b) {
		return array[a] == array[b];
	}
};

#endif
