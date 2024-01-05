#pragma once
#include "Ticket.h"
#include "TicketType.h"

class TicketVIP : public Ticket {
public:
	void addBenefits() override {
		Ticket::addBenefits();
		this->benefits.push_back("photos with artist");
		this->benefits.push_back("signed merch");
		this->benefits.push_back("free drinks");
	}

	void readTicket() override {
		this->setType(VIP);
		Ticket::readTicket();
	}
};

