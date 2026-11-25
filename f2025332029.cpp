
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class ParkingTicket {
private:
    string ticketID, plateNumber;
    time_t entryTime, exitTime;
    bool isActive;

public:
    ParkingTicket(string id, string plate) {
        ticketID = id;
        plateNumber = plate;
        entryTime = time(0);
        exitTime = 0;
        isActive = true;
    }

    string getTicketID() {
        return ticketID;
    }

    string getPlateNumber() {
        return plateNumber;
    }

    bool getStatus() {
        return isActive;
    }

    void recordExit() {
        if (isActive) {
            exitTime = time(0);
            isActive = false;
        }
    }

    double getParkingHours() {
        if (isActive)
            return difftime(time(0), entryTime) / 3600.0;
        return difftime(exitTime, entryTime) / 3600.0;
    }

    void displayTicket() {
        cout << "\n------ PARKING TICKET ------\n";
        cout << "Ticket ID: " << ticketID << endl;
        cout << "License Plate: " << plateNumber << endl;
        cout << "Entry Time: " << ctime(&entryTime);
        if (!isActive)
            cout << "Exit Time: " << ctime(&exitTime);
        else
            cout << "Status: Active\n";
        cout << "----------------------------\n";
    }
};

class ParkingGate {
private:
    int gateNumber;
    bool gateStatus;

public:
    ParkingGate(int number) {
        gateNumber = number;
        gateStatus = false;
    }

    void openGate() {
        gateStatus = true;
        cout << "\nGate #" << gateNumber << " is OPEN.\n";
    }

    void closeGate() {
        gateStatus = false;
        cout << "Gate #" << gateNumber << " is CLOSED.\n";
    }
};

int main() {
    string plate, ticketID;
    int choice;
    ParkingGate gate(1);
    ParkingTicket* ticket = nullptr;

    do {
        cout << "\n================================\n";
        cout << "SMART PARKING ENTRY/EXIT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Vehicle Entry\n";
        cout << "2. Vehicle Exit\n";
        cout << "3. View Parking Ticket\n";
        cout << "4. Exit Program\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (ticket != nullptr && ticket->getStatus()) {
                cout << "\nA vehicle is already parked!\n";
                break;
            }

            cout << "\nEnter License Plate Number: ";
            cin >> plate;
            cout << "Enter Ticket ID: ";
            cin >> ticketID;

            delete ticket;
            ticket = new ParkingTicket(ticketID, plate);

            cout << "\nLPR Camera Captured Plate: " << plate << endl;
            cout << "RFID Ticket Generated: " << ticketID << endl;

            gate.openGate();
            gate.closeGate();

            cout << "\nVehicle Entry Successful!\n";
            break;

        case 2:
            if (ticket == nullptr || !ticket->getStatus()) {
                cout << "\nNo active parking ticket found!\n";
                break;
            }

            cout << "\nVehicle Exit Process Started...\n";
            ticket->recordExit();

            gate.openGate();
            gate.closeGate();

            cout << "\nVehicle Exit Successful!\n";
            cout << fixed << setprecision(2);
            cout << "Parking Duration: " << ticket->getParkingHours() << " hours\n";
            break;

        case 3:
            if (ticket == nullptr)
                cout << "\nNo ticket available!\n";
            else
                ticket->displayTicket();
            break;

        case 4:
            cout << "\nThank you for using Smart Parking!\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    delete ticket;
    return 0;
}
