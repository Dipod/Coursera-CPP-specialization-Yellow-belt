#include <iostream>
#include <algorithm>
#include <vector>
#include "test_runner.h"

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

	auto range_length = range_end - range_begin;

	if (range_length < 2) {
		return;
	}

	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	auto half_it = elements.begin() + range_length / 2;
	MergeSort(elements.begin(), half_it);
	MergeSort(half_it, elements.end());
	merge(elements.begin(), half_it, half_it, elements.end(), range_begin);
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
