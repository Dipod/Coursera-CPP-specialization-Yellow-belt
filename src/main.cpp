#include <map>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

template<typename BasicType> BasicType Sqr(const BasicType &item);
template<typename First, typename Second> pair<First, Second> Sqr(
		const pair<First, Second> p1);
template<typename Element> vector<Element> Sqr(vector<Element> c);
template<typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value> c);

template<typename BasicType>
BasicType Sqr(const BasicType &item) {
	return item * item;
}

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> p1) {
	First f = Sqr(p1.first);
	Second s = Sqr(p1.second);
	return {f, s};
}

template<typename Element>
vector<Element> Sqr(vector<Element> c) {
	for (Element &item : c) {
		item = Sqr(item);
	}
	return c;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> c) {
	for (auto &item : c) {
		item.second = Sqr(item.second);
	}
	return c;
}

int main() {

	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = { { 4, { 2, 2 } }, { 7, { 4, 3 } } };
	cout << "map of pairs:" << endl;
	for (const auto &x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second
				<< endl;
	}

	return 0;
}

