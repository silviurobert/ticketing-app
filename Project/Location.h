#pragma once
#include <iostream>
#include "Util.h"
#include "Displayable.h"

class Location : public Displayable {
private:
    int maxNumberOfSeats = 0;
    int numberOfRows = 0;
    int seatsPerRow = 0;
    const char* locationDescription = nullptr;
    int** availableSeats = nullptr;

public:
    //Ctor without params
    Location() {
    }

    //Ctor without params
    Location(int maxNumberOfSeats, int numberOfRows, int seatsPerRow, const char* locationDescription) :
        maxNumberOfSeats(maxNumberOfSeats), numberOfRows(numberOfRows), seatsPerRow(seatsPerRow) {
        this->setLocationDescription(locationDescription);
        this->setAvailableSeats();
    }

    //copy ctor
    Location(const Location& location) {
        this->maxNumberOfSeats = location.maxNumberOfSeats;
        this->numberOfRows = location.numberOfRows;
        this->seatsPerRow = location.seatsPerRow;
        this->setLocationDescription(location.locationDescription);
        this->setAvailableSeats();
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

    int** getAvailableSeats() {
        return this->availableSeats;
    }

    void setAvailableSeats() {
        //std::cout << this->seatsPerRow << "\n\n\n\n\n\n";
        this->availableSeats = new int*[this->numberOfRows];
        for (int i = 0; i < this->numberOfRows; i++) {
            this->availableSeats[i] = new int[this->seatsPerRow];
        }
        for (int i = 0; i < this->numberOfRows; i++) {
            for (int j = 0; j < this->seatsPerRow; j++) {
                this->availableSeats[i][j] = (i + 1) * 10 + (j + 1);
            }
        }
    }

    bool isSeatAvailable(int row, int seat) {
        std::cout << row << " " << seat << "\n";
        return this->availableSeats[row][seat] != 0;
    }

    void displayAvailableSeats() {
        for (int i = 0; i < this->numberOfRows; i++) {
            for (int j = 0; j < this->seatsPerRow; j++) {
                std::cout << "    " << this->availableSeats[i][j] << "  ";
                
            }
            std::cout << std::endl << std::endl;
        }
    }

    void bookSeat(int row, int seat) {
        this->availableSeats[row - 1][seat - 1] = 0;
    }
    
    void operator=(const Location& source) {
        if (&source == this) {
            return;
        }
        this->maxNumberOfSeats = source.maxNumberOfSeats;
        this->numberOfRows = source.numberOfRows;
        this->seatsPerRow = source.seatsPerRow;
        this->setLocationDescription(source.locationDescription);
        this->setAvailableSeats();
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

    void readLocation() {
        std::cout << std::endl << "Max number of seats: ";
        std::cin >> this->maxNumberOfSeats;

        std::cout << "Number of rows: ";
        std::cin >> this->numberOfRows;

        std::cout << "Seats per row: ";
        std::cin >> this->seatsPerRow;

        std::cout << "Description: ";
        std::string description;
        std::cin >> description;
        this->setLocationDescription(description.c_str());
    }

    void display() override {
        if (this->locationDescription == nullptr) return;
        std::cout << "Location: Description:" << this->locationDescription << ", noSeats:" << this->maxNumberOfSeats <<
            ", noRows:" << this->numberOfRows << ", seatsPerRow:" << this->seatsPerRow << std::endl;
    }
   
    //I tried overloading the >> operator, but it didn't work, so I implemented the readLocation() method instead.
     
    //friend std::istream& operator>> (std::istream& is, Location& location);

    //Destructor
    ~Location() {
        delete[] this->locationDescription;
        for (int i = 0; i < this->numberOfRows; i++) {
            delete[] this->availableSeats[i];
        }
        delete[] this->availableSeats;
    }

};

/*std::istream& operator>> (std::istream& is, Location& location)
{
    std::cout << "Max number of seats: ";
    is >> location.maxNumberOfSeats;

    std::cout << "Number of rows: ";
    is >> location.numberOfRows;

    std::cout << "Seats per row: ";
    is >> location.seatsPerRow;

    std::cout << "Description: ";
    std::string line;
    std::getline(is, line);
    location.locationDescription = line.data();

    return is;
}*/


