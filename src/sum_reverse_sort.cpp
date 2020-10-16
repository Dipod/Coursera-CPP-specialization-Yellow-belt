#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
	return x + y;
}
string Reverse(string s) {
	string result = "";
	for (auto it = rbegin(s); it != rend(s); it++) {
		result += *it;
	}
	return result;
}
void Sort(vector<int> &nums) {
	std::sort(nums.begin(), nums.end());
}
