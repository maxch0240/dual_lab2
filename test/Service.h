#pragma once
#include "Trip.h"

class Service {
public:
	Service();

	Service(string inputFile, string resultfile);

	void makeTrips();

	void clearBadTrips();

	void sortTrips();

	void divideTrips();

	void writeFile();

	void writeFile(string path);

	//test
	void showTrips();

	//test
	void showSizes();

	//test
	void showSchedules();
private:
	list<string> schedules;
	list<Trip> trips;
	list<string> SortedPoshTrip;
	list<string> SortedGrottyTrip;

	void readFile(); //path?
	void readFile(string path);
};
