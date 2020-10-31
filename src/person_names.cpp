#include <string>
#include <map>

typedef std::map<int, std::string> NamesByYears;

std::string GetName(const int &year, const NamesByYears &name_changes);

class Person {
public:
	void ChangeFirstName(const int &year, const std::string &first_name);
	void ChangeLastName(const int &year, const std::string &last_name);
	std::string GetFullName(const int &year) const;
private:
	NamesByYears first_name_changes;
	NamesByYears last_name_changes;
};

void Person::ChangeFirstName(const int &year, const std::string &first_name) {
	first_name_changes[year] = first_name;
}

void Person::ChangeLastName(const int &year, const std::string &last_name) {
	last_name_changes[year] = last_name;
}

std::string Person::GetFullName(const int &year) const {
	std::string first_name = GetName(year, first_name_changes);
	std::string last_name = GetName(year, last_name_changes);

	if (first_name == "" && last_name == "") {
		return "Incognito";
	}

	if (first_name == "") {
		return last_name + " with unknown first name";
	}

	if (last_name == "") {
		return first_name + " with unknown last name";
	}

	return first_name + ' ' + last_name;
}

std::string GetName(const int &year, const NamesByYears &name_changes) {

	auto border = name_changes.upper_bound(year);

	if (border != name_changes.begin()) {
		return prev(border)->second;
	} else {
		return "";
	}
}

