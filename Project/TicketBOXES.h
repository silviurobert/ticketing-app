#pragma once
#include "Ticket.h"
class TicketBOXES : public Ticket {
public:
	TicketBOXES(Event event, int row, int seat, char* backInfo) : Ticket(event, row, seat, backInfo) {
		this->setType(BOXES);
	}

	void addBenefits() override {
		Ticket::addBenefits();
		this->benefits.push_back("priority services");
		this->benefits.push_back("better view");
		this->benefits.push_back("catering services");
	}

	void readTicket() override {
		this->setType(BOXES);
		Ticket::readTicket();
	}
};

