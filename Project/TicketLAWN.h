#pragma once
#include "Ticket.h"
class TicketLAWN : public Ticket {
public: 
	virtual void displayBenefits() {
		std::cout << "More space, closest to the stage, you can bring your own chair";
	}
};

