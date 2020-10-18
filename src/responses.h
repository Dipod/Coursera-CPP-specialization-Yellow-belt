#pragma once

#include <vector>
#include <string>
#include <map>

struct BusesForStopResponse {
	bool is_empty;
	std::vector<std::string> buses_for_stop;
};

std::ostream& operator <<(std::ostream &os, const BusesForStopResponse &r);

struct StopsForBusResponse {
	bool is_empty;
	std::vector<std::string> stops_for_bus;
	std::string bus;
	std::map<std::string, std::vector<std::string>> stops_to_buses;
};

std::ostream& operator <<(std::ostream &os, const StopsForBusResponse &r);

struct AllBusesResponse {
	bool is_empty;
	std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator <<(std::ostream &os, const AllBusesResponse &r);
