#pragma once
#include "Ticket.h"
class TicketBOXES : public Ticket {
public:
	virtual void displayBenefits() {
		std::cout << "Priority services, better view, catering services";
	}

	void readTicket() override {
		this->setType(BOXES);
		Ticket::readTicket();
	}
};

