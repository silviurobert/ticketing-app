#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
#include "Displayable.h"
#include "Util.h"
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "TicketType.h"
#include "TicketVIP.h"
#include "TicketBOXES.h"
#include "TicketTRIBUNE.h"
#include "TicketLAWN.h"
#include <vector>




//clasa abstracta cu metoda pura
//fisiere
//citire despre locatii eventuri tickete
//sa generam prin meniu un ticket
//sa fie unice
//sa salvam intr un fisier binar
//sa citim ce am pus in el

Ticket* readTicket(TicketType type) {
    Ticket* ticket = nullptr;
    switch (type) {
        case VIP: ticket = new TicketVIP(); break;
        case LAWN: ticket = new TicketLAWN(); break;
        case TRIBUNE: ticket = new TicketTRIBUNE(); break;
        case BOXES: ticket = new TicketBOXES(); break;
    }
    ticket->readTicket();

    return ticket;
}



int main() {
    vector<Location> locations;
    vector<Event> events;

    ifstream locationsFile("locations.txt");
    if (!locationsFile.is_open()) {
        cerr << "Unable to open the file";
        return 1;
    }

    string line;
    int maxNumberOfSeats = 0;
    int numberOfRows = 0;
    int seatsPerRow = 0;
    char* locationDescription = nullptr;

    while (getline(locationsFile, line)) {
       
        istringstream iss(line);
        if (iss >> maxNumberOfSeats >> numberOfRows >> seatsPerRow) {
            if (getline(locationsFile, line)) {
                locationDescription = new char[line.length() + 1];
                strcpy(locationDescription, line.c_str());
                Location* location = new Location(maxNumberOfSeats, numberOfRows, seatsPerRow, locationDescription);
                locations.push_back(*location);
            }
        }
        
        
    }
    for (auto& element : locations) {
          element.display() ;
    }
    locationsFile.close();

    cout << endl << endl;

    string eventName = "";
	char eventDate[11] = ""; // dd/mm/yyyy
	int locationIndex;
	char eventStartTime[6] = ""; // hh:mm
	char eventEndTime[6] = ""; // hh:mm
	char* eventDescription = nullptr;	

    ifstream eventsFile("events.txt");
    if (!eventsFile.is_open()) {
        cerr << "Unable to open the file";
        return 1;
    }
    

    while (getline(eventsFile, line)) {
        eventName = line;
        if (getline(eventsFile, line)){
            istringstream iss(line);
            if (iss >> eventDate >> locationIndex >> eventStartTime >> eventEndTime) {
                if (getline(eventsFile, line)) {
                    eventDescription = new char[line.length() + 1];
                    strcpy(eventDescription, line.c_str());
                    Event* event = new Event(eventName, eventDate, locations[locationIndex], eventStartTime, eventEndTime, eventDescription);
                    events.push_back(*event);
                }
            }
        }
    }
    for (auto& element : events) {
        element.display();
    }
    eventsFile.close();

    //MENU 
    
    /*location->readLocation();
    locations.push_back(*location);
    locations.push_back(*location);
    locations.push_back(*location);
    for (auto& loc : locations) {
        loc.displayLocation();
    }*/

    /* Event* event = new Event();

    cout << endl << "Ticket type (VIP, TRIBUNE, LAWN, BOXES): ";
    string type;
    cin >> type;
        
    Ticket* ticket = readTicket(Util::stringToType(type));
    ticket->display();
    ticket->displayBenefits();
    int key = 0;

    do {
        cout << "[1] CREATE NEW LOCATION" << endl;
        cout << "[2] CREATE NEW EVENT" << endl;
        cout << "[3] CREATE NEW TICKET" << endl;
        cout << "[4] DISPLAY LOCATION" << endl;
        cout << "[5] DISPLAY EVENT" << endl;
        cout << "[6] DISPLAY TICKET" << endl;
        cout << "[0] EXIT" << endl;

        cout << "Select from options displayed above: ";
        cin >> key;

        switch (key) {
        case 1: {
            location->readLocation();
            cout << "New Location has beeen creatd" << endl << endl;
        } break;
        case 2: {
            int finished = 0;
            while(finished == 0)
            {
                try {
                    event->readEvent();
                    event->setLocation(location);
                    cout << "New event has been created" << endl << endl;
                    finished = 1;
                }
                catch (exception e) {
                    cout << endl  << "Data input error! Please try again.";
                    finished = 0;
                }
            }
            
        } break;
        case 3: {
            ticket->readTicket();
            ticket->setEvent(event);
            cout << "New ticket has been created" << endl << endl;
        } break;
        case 4: {
            location->displayLocation();
        } break;
        case 5: {
            event->displayEvent();
        } break;
        case 6: {
            ticket->displayTicket();
        } break;
        case 0: {
            cout << "[0] EXIT" << endl;
        } break;
        default: cout << "Please select from the menu..." << endl;
        }
        cout << "[1]Yes\n[0]No\n";
        cout << "Do you want to continue?\n";
        cout << "Select from options displayed above: ";
        cin >> key;

    } while (key != 0);*/
    return 0;
}

