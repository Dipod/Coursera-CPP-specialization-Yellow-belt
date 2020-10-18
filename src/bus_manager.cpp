#include "bus_manager.h"

void BusManager::AddBus(const std::string &bus, const std::vector<std::string> &stops) {
	for (const auto &stop : stops) {
		buses_to_stops[bus].push_back(stop);
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string &stop) const {
	BusesForStopResponse response;
	response.is_empty = stops_to_buses.count(stop) == 0;
	if (!response.is_empty) {
		response.buses_for_stop = stops_to_buses.at(stop);
	}
	return response;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string &bus) const {
	StopsForBusResponse response;
	response.is_empty = buses_to_stops.count(bus) == 0;
	if (!response.is_empty) {
		response.bus = bus;
		response.stops_for_bus = buses_to_stops.at(bus);
		response.stops_to_buses = stops_to_buses;
	}

	return response;
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse response;
	response.is_empty = buses_to_stops.empty();
	if (!response.is_empty) {
		response.buses_to_stops = buses_to_stops;
	}
	return response;
}

