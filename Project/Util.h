#pragma once
#include <string>
#include "TicketType.h"
#include <time.h>
#include <Windows.h>


class Util{
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}

	static std::string typeToString(TicketType type) {
		switch (type) {
			case TicketType::VIP:
				return "VIP Ticket";
			case TicketType::TRIBUNE:
				return "TRIBUNE Ticket";
			case TicketType::LAWN:
				return "LAWN Ticket";
			case TicketType::BOXES:
				return "BOXES Ticket";
			default:
				throw std::exception("Type not covered");
		}
	}

	static TicketType stringToType(std::string type) {
		if (type == "VIP") return TicketType::VIP;
		if (type == "TRIBUNE") return TicketType::TRIBUNE;
		if (type == "LAWN") return TicketType::LAWN;
		if (type == "BOXES") return TicketType::BOXES;
	}

	static int generateUniqueRandomNumber() {
		//to be sure you create an unique random number, use the Sleep() function below:
		//Sleep(1000);
		srand((unsigned)time(NULL));
		return rand();
	}
};

