#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
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
	tr.RunTest(TestSomething, "Test SplitIntoWords");
}

int main() {
	vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
	RemoveDuplicates(v1);
	for (int x : v1) {
		cout << x << " ";
	}
	cout << endl;

	vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
	RemoveDuplicates(v2);
	for (const string &s : v2) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
