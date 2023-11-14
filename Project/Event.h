#pragma once
#include <string>
#include "Util.h"
using namespace std;
class Event{
private:
	string eventName = "";
	char eventDate[11] = ""; // dd/mm/yyyy
	char eventStartTime[6] = ""; // hh:mm
	char eventEndTime[6] = ""; // hh:mm
	char* eventDescription = nullptr;	

public:
	string getEventName() {
		return this->eventName;
	}
	
	char* getEventDate() {
		return Util::copyString(this->eventDate);
	}

	void setEventDate(const char* newEventDate) {
		if (strlen(newEventDate) != 10) {
			throw exception("Wrong date");
		}
		if (newEventDate[2] != '/' || newEventDate[5] != '/') {
			throw exception("Wrong date format");
		}
		strcpy_s(this->eventDate, newEventDate);
	}

	char* getEventStartTime() {
		return Util::copyString(this->eventStartTime);
	}

	void setEventStartTime(const char* newEventStartTime) {
		if (strlen(newEventStartTime) != 5) {
			throw exception("Wrong time");
		}
		if (newEventStartTime[2] != ':') {
			throw exception("Wrong time format");
		}
		strcpy_s(this->eventStartTime, newEventStartTime);
	}

	char* getEventEndTime() {
		return Util::copyString(this->eventEndTime);
	}

	void setEventEndTime(const char* newEventEndTime) {
		if (strlen(newEventEndTime) != 5) {
			throw exception("Wrong time");
		}
		if (newEventEndTime[2] != ':') {
			throw exception("Wrong time format");
		}
		strcpy_s(this->eventEndTime, newEventEndTime);
	}

	char* getEventDescription() {
		char* copy = Util::copyString(this->eventDescription);
		return copy;
	}

	void setEventDescription(const char* eventDescription) {
		this->eventDescription =  Util::copyString(eventDescription);
	}

	Event(string name, const char* date, const char* eventStartTime,
		const char* eventEndTime, string eventDescription) : eventName(name) {
		this->setEventDate(date);
		this->setEventStartTime(eventStartTime);
		this->setEventEndTime(eventEndTime);
		this->setEventDescription(eventDescription.c_str());
	}




};