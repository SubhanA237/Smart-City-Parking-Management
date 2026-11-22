#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ParkingSpot
{
private:
int spotID;
string spotType;
bool isOccupied;
public:
ParkingSpot(int id, string type)
{
spotID = id;
spotType = type;
isOccupied = false;
}
int getSpotID() const
{
return spotID;
}

string getSpotType() const
{
return spotType;
}
bool getOccupancy() const
{
return isOccupied;
}
bool occupy()
{
if (isOccupied == false)
{
isOccupied = true;
return true;
}
return false;
}
bool release()
{
if (isOccupied == true)
{
isOccupied = false;
return true;
}
return false;
}
void displaySpot() const
{
cout << "Spot ID: " << spotID << endl;
cout << "Spot Type: " << spotType << endl;
if (isOccupied)
cout << "Status: Occupied" << endl;
else
cout << "Status: Available" << endl;
}
};
// CLASS 2: ParkingFloor
class ParkingFloor
{
private:
int floorNumber;
vector<ParkingSpot> spots;
public:
ParkingFloor(int number)
{
floorNumber = number;
}
int getFloorNumber() const
{
return floorNumber;
}
void addSpot(ParkingSpot spot)
{
spots.push_back(spot);
}
int assignSpot(string type)
{
for (int i = 0; i < (int)spots.size(); i++)
{
if (spots[i].getSpotType() == type &&
spots[i].getOccupancy() == false)
{
spots[i].occupy();
return spots[i].getSpotID();
}
}
return -1;
}
bool releaseSpot(int id)
{
for (int i = 0; i < (int)spots.size(); i++)
{
if (spots[i].getSpotID() == id)
{
return spots[i].release();
}
}
return false;
}
int getTotalSpots() const
{
return (int)spots.size();
}
int getOccupiedSpots() const
{
int count = 0;
for (int i = 0; i < (int)spots.size(); i++)
{
if (spots[i].getOccupancy())
count++;
}
return count;
}
void displayFloor() const
{
cout << "\n========== FLOOR "
<< floorNumber << " ==========" << endl;
for (int i = 0; i < (int)spots.size(); i++)
{
spots[i].displaySpot();
cout << "--------------------" << endl;
}
}
};
// CLASS 3: ParkingGarage
class ParkingGarage
{
private:
vector<ParkingFloor> floors;
public:
void addFloor(int floorNumber)
{
floors.push_back(ParkingFloor(floorNumber));
}
bool addSpot(int floorNumber, ParkingSpot spot)
{
for (int i = 0; i < (int)floors.size(); i++)
{
if (floors[i].getFloorNumber() == floorNumber)
{
floors[i].addSpot(spot);
return true;
}
}
return false;
}
int assignSpot(int floorNumber, string type)
{
for (int i = 0; i < (int)floors.size(); i++)
{
if (floors[i].getFloorNumber() == floorNumber)
{
return floors[i].assignSpot(type);
}
}
return -1;
}
bool releaseSpot(int floorNumber, int spotID)
{
for (int i = 0; i < (int)floors.size(); i++)
{
if (floors[i].getFloorNumber() == floorNumber)
{
return floors[i].releaseSpot(spotID);
}
}
return false;
}
int getTotalSpots() const
{int total = 0;
for (int i = 0; i < (int)floors.size(); i++)
{
total += floors[i].getTotalSpots();
}
return total;
}
int getOccupiedSpots() const
{
int occupied = 0;
for (int i = 0; i < (int)floors.size(); i++)
{
occupied += floors[i].getOccupiedSpots();
}
return occupied;
}
void displayGarage() const
{
cout << "\n========== PARKING GARAGE ==========" << endl;
for (int i = 0; i < (int)floors.size(); i++)
{
floors[i].displayFloor();
}
cout << "\nTotal Parking Spots: "
<< getTotalSpots() << endl;
cout << "Occupied Spots: "
<< getOccupiedSpots() << endl;
cout << "Available Spots: "
<< getTotalSpots() - getOccupiedSpots()
<< endl;
}
};
// CLASS 4: ParkingSensor
class ParkingSensor
{
private:
int sensorID;
bool sensorWorking;
bool vehicleDetected;
public:
ParkingSensor(int id)
{
sensorID = id;
sensorWorking = true;
vehicleDetected = false;
}
void detectVehicle(bool detected)
{
if (sensorWorking)
{
vehicleDetected = detected;
}
}
void setSensorStatus(bool status)
{
sensorWorking = status;
if (sensorWorking == false)
{
vehicleDetected = false;
}
}
void displaySensor() const
{
cout << "\n========== SENSOR INFORMATION ==========" << endl;
cout << "Sensor ID: " << sensorID << endl;
if (sensorWorking)
cout << "Sensor Status: Working" << endl;
else
cout << "Sensor Status: Not Working" << endl;
if (vehicleDetected)
cout << "Vehicle Detected: Yes" << endl;
else
cout << "Vehicle Detected: No" << endl;
}
};

