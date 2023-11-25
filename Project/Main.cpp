#include <iostream>
#include <string.h>
using namespace std;
#include "Util.h"
#include "Location.h"
#include "Event.h"
#include "Ticket.h"


int main() {

	Location location1(2000, 100, 20, "Very spacious location");
	cout << endl << "The first location details are: ";
	cout << endl << "The maximum number of seats is: " << location1.getNumberOfSeats();
	cout << endl << "The number of rows is: " << location1.getNumberOfRows();
	cout << endl << "The number of seats per row is: " << location1.getSeatsPerRow();
	cout << endl << "Location description: " << location1.getLocationDescription();

	cout << endl << "-----------------------------------------------------";
	Event event1("The Weeknd Concert", "04/08/2023", location1, "18:00", "23:00", "The best concert ever!");
	cout << endl << "The first event details are: ";
	cout << endl << "Event name: " << event1.getEventName();
	cout << endl << "Event date: " << event1.getEventDate();
	cout << endl << "Event start time: " << event1.getEventStartTime();
	cout << endl << "Event end time: " << event1.getEventEndTime();
	cout << endl << "Event description: " << event1.getEventDescription();

	cout << endl << "-----------------------------------------------------";

	//cout << endl << "Box State: " << Util::stateToString(box.getState());
	

	Ticket ticket1(event1, 20, 16, "Check our website: www.concert-goers.com");
	cout << endl << "The concert name is:" << ticket1.getEvent()->getEventName();
	cout << endl << "The row number is:" << ticket1.getRow();
	cout << endl << "The seat number is:" << ticket1.getSeat();
	cout << endl << "Info regarding the concert: " << ticket1.getBackInfo();
	cout << endl << "Type: " << Util::typeToString(ticket1.getType());
}