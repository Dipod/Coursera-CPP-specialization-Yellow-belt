#include "test_runner.h"

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestSomething, "TestSomething");
}

int main() {
	TestAll();

	return 0;
}
