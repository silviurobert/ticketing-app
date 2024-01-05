#pragma once
#include "Ticket.h"
class TicketBOXES : public Ticket {
public:
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

