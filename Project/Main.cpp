#include <iostream>
#include <string.h>
using namespace std;
#include "Util.h"
#include "Location.h"
#include "Event.h"
#include "Ticket.h"


int main() {
    //MENU 
    Location* location = new Location();
    Event* event = new Event();
    Ticket* ticket = new Ticket();
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

    } while (key != 0);
    return 0;
}