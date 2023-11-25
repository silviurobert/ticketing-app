#pragma once
#include "Util.h"
#include <string>
#include "Location.h"


class Event{
private:
	std::string eventName = "";
	char eventDate[11] = ""; // dd/mm/yyyy
	Location* location;
	char eventStartTime[6] = ""; // hh:mm
	char eventEndTime[6] = ""; // hh:mm
	char* eventDescription = nullptr;	

public:
	//Ctor without params
	Event() {
		this->location = new Location();
	}

	//Ctor with params
	Event(std::string name, const char* date, Location location, const char* eventStartTime,
		const char* eventEndTime, std::string eventDescription) : eventName(name) {
		this->setEventDate(date);
		this->location = new Location(location.getNumberOfSeats(), location.getNumberOfRows(), location.getNumberOfSeats(), 
			location.getLocationDescription());

		this->setEventStartTime(eventStartTime);
		this->setEventEndTime(eventEndTime);
		this->setEventDescription(eventDescription.c_str());
	}

	//copy ctor
	Event(const Event& event) {
		this->eventName = event.eventName;
		this->setEventDate(event.eventDate);
		this->setLocation(event.location);
		this->setEventStartTime(event.eventStartTime);
		this->setEventEndTime(event.eventEndTime);
		this->setEventDescription(event.eventDescription);
	}

	//Getters and Setters
	std::string getEventName() {
		return this->eventName;
	}
	
	char* getEventDate() {
		return Util::copyString(this->eventDate);
	}

	void setEventDate(const char* newEventDate) {
		if (strlen(newEventDate) != 10) {
			throw std::exception("Wrong date");
		}
		if (newEventDate[2] != '/' || newEventDate[5] != '/') {
			throw std::exception("Wrong date format");
		}
		strcpy_s(this->eventDate, newEventDate);
	}

	Location* getLocation() {
		return this->location;
	}

	void setLocation(Location* location) {
		this->location = location;
	}

	char* getEventStartTime() {
		return Util::copyString(this->eventStartTime);
	}

	void setEventStartTime(const char* newEventStartTime) {
		if (strlen(newEventStartTime) != 5) {
			throw std::exception("Wrong time");
		}
		if (newEventStartTime[2] != ':') {
			throw std::exception("Wrong time format");
		}
		strcpy_s(this->eventStartTime, newEventStartTime);
	}

	char* getEventEndTime() {
		return Util::copyString(this->eventEndTime);
	}

	void setEventEndTime(const char* newEventEndTime) {
		if (strlen(newEventEndTime) != 5) {
			throw std::exception("Wrong time");
		}
		if (newEventEndTime[2] != ':') {
			throw std::exception("Wrong time format");
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

	/*std::string eventName = "";
	char eventDate[11] = ""; // dd/mm/yyyy
	char eventStartTime[6] = ""; // hh:mm
	char eventEndTime[6] = ""; // hh:mm
	char* eventDescription = nullptr;*/

	void operator=(const Event& source) {
		if (&source == this) {
			return;
		}
		this->eventName = source.eventName;
		this->setEventDate(source.eventDate);
		this->setEventStartTime(source.eventStartTime);
		this->setEventEndTime(source.eventEndTime);
		this->setEventDescription(source.eventDescription);
	}

	//Destructor
	~Event() {
		delete[] this->eventDescription;
	}

	//char eventStartTime[6] = ""; // hh:mm
	//aici fac int& operator[](int index){
	//if(index < 0 || )
};