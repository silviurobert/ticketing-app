#include <iostream>
using namespace std;
#include "Location.h"

int main() {

	Location location1(2000, 100, 20);

	cout << endl << "2000, 100, 20";
	cout << endl << "The maximum number of seats is: " << location1.getNumberOfSeats();
	cout << endl << "The number of rows is: " << location1.getNumberOfRows();
	cout << endl << "The number of seats per row is: " << location1.getSeatsPerRow();
	
}