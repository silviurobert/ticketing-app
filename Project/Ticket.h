#pragma once
#include <string>
#include "TicketType.h"
#include "Util.h"
#include "Event.h"


class Ticket{
private:
	int id = 0;
	Event* event;
	TicketType type = TicketType::VIP;
	int row = 0;
	int seat = 0;
	char* backInfo = nullptr;

public:
	//Ctor without params
	Ticket() {
		this->id = Util::generateUniqueRandomNumber();
		this->event = new Event();
	}

	//Ctor with params
	Ticket( Event event, int row, int seat, const char* backInfo) : row(row), seat(seat) {
		this->setBackInfo(backInfo);
		this->id = Util::generateUniqueRandomNumber();
		this->event = new Event(event.getEventName(), event.getEventDate(), *event.getLocation(), event.getEventStartTime(), 
			event.getEventEndTime(), event.getEventDescription());
	}

	//copy ctor
	Ticket(const Ticket& ticket) {
		this->setBackInfo(ticket.backInfo);
		this->setRow(ticket.row);
		this->setSeat(ticket.seat);
		this->id = ticket.id;
		this->event = ticket.event;
	}

	//Getters and Setters
	int getId() {
		return this->id;
	}

	void setId(int id) {
		this->id = id;
	}

	Event* getEvent() {
		return this->event;
	}

	void setEvent(Event* event) {
		this->event = event;
	}

	TicketType getType() {
		return this->type;
	}

	void setType(TicketType type) {
		this->type = type;
	}

	int getRow() {
		return this->row;
	}

	void setRow(int value) {
		this->row = value;
	}

	int getSeat() {
		return this->seat;
	}

	void setSeat(int value) {
		this->row = value;
	}

	char* getBackInfo() {
		char* copy = Util::copyString(this->backInfo);
		return copy;
	}

	void setBackInfo(const char* info) {
		this->backInfo = Util::copyString(info);
	}

	void vip() {
		this->type = TicketType::VIP;
	}

	void lawn() {
		this->type = TicketType::LAWN;
	}

	void tribune() {
		this->type = TicketType::TRIBUNE;
	}

	void boxes() {
		this->type = TicketType::BOXES;
	}

	void operator=(const Ticket& source) {
		if (&source == this) {
			return;
		}
		this->setId(source.id);
		this->setEvent(source.event);
		this->setType(source.type);
		this->setRow(source.row);
		this->setSeat(source.seat);
		this->setBackInfo(source.backInfo);
	}

	bool operator==(Ticket ticket) {
		return this->id == ticket.id;
	}

	void readTicket() {
		std::cout << std::endl << "Ticket type (VIP, TRIBUNE, LAWN, BOXES): ";
		std::string type;
		std::cin >> type;
		this->setType(Util::stringToType(type));

		std::cout << "Row number: ";
		std::cin >> this->row;

		std::cout << "Seat number: ";
		std::cin >> this->seat;

		std::cout << "Back info: ";
		std::string info;
		std::cin >> info;
		this->setBackInfo(info.c_str());
	}

	void displayTicket() {
		if (this->backInfo == nullptr) return;
		std::cout << "Ticket: ID:" << this->id << ", type:" << Util::typeToString(this->type) <<
			", rowNo:" << this->row << ", seatNo:" << this->seat << ", backInfo:" << this->backInfo << std::endl;
		this->event->displayEvent();
	}

	//Destructor
	~Ticket() {
		delete[] this->event;
		delete[] this->backInfo;
	}

};

