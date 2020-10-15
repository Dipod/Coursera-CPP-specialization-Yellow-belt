#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream& operator <<(ostream &os, const vector<T> &s) {
	os << "{";
	bool first = true;
	for (const auto &x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class T>
ostream& operator <<(ostream &os, const set<T> &s) {
	os << "{";
	bool first = true;
	for (const auto &x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class K, class V>
ostream& operator <<(ostream &os, const map<K, V> &m) {
	os << "{";
	bool first = true;
	for (const auto &kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = { }) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string &hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template<class TestFunc>
	void RunTest(TestFunc func, const string &test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (exception &e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		} catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};
/*
class Person {
public:
	// Вы можете вставлять сюда различные реализации класса,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	void ChangeFirstName(int year, const string &first_name) {
	}
	void ChangeLastName(int year, const string &last_name) {
	}
	string GetFullName(int year) {
		return "";
	}
};
*/
void TestPerson() {
	{
		Person person;
		AssertEqual(person.GetFullName(0), "Incognito",
				"Test empty person with 0 year");
	}

	{
		Person person;
		AssertEqual(person.GetFullName(-1), "Incognito",
				"Test empty person with -1 year");
	}

	{
		Person person;
		AssertEqual(person.GetFullName(1), "Incognito",
				"Test empty person with 1 year");
	}

	{
		Person person;
		person.ChangeFirstName(1, "Boom");
		AssertEqual(person.GetFullName(1), "Boom with unknown last name",
				"Simple change first name");
		AssertEqual(person.GetFullName(0), "Incognito",
				"Simple change first name but request before change");
	}

	{
		Person person;
		person.ChangeLastName(1, "Boom");
		AssertEqual(person.GetFullName(1), "Boom with unknown first name",
				"Simple change last name");
		AssertEqual(person.GetFullName(0), "Incognito",
				"Simple change last name but request before change");
	}

	{
		Person person;
		person.ChangeFirstName(1, "First");
		person.ChangeLastName(2, "Last");
		AssertEqual(person.GetFullName(2), "First Last",
				"Simple change Full name request in same year");
		AssertEqual(person.GetFullName(3), "First Last",
				"Simple change Full name request in future");
		person.ChangeLastName(3, "Last2");
		AssertEqual(person.GetFullName(3), "First Last2",
				"Second change Last name");
		AssertEqual(person.GetFullName(0), "Incognito",
				"Request full name after changes in future");
		AssertEqual(person.GetFullName(2), "First Last",
				"request 2 year before secon change last name");
		person.ChangeLastName(0, "God");
		AssertEqual(person.GetFullName(0), "God with unknown first name",
				"request after change in past");
		AssertEqual(person.GetFullName(3), "First Last2",
				"request in future after change in past");
	}
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestPerson, "Test person");
}

int main() {
	TestAll();
	// добавьте сюда свои тесты
	return 0;
}
