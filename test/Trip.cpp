#pragma once
#include "Trip.h"

string Trip::getCompany() {
	return this->company;
}

string Trip::getDeparture() {
	return this->departure;
}

string Trip::getArrival() {
	return this->arrival;
}

int Trip::getDepartureInMinutes() {
	return this->departureInMinutes;
}

int Trip::getArrivalInMinutes() {
	return this->arrivalInMinutes;
}

Trip::Trip(string& schedule) {
	split(schedule);
	this->departureInMinutes = convertTimeToMinutes(this->departure);
	this->arrivalInMinutes = convertTimeToMinutes(this->arrival);
}

void Trip::split(string& str) {
	string delim(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	next = str.find(delim, prev);
	this->company = str.substr(prev, next - prev);

	prev = next + delta;
	next = str.find(delim, prev);
	this->departure = str.substr(prev, next - prev);

	prev = next + delta;
	next = str.find(delim, prev);
	this->arrival = str.substr(prev, next - prev);
}

//rewrite
int Trip::convertTimeToMinutes(string& str)
{
	istringstream ss(str);
	string hh, mm;
	getline(ss, hh, ':');
	getline(ss, mm, ';');
	int nhh = atoi(hh.c_str());
	int nmm = atoi(mm.c_str());
	return nhh * 60 + nmm;

}