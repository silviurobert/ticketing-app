#pragma once
#include "Ticket.h"
class TicketLAWN : public Ticket {
public: 
	TicketLAWN(Event event, int row, int seat, char* backInfo) : Ticket(event, row, seat, backInfo) {
		this->setType(LAWN);
	}
	void addBenefits() override {
		Ticket::addBenefits();
		this->benefits.push_back("more space");
		this->benefits.push_back("closest to the stage");
		this->benefits.push_back("you can bring your own chair");
	}

	void readTicket() override {
		this->setType(LAWN);
		Ticket::readTicket();
	}
};

