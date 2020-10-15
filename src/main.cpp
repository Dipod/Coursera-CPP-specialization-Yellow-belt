#include "test_runner.h"

// Tests section

void TestSomething() {
	AssertEqual(1, 1, "1 = 1 test");
}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestSomething, "TestSomething");
}

int main() {
	TestAll();

	return 0;
}

