#include "Service.h"

Service::Service() {
	readFile();
	makeTrips();
	clearBadTrips();
	sortTrips();
	divideTrips();
	writeFile();
};

Service::Service(string inputFile, string resultFile) {
	readFile(inputFile);
	makeTrips();
	clearBadTrips();
	sortTrips();
	divideTrips();
	writeFile(resultFile);
};

void Service::readFile() {
	ifstream file("D:\\C++\\test3\\schedule.txt");
	string line;
	if (file)
	{
		while (getline(file, line)) {
			this->schedules.push_back(line);
		}
	}
	else {
		cout << "file not open\n";
		return;
	}
	file.close();
}

void Service::readFile(string path) {
	ifstream file(path);
	string line;
	if (file)
	{
		while (getline(file, line)) {
			this->schedules.push_back(line);
		}
	}
	else {
		cout << "file not open\n";
		return;
	}
	file.close();
}

void Service::makeTrips() {
	for (auto it = this->schedules.begin(); it != this->schedules.end(); ++it) {
		this->trips.push_back(*(new Trip(*it)));		
	}
		
}

void Service::clearBadTrips() {
	int departureInMinutes, arrivalInMinutes;
	int departureInMinutes2, arrivalInMinutes2;
	for (auto it = this->trips.begin(); it != this->trips.end(); ++it) {
		for (auto it2 = this->trips.begin(); it2 != this->trips.end(); ++it2) {
			if (it == it2) continue;
			departureInMinutes = it->getDepartureInMinutes();
			arrivalInMinutes = it->getArrivalInMinutes();
			departureInMinutes2 = it2->getDepartureInMinutes();
			arrivalInMinutes2 = it2->getArrivalInMinutes();

			if ((abs(arrivalInMinutes - departureInMinutes) > 60) 
				|| (departureInMinutes < departureInMinutes2 && arrivalInMinutes > arrivalInMinutes2)
				|| (departureInMinutes < departureInMinutes2 && arrivalInMinutes == arrivalInMinutes2)
				|| (departureInMinutes == departureInMinutes2 && arrivalInMinutes > arrivalInMinutes2) 
				|| (departureInMinutes == departureInMinutes2 && arrivalInMinutes == arrivalInMinutes2 
					&& it->getCompany() != "Posh")) {
				it = this->trips.erase(it);
			}
			
		}
	}
}

void Service::sortTrips() {
	this->trips.sort([](Trip& a, Trip& b) { return a.getDepartureInMinutes() < b.getDepartureInMinutes(); });
}

void Service::divideTrips() {
	string str;
	for (auto it = this->trips.begin(); it != this->trips.end(); ++it) {		
		if (it->getCompany() == "Posh") {
			str = it->getCompany() + " " + it->getDeparture() + " " + it->getArrival();
			this->SortedPoshTrip.push_back(str);
		}
		else {
			str = it->getCompany() + " " + it->getDeparture() + " " + it->getArrival();
			this->SortedGrottyTrip.push_back(str);
		}
	}
}

void Service::writeFile() {
	ofstream resultFile;
	resultFile.open("D:\\C++\\test\\result.txt");
	if (resultFile)
	{
		for (auto it = this->SortedPoshTrip.begin(); it != this->SortedPoshTrip.end(); ++it) {
			resultFile << *it << endl;
		}
		resultFile << endl;
		for (auto it = this->SortedGrottyTrip.begin(); it != this->SortedGrottyTrip.end(); ++it) {
			resultFile << *it << endl;
		}
	}
	else {
		cout << "file not open\n";
		return;
	}
}

void Service::writeFile(string path) {
	ofstream resultFile;
	resultFile.open(path);
	if (resultFile)
	{
		for (auto it = this->SortedPoshTrip.begin(); it != this->SortedPoshTrip.end(); ++it) {
			resultFile << *it << endl;
		}
		resultFile << endl;
		for (auto it = this->SortedGrottyTrip.begin(); it != this->SortedGrottyTrip.end(); ++it) {
			resultFile << *it << endl;
		}
	}
	else {
		cout << "file not open\n";
		return;
	}
}


//test
void Service::showTrips() {
	for (auto it = this->trips.begin(); it != this->trips.end(); ++it) {
		cout << it->getCompany() << " " << it->getDeparture() << " " << it->getArrival() << endl;
		//test
		if (abs(it->getArrivalInMinutes() - it->getDepartureInMinutes()) > 60) {
			cout << "shit" << endl;
		}
	}
}

//test
void Service::showSizes() {
	cout << "schedule size " << this->schedules.size() << endl <<
		"trips size " << this->trips.size() << endl;
}

//test
void Service::showSchedules() {
	for (auto it = this->schedules.begin(); it != this->schedules.end(); ++it) {
		cout << *it << endl;
	}
}