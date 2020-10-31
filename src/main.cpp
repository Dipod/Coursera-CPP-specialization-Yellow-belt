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
	auto it1 = elements.begin() + range_length / 3;
	auto it2 = it1 + range_length / 3;
	MergeSort(elements.begin(), it1);
	MergeSort(it1, it2);
	MergeSort(it2, elements.end());
	vector<typename RandomIt::value_type> temp;
	merge(elements.begin(), it1, it1, it2, back_inserter(temp));
	merge(temp.begin(), temp.end(), it2, elements.end(), range_begin);
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
