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

Ticket* generateTicket(TicketType type, Event event, int row, int seat, char* backInfo) {
    Ticket* ticket = nullptr;

    switch (type) {
        case VIP: ticket = new TicketVIP(event, row, seat, backInfo); break;
        case LAWN: ticket = new TicketLAWN(event, row, seat, backInfo); break;
        case TRIBUNE: ticket = new TicketTRIBUNE(event, row, seat, backInfo); break;
        case BOXES: ticket = new TicketBOXES(event, row, seat, backInfo); break;
    }
    return ticket;
}


int main() { 
    vector<Location> locations;
    vector<Event> events;
    vector<Ticket*> tickets;

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
                    //cout << locations[locationIndex].getLocationDescription() << endl;
                    Event* event = new Event(eventName, eventDate, locations[locationIndex], eventStartTime, eventEndTime);
                    events.push_back(*event);
                }
            }
        }
    }
    
    eventsFile.close();


    //MENU    
    int key = 0;

    do {
        cout << "[1] DISPLAY ALL EVENTS" << endl;
        cout << "[2] BOOK A TICKET" << endl;
        cout << "[3] DISPLAY ALL TICKETS" << endl;
        cout << "[4] CHECK TICKET" << endl;
        cout << "[0] EXIT" << endl;

        cout << "Select from options displayed above: ";
        cin >> key;

        switch (key) {
        case 1: {
            for (auto& element : events) {
                element.display();
            }
        } break;
        case 2: {
            try {
                int index = 1;
                for (auto& element : events) {
                    cout << "[" << index << "]" << element.getEventName() << endl;
                    index++;
                }
                cout << "CHOOSE EVENT FROM ABOVE:";
                int eventIndex;
                cin >> eventIndex;
                events[eventIndex - 1].getLocation()->displayAvailableSeats();
                cout << "CHOOSE YOUR SEAT:\n";
                int row, seat;
                cout << "ROW:"; cin >> row;
                cout << "SEAT:"; cin >> seat;
                Location* location = events[eventIndex - 1].getLocation();
                if (row <= 0 || row >= location->getNumberOfRows() || seat <= 0 || seat >= location->getSeatsPerRow()) {
                   cout << "Invalid input!\n";
                   break;
                }

                cout << endl << "Ticket type (VIP, TRIBUNE, LAWN, BOXES): ";
                string type;
                cin >> type;

                char backInfo[] = "The best event!";
                //events[eventIndex - 1].display();


                Ticket* ticket = generateTicket(Util::stringToType(type), events[eventIndex - 1], row, seat, backInfo);

                tickets.push_back(ticket);
                cout << "Ticket has been booked sucessfully!\n";
                ticket->display();

            }
            catch (exception e) {
                cout << "Invalid Input\n";
            }
                
                
                
            
            
            
        } break;
        case 3: {
            for (auto& element : tickets) {
                 element->display();
            }
            
        } break;
        case 4: {
            int ticketId;
            cout << "CHECK TICKET ID: ";
            cin >> ticketId;
            int found = 0;
            for (auto& element : tickets) {
                if (element->getId() == ticketId) {
                    found = 1;
                   
                    break;
                }
                
            } 
            if (found) {
                cout << "Ticket is valid!\n";
               
            }
            else {
                cout << "Ticket is not valid!\n";
            }
            
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

    } while (key != 0);
    return 0;
}

