#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "test_runner.h"

using namespace std;

vector<string> SplitIntoWords(const string &s) {

	auto it1 = begin(s), it2 = begin(s);
	vector<string> result;

	while (it2 != end(s)) {
		if (it2 != begin(s)) {
			it2++;
		}
		it1 = it2;
		it2 = find(it2, end(s), ' ');
		result.push_back(string(it1, it2));
	}

	return result;
}

// Tests section

void TestSplitIntoWords() {

	string s = "C Cpp Java Python";
	AssertEqual(SplitIntoWords(s),
			vector<string> { "C", "Cpp", "Java", "Python" },
			"Test string C Cpp Java Python");
}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestSplitIntoWords, "Test SplitIntoWords");
}

int main() {
	TestAll();

	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}
