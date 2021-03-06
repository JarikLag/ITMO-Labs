#include <iostream>
#include "Array.h"
using namespace std;

bool lezz(int a, int b) {
	return a < b;
}

struct Greater {
	bool operator()(int a, int b) const {
		return b < a; 
	} 
};

template<typename T, typename Comparator>
T minimum(Array<T>& array, Comparator comparator) {
	T result = array[0];
	for (size_t i = 1; i < array.size(); ++i) {
		if (comparator(array[i], result)) {
			result = array[i];
		}
	}
	return result;
}

template <typename T>
void flatten(const Array<T>& array, ostream& out) {
	for (size_t i = 0; i < array.size(); ++i) {
		out << array[i] << ' ';
	}
}

template <typename T>
void flatten(const Array<Array<T>>& array, ostream& out) {
	for (size_t i = 0; i < array.size(); ++i) {
		flatten(array[i], out);
	}
}

int main()
{
	Array<int> ints(3);
	ints[0] = 10;
	ints[1] = 2;
	ints[2] = 15;
	int min = minimum(ints, lezz);
	int max = minimum(ints, Greater());
	cout << min << ' ' << max << endl;

	Array<Array<Array<int>>> arr(3, Array<Array<int>>(3, Array<int>(3, 3)));
	flatten(arr, cout);
	return 0;
}