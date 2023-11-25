#pragma once
#include "Util.h"

class Location
{
private:
    int maxNumberOfSeats = 0;
    int numberOfRows = 0;
    int seatsPerRow = 0;
    const char* locationDescription = nullptr;

public:
    //Ctor without params
    Location() {
    }

    //Ctor without params
    Location(int maxNumberOfSeats, int numberOfRows, int seatsPerRow, const char* locationDescription) :
        maxNumberOfSeats(maxNumberOfSeats), numberOfRows(numberOfRows), seatsPerRow(seatsPerRow) {
        this->setLocationDescription(locationDescription);
    }

    //copy ctor
    Location(const Location& location) {
        this->maxNumberOfSeats = location.maxNumberOfSeats;
        this->numberOfRows = location.numberOfRows;
        this->seatsPerRow = location.seatsPerRow;
        this->setLocationDescription(location.locationDescription);
    }

    //Getters and Setters
    int getNumberOfSeats() {
        return this->maxNumberOfSeats;
    }

    void setNumberOfSeats(int value) {
        this->maxNumberOfSeats = value;
    }

    int getNumberOfRows() {
        return this->numberOfRows;
    }

    void setNumberOfRows(int value) {
        this->numberOfRows = value;
    }

    int getSeatsPerRow() {
        return this->seatsPerRow;
    }

    void setSeatsPerRow(int value) {
        this->seatsPerRow = value;
    }

    char* getLocationDescription() {
        char* copy = Util::copyString(locationDescription);
        return copy;
    }

    void setLocationDescription(const char* description) {
        this->locationDescription = Util::copyString(description);
    }
    
    void operator=(const Location& source) {
        if (&source == this) {
            return;
        }
        this->maxNumberOfSeats = source.maxNumberOfSeats;
        this->numberOfRows = source.numberOfRows;
        this->seatsPerRow = source.seatsPerRow;
        this->setLocationDescription(source.locationDescription);
    }

    void operator+=(int v) {
        this->maxNumberOfSeats += v;
        this->numberOfRows += v;
        this->seatsPerRow += v;
    }

    void operator++() {
        this->maxNumberOfSeats += 1;
        this->numberOfRows += 1;
        this->seatsPerRow += 1;
    }

    //Destructor
    ~Location() {
        delete[] this->locationDescription;
    }

};


