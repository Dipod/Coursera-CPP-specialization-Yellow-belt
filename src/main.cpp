#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class QueryType {
	NewBus, BusesForStop, StopsForBus, AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >>(istream &is, Query &q) {

	string operation_code;
	is >> operation_code;

	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;

		int stop_count;
		is >> stop_count;
		q.stops.resize(stop_count);
		for (string &stop : q.stops) {
			is >> stop;
		}
	} else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}

	return is;
}

struct BusesForStopResponse {
	bool is_empty;
	vector<string> buses_for_stop;
};

ostream& operator <<(ostream &os, const BusesForStopResponse &r) {
	if (r.is_empty) {
		os << "No stop";
	} else {
		for (const string &bus : r.buses_for_stop) {
			os << bus << " ";
		}
	}
	return os;
}

struct StopsForBusResponse {
	bool is_empty;
	vector<string> stops_for_bus;
	string bus;
	map<string, vector<string>> stops_to_buses;
};

ostream& operator <<(ostream &os, const StopsForBusResponse &r) {

	if (r.is_empty) {
		os << "No bus";
	} else {
		bool first = true;
		for (const string &stop : r.stops_for_bus) {
			if (!first) {
				os << endl;
			}
			os << "Stop " << stop << ": ";
			if (r.stops_to_buses.at(stop).size() == 1) {
				os << "no interchange";
			} else {
				for (const string &other_bus : r.stops_to_buses.at(stop)) {
					if (r.bus != other_bus) {
						os << other_bus << " ";
					}
				}
			}
			first = false;
		}
	}

	return os;
}

struct AllBusesResponse {
	bool is_empty;
	map<string, vector<string>> buses_to_stops;
};

ostream& operator <<(ostream &os, const AllBusesResponse &r) {
	if (r.is_empty) {
		os << "No buses";
	} else {
		for (const auto &bus_item : r.buses_to_stops) {
			os << "Bus " << bus_item.first << ": ";
			for (const string &stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	return os;
}

class BusManager {
public:
	void AddBus(const string &bus, const vector<string> &stops) {
		for (const auto &stop : stops) {
			buses_to_stops[bus].push_back(stop);
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string &stop) const {
		BusesForStopResponse response;
		response.is_empty = stops_to_buses.count(stop) == 0;
		if (!response.is_empty) {
			response.buses_for_stop = stops_to_buses.at(stop);
		}
		return response;
	}

	StopsForBusResponse GetStopsForBus(const string &bus) const {
		StopsForBusResponse response;
		response.is_empty = buses_to_stops.count(bus) == 0;
		if (!response.is_empty) {
			response.bus = bus;
			response.stops_for_bus = buses_to_stops.at(bus);
			response.stops_to_buses = stops_to_buses;
		}

		return response;
	}

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse response;
		response.is_empty = buses_to_stops.empty();
		if (!response.is_empty) {
			response.buses_to_stops = buses_to_stops;
		}
		return response;
	}
private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	stringstream input(
			"10\n"
					"ALL_BUSES\n"
					"BUSES_FOR_STOP Marushkino\n"
					"STOPS_FOR_BUS 32K\n"
					"NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo\n"
					"NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo\n"
					"BUSES_FOR_STOP Vnukovo\n"
					"NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo\n"
					"NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo\n"
					"STOPS_FOR_BUS 272\n"
					"ALL_BUSES\n");

	input >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		input >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
