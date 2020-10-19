#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include "test_runner.h"

using namespace std;

template<typename T>
vector<T> FindGreaterElements(const set<T> &elements, const T &border) {

	auto it = find_if(begin(elements), end(elements), [&border](const T &item) {
		return item > border;
	});

	vector<T> result;
	result.assign(it, end(elements));
	return result;
}

// Tests section

void TestFindGreaterElements() {

	AssertEqual(FindGreaterElements(set<int> { 1, 5, 7, 8 }, 5), vector<int> {
			7, 8 }, "Test set of { 1, 5, 7, 8 }");
	string to_find = "Python";
	AssertEqual(FindGreaterElements(set<string> { "C", "C++" }, to_find),
			vector<string> { }, "Test set of { C, C++ }");

}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestFindGreaterElements, "Test FindGreaterElements");
}

int main() {
	TestAll();

	for (int x : FindGreaterElements(set<int> { 1, 5, 7, 8 }, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string> { "C", "C++" }, to_find).size()
			<< endl;
	return 0;
}
