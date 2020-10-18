#include "test_runner.h"
#include "rectangle.h"

using namespace std;

// Tests section

void TestSomething() {

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

