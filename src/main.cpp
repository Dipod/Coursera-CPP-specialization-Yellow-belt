#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "test_runner.h"

using namespace std;

class Prefix {
public:
	Prefix(const char &c) {
		prefix = c;
	}
	Prefix(const string &s) {
		prefix = s;
	}
	string Get() const {
		return prefix;
	}
private:
	string prefix;
};

template<typename RandomIt>
pair<RandomIt, RandomIt> UniversalFindStartsWith(RandomIt range_begin,
		RandomIt range_end, const Prefix &prefix) {

	struct PrefixComparator {
		bool operator()(const string &s, const Prefix &i) const {
			string pref = i.Get();
			auto pref_size = pref.size(), s_size = s.size();
			if (pref_size <= s_size) {
				string temp(s.begin(), s.begin() + pref_size);
				return temp < pref;
			} else {
				return s < pref;
			}
		}
		bool operator()(const Prefix &i, const string &s) const {
			string pref = i.Get();
			auto pref_size = pref.size(), s_size = s.size();
			if (pref_size <= s_size) {
				string temp(s.begin(), s.begin() + pref_size);
				return pref < temp;
			} else {
				return pref < s;
			}
		}
	};

	return equal_range(range_begin, range_end, prefix, PrefixComparator { });

}

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
		RandomIt range_end, char prefix) {
	return UniversalFindStartsWith(range_begin, range_end, Prefix(prefix));
}

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
		RandomIt range_end, const string &prefix) {
	return UniversalFindStartsWith(range_begin, range_end, Prefix(prefix));
}

// Tests section

void MoTestStringPrefix() {

	const vector<string> sorted_strings =
			{ "moscow", "motovilikha", "murmansk" };

	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "mo");

	Assert(
			result.first - sorted_strings.begin() == 0
					&& result.second - sorted_strings.begin() == 2,
			"\"mo\" test from task");

}

void MtTestStringPrefix() {

	const vector<string> sorted_strings =
			{ "moscow", "motovilikha", "murmansk" };
	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "mt");
	Assert(
			result.first - sorted_strings.begin() == 2
					&& result.second - sorted_strings.begin() == 2,
			"\"mt\" test from task");

}

void NaTestStringPrefix() {

	const vector<string> sorted_strings =
			{ "moscow", "motovilikha", "murmansk" };
	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "na");
	Assert(
			result.first - sorted_strings.begin() == 3
					&& result.second - sorted_strings.begin() == 3,
			"\"na\" test from task");

}

void EmptyTestStringPrefix() {

	const vector<string> sorted_strings =
			{ "moscow", "motovilikha", "murmansk" };

	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "");
	cerr << "begin iterator " << result.first - sorted_strings.begin() << endl;
	cerr << "end iterator " << result.second - sorted_strings.begin() << endl;
	Assert(
			result.first - sorted_strings.begin() == 0
					&& result.second - sorted_strings.begin() == 3,
			"\"\" prefix test");

}

void ATestStringPrefix() {

	const vector<string> sorted_strings =
			{ "moscow", "motovilikha", "murmansk" };

	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "a");
	Assert(
			result.first - sorted_strings.begin() == 0
					&& result.second - sorted_strings.begin() == 0,
			"\"a\" prefix test");

}

void CharMTestStringPrefix() {
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), 'm');
	Assert(
			result.first - sorted_strings.begin() == 0
					&& result.second - sorted_strings.begin() == 2,
			"'m' prefix test from task");
}

void CharPTestStringPrefix() {
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };
	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), 'p');
	Assert(
			result.first - sorted_strings.begin() == 2
					&& result.second - sorted_strings.begin() == 2,
			"'p' prefix test from task");
}

void CharZTestStringPrefix() {
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };
	const auto result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), 'z');
	Assert(
			result.first - sorted_strings.begin() == 3
					&& result.second - sorted_strings.begin() == 3,
			"'z' prefix test from task");
}

// End of tests section

void TestAll() {
	TestRunner tr;
	tr.RunTest(MoTestStringPrefix, "\"mo\" test from task");
	tr.RunTest(MtTestStringPrefix, "\"mt\" test from task");
	tr.RunTest(NaTestStringPrefix, "\"na\" test from task");
	tr.RunTest(EmptyTestStringPrefix, "\"\" prefix test");
	tr.RunTest(ATestStringPrefix, "\"a\" prefix test");
	tr.RunTest(CharMTestStringPrefix, "'m' prefix test from task");
	tr.RunTest(CharPTestStringPrefix, "'p' prefix test from task");
	tr.RunTest(CharZTestStringPrefix, "'z' prefix test from task");
}

int main() {

	TestAll();
	return 0;
}
