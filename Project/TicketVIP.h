#pragma once
#include "Ticket.h"

class TicketVIP : public Ticket {
public:
	virtual void displayBenefits() {
		std::cout << "Photos with artist, signed merch, free drinks";
	}
};

