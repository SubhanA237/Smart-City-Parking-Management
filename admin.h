#include <iostream>
using namespace std;

class AdminAnalytics
{
private:
    int totalSpaces;
    int occupiedSpaces;
    float totalRevenue;
    int sensorErrors;

public:

    AdminAnalytics()
    {
        totalSpaces = 0;
        occupiedSpaces = 0;
        totalRevenue = 0;
        sensorErrors = 0;
    }

    void setData(int total, int occupied,
                 float revenue, int errors)
    {
        totalSpaces = total;
        occupiedSpaces = occupied;
        totalRevenue = revenue;
        sensorErrors = errors;
    }

    void displayDashboard()
    {
        cout << "\n===== ADMIN ANALYTICS DASHBOARD =====\n";

        cout << "Total Parking Spaces: "
             << totalSpaces << endl;

        cout << "Occupied Spaces: "
             << occupiedSpaces << endl;

        cout << "Available Spaces: "
             << totalSpaces - occupiedSpaces << endl;

        if (totalSpaces > 0)
        {
            cout << "Occupancy Percentage: "
                 << (occupiedSpaces * 100.0 / totalSpaces)
                 << "%" << endl;
        }

        cout << "Total Parking Revenue: Rs. "
             << totalRevenue << endl;

        cout << "Sensor Error Alerts: "
             << sensorErrors << endl;
    }
};


