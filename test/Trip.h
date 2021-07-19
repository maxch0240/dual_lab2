#pragma once
#include <iostream>
#include <string>
#include <list>
#include <sstream>  
#include <fstream>
#include <cmath>
using namespace std;

class Trip {
public:
	Trip(string& schedule);

	string getCompany();

	string getDeparture();

	string getArrival();

	int getDepartureInMinutes();

	int getArrivalInMinutes();
private:
	string company, departure, arrival;
	int departureInMinutes, arrivalInMinutes;

	void split(string& str); 

	int convertTimeToMinutes(string& str);
};