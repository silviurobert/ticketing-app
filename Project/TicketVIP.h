#pragma once
#include "Ticket.h"
#include "TicketType.h"

class TicketVIP : public Ticket {
public:
	virtual void displayBenefits() {
		std::cout << "Photos with artist, signed merch, free drinks";
	}

	void readTicket() override {
		this->setType(VIP);
		Ticket::readTicket();
	}
};

