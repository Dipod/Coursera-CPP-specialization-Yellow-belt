#include "phone_number.h"
#include <stdexcept>
#include <vector>

PhoneNumber::PhoneNumber(const string &international_number) {
	if (international_number.empty()) {
		throw invalid_argument("Invalid phone number");
	}

	if (international_number[0] != '+') {
		throw invalid_argument("Invalid phone number");
	}
	vector<string*> number_parts =
			{ &country_code_, &city_code_, &local_number_ };
	size_t j = 0;
	for (size_t i = 1; i < international_number.size(); i++) {
		if (international_number.at(i) == '-' && j < number_parts.size() - 1) {
			j++;
		} else {
			*number_parts.at(j) += international_number[i];
		}
	}
	if (country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		throw invalid_argument("Invalid phone number");
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
