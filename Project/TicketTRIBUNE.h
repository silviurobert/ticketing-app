#pragma once
#include "Ticket.h"
class TicketTRIBUNE : public Ticket {
public: 
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

