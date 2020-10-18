#include <iostream>
#include <algorithm>
#include <vector>
#include "test_runner.h"

using namespace std;

vector<int> GetVectorPart(const vector<int> &numbers) {
	auto it = find_if(numbers.begin(), numbers.end(), [](const int &number) {
		return number < 0;
	});
	vector<int> result;
	result.assign(numbers.begin(), it);
	reverse(result.begin(), result.end());
	return result;
}

void PrintVectorPart(const vector<int> &numbers) {
	bool first = true;
	for (const auto &item : GetVectorPart(numbers)) {
		if (!first) {
			cout << ' ';
		}
		cout << item;
		first = false;
	}
}

// Tests section

void TestGetVectorPart() {
	{
		vector<int> n = { 8, 1, 6 };
		AssertEqual(GetVectorPart( { 6, 1, 8, -5, 4 }), n,
				"Test vector { 6, 1, 8, -5, 4 }");
	}

	{
		vector<int> n;
		AssertEqual(GetVectorPart( { -6, 1, 8, -5, 4 }), n,
				"Test vector { -6, 1, 8, -5, 4 }");
	}

	{
		vector<int> n = { 4, 5, 8, 1, 6 };
		AssertEqual(GetVectorPart( { 6, 1, 8, 5, 4 }), n,
				"Test vector { 6, 1, 8, 5, 4 }");
	}
}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestGetVectorPart, "Test TestGetVectorPart");
}

int main() {
	TestAll();

	PrintVectorPart( { 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart( { -6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart( { 6, 1, 8, 5, 4 });
	cout << endl;

	return 0;
}
