#pragma once

class Location
{
private:
    int maxNumberOfSeats = 0;
    int numberOfRows = 0;
    int seatsPerRow = 0;
    //attribute zone?

public: 
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

    Location(int maxNumberOfSeats, int numberOfRows, int seatsPerRow) :
        maxNumberOfSeats(maxNumberOfSeats), numberOfRows(numberOfRows), seatsPerRow(seatsPerRow) {

    }


    
};


