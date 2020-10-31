#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {

	deque<string> result(1);
	int n = 0;
	cin >> result[0];

	cin >> n;
	char operation, prev_operation;
	int operand = 0;
	bool first_operation = true;
	for (int i = 0; i < n; i++) {
		cin >> operation;
		cin >> operand;
		if (first_operation) {
			string tail = " ";
			tail.append(1, operation);
			result.push_back(tail + " " + to_string(operand));
			first_operation = false;
		} else {
			if ((prev_operation == '-' || prev_operation == '+')
					&& (operation == '*' || operation == '/')) {
				result.push_front("(");
				string tail = ") ";
				tail.append(1, operation);
				result.push_back(tail + " " + to_string(operand));
			} else {
				string tail = " ";
				tail.append(1, operation);
				result.push_back(tail + " " + to_string(operand));
			}
		}
		prev_operation = operation;
	}

	for (const auto &string_part : result) {
		cout << string_part;
	}

	return 0;
}
