#include <iostream>
using namespace std;
#include "Location.h"
#include "Event.h"

int main() {

	Location location1(2000, 100, 20);
	cout << endl << "The first location details are: ";
	cout << endl << "The maximum number of seats is: " << location1.getNumberOfSeats();
	cout << endl << "The number of rows is: " << location1.getNumberOfRows();
	cout << endl << "The number of seats per row is: " << location1.getSeatsPerRow();

	Event event1("The Weeknd Concert", "04/08/2023", "18:00", "23:00", "The best concert ever!");
	cout << endl << "The first event details are: ";
	cout << endl << "Event name: " << event1.getEventName();
	cout << endl << "Event date: " << event1.getEventDate();
	cout << endl << "Event start time: " << event1.getEventStartTime();
	cout << endl << "Event end time: " << event1.getEventEndTime();
	cout << endl << "Event description: " << event1.getEventDescription();
	
}