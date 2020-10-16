#include "test_runner.h"
#include <vector>
#include "phone_number.h"
#include <stdexcept>

using namespace std;

// Tests section

void TestPhoneNumber() {

	{
		PhoneNumber p("+7-495-111-22-33");
		AssertEqual(p.GetCountryCode(), "7",
				"Country code of number +7-495-111-22-33");
		AssertEqual(p.GetCityCode(), "495",
				"City code of number +7-495-111-22-33");
		AssertEqual(p.GetLocalNumber(), "111-22-33",
				"Local number of number +7-495-111-22-33");
		AssertEqual(p.GetInternationalNumber(), "+7-495-111-22-33",
				"International number of number +7-495-111-22-33");
	}

	{
		PhoneNumber p("+7-495-1112233");
		AssertEqual(p.GetCountryCode(), "7",
				"Country code of number +7-495-1112233");
		AssertEqual(p.GetCityCode(), "495",
				"City code of number +7-495-1112233");
		AssertEqual(p.GetLocalNumber(), "1112233",
				"Local number of number +7-495-1112233");
		AssertEqual(p.GetInternationalNumber(), "+7-495-1112233",
				"International number of number +7-495-1112233");
	}

	{
		PhoneNumber p("+323-22-460002");
		AssertEqual(p.GetCountryCode(), "323",
				"Country code of number +323-22-460002");
		AssertEqual(p.GetCityCode(), "22",
				"City code of number +323-22-460002");
		AssertEqual(p.GetLocalNumber(), "460002",
				"Local number of number +323-22-460002");
		AssertEqual(p.GetInternationalNumber(), "+323-22-460002",
				"International number of number +323-22-460002");
	}

	{
		PhoneNumber p("+1-2-coursera-cpp");
		AssertEqual(p.GetCountryCode(), "1",
				"Country code of number +1-2-coursera-cpp");
		AssertEqual(p.GetCityCode(), "2",
				"City code of number +1-2-coursera-cpp");
		AssertEqual(p.GetLocalNumber(), "coursera-cpp",
				"Local number of number +1-2-coursera-cpp");
		AssertEqual(p.GetInternationalNumber(), "+1-2-coursera-cpp",
				"International number of number +1-2-coursera-cpp");
	}

	{
		try {
			PhoneNumber p("1-2-333");
		} catch (invalid_argument &ex) {
		}
	}

	{
		try {
			PhoneNumber p("+7-1233");
		} catch (invalid_argument &ex) {
		}
	}
}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestPhoneNumber, "TestPhoneNumber");
}

int main() {
	TestAll();

	return 0;
}

