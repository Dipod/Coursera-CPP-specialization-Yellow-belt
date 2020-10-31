#include <iostream>
#include <map>

typedef std::map<int, std::string> NamesByYears;

class Person {
public:
	void ChangeFirstName(const int &year, const std::string &first_name);
	void ChangeLastName(const int &year, const std::string &last_name);
	std::string GetFullName(const int &year) const;
private:
	NamesByYears first_name_changes;
	NamesByYears last_name_changes;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : { 1900, 1965, 1990 }) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : { 1969, 1970 }) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : { 1969, 1970 }) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	return 0;
}