int main()
{
cout << "====================================" << endl;
cout << " SMART CITY PARKING MANAGEMENT SYSTEM" << endl;
cout << "====================================" << endl;
ParkingGarage garage;
garage.addFloor(1);
garage.addFloor(2);
garage.addSpot(1, ParkingSpot(101, "Car"));
garage.addSpot(1, ParkingSpot(102, "Car"));
garage.addSpot(1, ParkingSpot(103, "SUV"));
garage.addSpot(1, ParkingSpot(104, "Motorcycle"));
garage.addSpot(2, ParkingSpot(201, "Car"));
garage.addSpot(2, ParkingSpot(202, "Car"));
garage.addSpot(2, ParkingSpot(203, "SUV"));
garage.addSpot(2, ParkingSpot(204, "Motorcycle"));
vector<int> vehicleFloors;
vector<int> vehicleSpots;
vector<bool> vehicleParked;
int numberOfVehicles;
cout << "\nTotal Parking Spaces: 8" << endl;
cout << "Enter number of vehicles: ";
cin >> numberOfVehicles;
if (numberOfVehicles < 1 || numberOfVehicles > 8)
{
cout << "Please enter a number between 1 and 8!" << endl;
return 0;
}
for (int i = 0; i < numberOfVehicles; i++)
{
int floor;
string type;
cout << "\n--- Vehicle " << i + 1 << " ---" << endl;
cout << "Enter floor number (1 or 2): ";
cin >> floor;
if (floor != 1 && floor != 2)
{
cout << "Invalid floor number!" << endl;
continue;
}
cout << "Enter vehicle type (Car/SUV/Motorcycle): ";
cin >> type;
int spot = garage.assignSpot(floor, type);
if (spot != -1)
{
cout << "Parking assigned successfully!" << endl;
cout << "Your Parking Spot ID: " << spot << endl;
vehicleFloors.push_back(floor);
vehicleSpots.push_back(spot);
vehicleParked.push_back(true);
}
else
{
cout << "No suitable parking spot available!" << endl;
}
}
cout << "\n--- GARAGE STATUS AFTER ENTRY ---" << endl;
garage.displayGarage();
ParkingSensor sensor1(501);
sensor1.detectVehicle(garage.getOccupiedSpots() > 0);
sensor1.displaySensor();
int choice;
do
{
cout << "\n--- VEHICLE EXIT ---" << endl;
cout << "Enter vehicle number to exit (1 to "
<< vehicleParked.size()
<< "), or 0 to finish: ";
cin >> choice;
if (choice == 0)
{
break;
}
if (choice < 1 || choice > (int)vehicleParked.size())
{
cout << "Invalid vehicle number!" << endl;
}
else if (vehicleParked[choice - 1] == false)
{
cout << "This vehicle has already exited!" << endl;
}
else
{
int index = choice - 1;
if (garage.releaseSpot(
vehicleFloors[index],
vehicleSpots[index]))
{
cout << "Vehicle exited successfully!" << endl;
vehicleParked[index] = false;
}
}
sensor1.detectVehicle(garage.getOccupiedSpots() > 0);
} while (choice != 0);
cout << "\n--- FINAL GARAGE STATUS ---" << endl;
garage.displayGarage();
sensor1.displaySensor();
return 0;
}
