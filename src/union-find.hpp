#ifndef __UNION_FIND__
#define __UNION_FIND__

#include <vector>

class union_find {
	std::vector<int> array;
	std::vector<std::size_t> sz;

	bool is_leaf(int a) {
		return array[a] == a;
	}

	bool is_alone(int a) {
		return is_leaf(a) && sz[a] == 1;
	}

	int get_root(int a) {

		/*
		 * check if the first element is in the array.
		 * If it's in the array, all connection will be
		 * in by costruction
		 */
		if (array.at(a) == a)
			return a;

		do {
			array[a] = array[array[a]];
			a = array[a];
		} while (array[a] != a);
		return a;
	}

public:
	union_find(const int n);
	~union_find() = default;

	void add_union(int a, int b) {
		const int b_r = get_root(b);
		const int a_r = get_root(a);

		if (b_r == a_r)
			return;

		/*
		 * exception check is not needed because array is garanteed
		 * to be the same size for array and sz. If we check the
		 * boundary on array we know that sz is already check
		 */
		const std::size_t sz_a = sz[a];
		const std::size_t sz_b = sz[b];

		if (sz_a < sz_b) {
			array[a_r] = b_r;
			sz[b_r] += sz_a;
		} else {
			array[b_r] = a_r;
			sz[a_r] += sz_b;
		}
	};

	bool is_connected(int a, int b) {
		return get_root(a) == get_root(b);
	}
};

#endif
