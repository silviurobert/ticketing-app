#pragma once
#include "Ticket.h"
class TicketTRIBUNE : public Ticket {
public: 
	TicketTRIBUNE(Event event, int row, int seat, char* backInfo) : Ticket(event, row, seat, backInfo) {
		this->setType(TRIBUNE);
	}

	void addBenefits() override {
		Ticket::addBenefits();
		this->benefits.push_back("priority services");
		this->benefits.push_back("better view");
		this->benefits.push_back("invitation to pre or post events");
	}

	void readTicket() override {
		this->setType(TRIBUNE);
		Ticket::readTicket();
	}
};

