
#include <iostream>
#include <iomanip>
using namespace std;

class AdminAnalytics
{
private:
    int totalSpots;
    int occupiedSpots;
    double totalRevenue;
    int sensorErrors;

public:

    AdminAnalytics()
    {
        totalSpots = 0;
        occupiedSpots = 0;
        totalRevenue = 0.0;
        sensorErrors = 0;
    }

    void updateParkingData(int total, int occupied)
    {
        if (total >= 0 && occupied >= 0 && occupied <= total)
        {
            totalSpots = total;
            occupiedSpots = occupied;
        }
    }

    void addRevenue(double amount)
    {
        if (amount >= 0)
            totalRevenue += amount;
    }

    void updateSensorErrors(int errors)
    {
        if (errors >= 0)
            sensorErrors = errors;
    }

    int getAvailableSpots() const
    {
        return totalSpots - occupiedSpots;
    }

    double calculateOccupancy() const
    {
        if (totalSpots == 0)
            return 0.0;

        return (static_cast<double>(occupiedSpots) / totalSpots) * 100;
    }

    void displayDashboard() const
    {
        cout << "\nADMIN ANALYTICS DASHBOARD" << endl;

        cout << "Total Parking Spots: " << totalSpots << endl;
        cout << "Occupied Spots: " << occupiedSpots << endl;
        cout << "Available Spots: " << getAvailableSpots() << endl;

        cout << fixed << setprecision(2);

        cout << "Occupancy Percentage: "
             << calculateOccupancy() << "%" << endl;

        cout << "Total Parking Revenue: " << totalRevenue << endl;
        cout << "Sensor Errors: " << sensorErrors << endl;

        if (sensorErrors > 0)
            cout << "Alert: Sensor errors detected!" << endl;
        else
            cout << "All sensors are working properly." << endl;
    }
};

int main()
{
    cout << "SMART CITY PARKING MANAGEMENT SYSTEM" << endl;

    AdminAnalytics admin;

    int total, occupied, errors;
    double revenue;

    cout << "\nEnter total parking spots: ";
    cin >> total;

    cout << "Enter occupied parking spots: ";
    cin >> occupied;

    if (total < 0 || occupied < 0 || occupied > total)
    {
        cout << "Invalid parking information!" << endl;
        return 0;
    }

    cout << "Enter total parking revenue: ";
    cin >> revenue;

    if (revenue < 0)
    {
        cout << "Invalid revenue amount!" << endl;
        return 0;
    }

    cout << "Enter number of sensor errors: ";
    cin >> errors;

    if (errors < 0)
    {
        cout << "Invalid sensor error count!" << endl;
        return 0;
    }

    admin.updateParkingData(total, occupied);
    admin.addRevenue(revenue);
    admin.updateSensorErrors(errors);

    admin.displayDashboard();

    return 0;
}
