#include "test_runner.h"
#include "sum_reverse_sort.h"
#include <vector>

using namespace std;

// Tests section

void TestSort() {
	vector<int> v = { 3, 2, 1 }, sorted = { 1, 2, 3 };

	Sort(v);
	AssertEqual(v, sorted, "{3,2,1} sort test");
}

void TestSum() {
	AssertEqual(Sum(1, 2), 3, "1 + 2 test");
}

void TestReverse() {
	AssertEqual(Reverse("123"), "321", "123 reverse test");
}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestSort, "TestSort");
	tr.RunTest(TestSum, "TestSum");
	tr.RunTest(TestReverse, "TestReverse");
}

int main() {
	TestAll();

	return 0;
}

