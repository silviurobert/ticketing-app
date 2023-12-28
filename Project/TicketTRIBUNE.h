#pragma once
#include "Ticket.h"
class TicketTRIBUNE : public Ticket {
public: 
	virtual void displayBenefits() {
		std::cout << "Priority services, better view, invitation to pre or post events";
	}
};

