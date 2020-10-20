#include <iostream>
#include <algorithm>
#include <vector>
#include "test_runner.h"

using namespace std;

template<typename T>
void RemoveDuplicates(vector<T> &elements) {
	set<T> s(begin(elements), end(elements));
	elements.assign(begin(s), end(s));
}

// Tests section

void TestSomething() {

}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestSomething, "Test TestSomething");
}

ostream& operator<<(ostream &output, const vector<int> &v) {
	for (auto it = begin(v); it < end(v); it++) {
		if (it != begin(v)) {
			output << ' ';
		}
		output << *it;
	}
	return output;
}

int main() {

	int n;
	cin >> n;
	vector<int> permutation(n);
	for (auto &item : permutation) {
		item = n--;
	}

	cout << permutation << endl;

	while (prev_permutation(begin(permutation), end(permutation))) {
		cout << permutation << endl;
	}

	return 0;
}
