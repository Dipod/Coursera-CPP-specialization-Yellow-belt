#include <iostream>
#include <algorithm>
#include <set>
#include "test_runner.h"

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int> &numbers,
		int border) {

	if (numbers.empty()) {
		return numbers.end();
	}

	auto element = numbers.lower_bound(border);

	if (element == numbers.end()) {
		return prev(numbers.end());
	}

	if (element == numbers.begin()) {
		return numbers.begin();
	}

	auto prev_element = prev(element);

	if (border - *prev_element <= *element - border) {
		return prev_element;
	} else {
		return element;
	}
}

int main() {
	set<int> numbers = { 1, 4, 6 };
	cout << *FindNearestElement(numbers, 0) << " "
			<< *FindNearestElement(numbers, 3) << " "
			<< *FindNearestElement(numbers, 5) << " "
			<< *FindNearestElement(numbers, 6) << " "
			<< *FindNearestElement(numbers, 100) << endl;

	set<int> empty_set;

	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}
