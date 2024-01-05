#pragma once
#include "Ticket.h"
class TicketLAWN : public Ticket {
public: 
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

