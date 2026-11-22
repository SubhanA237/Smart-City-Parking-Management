#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class TariffSchedule
{
private:
string vehicleCategory;
double hourlyRate;
double peakMultiplier;
public:
TariffSchedule(string category, double rate, double peakMult = 1.0)
: vehicleCategory(category),
 hourlyRate(rate >= 0.0 ? rate : 0.0),
peakMultiplier(peakMult >= 1.0 ? peakMult : 1.0)
{
}
string getVehicleCategory() const
{
return vehicleCategory;
}
double getHourlyRate() const
{
 return hourlyRate;
}
double getPeakMultiplier() const
{
return peakMultiplier;
}
void setHourlyRate(double rate)
{
if (rate >= 0.0)
{
hourlyRate = rate;
}
}
void setPeakMultiplier(double mult)
{
if (mult >= 1.0)
{
peakMultiplier = mult;
}
}
};
class ParkingBill
{
private:
    string ticketId;
    string vehiclePlate;
    string vehicleCategory;
    double durationHours;
    double totalPayable;
    bool isPaid;
public:
    ParkingBill(string tId, string plate, string category, double hours, double amount)
        : ticketId(tId),
          vehiclePlate(plate),
          vehicleCategory(category),
          durationHours(hours > 0.0 ? hours : 0.0),
          totalPayable(amount >= 0.0 ? amount : 0.0),
          isPaid(false)
{
}
string getTicketId() const
{
        return ticketId;
}
double getTotalPayable() const
{
return totalPayable;
}
bool getPaidStatus() const
{
return isPaid;
}
void markPaid()
    {
        isPaid = true;
    }

    void displayBill() const
    {
        cout << fixed << setprecision(2);
        cout << "----------------------------------------\n";
        cout << "Ticket ID        : " << ticketId << "\n";
        cout << "Vehicle Plate    : " << vehiclePlate << "\n";
        cout << "Category         : " << vehicleCategory << "\n";
        cout << "Duration (Hours) : " << durationHours << "\n";
        cout << "Total Payable    : $" << totalPayable << "\n";
        cout << "Payment Status   : " << (isPaid ? "PAID" : "UNPAID") << "\n";
        cout << "----------------------------------------\n";
}
};
class TariffPaymentEngine
{
private:
    string engineName;
    double totalRevenueCollected;
public:
    TariffPaymentEngine(string name = "Tariff & Payment Engine")
        : engineName(name), totalRevenueCollected(0.0)
{
}
ParkingBill generateBill(const string& ticketId,
    const string& vehiclePlate,
    const TariffSchedule& schedule,
    int totalMinutes,
    bool peakHour = false)
{
    if (totalMinutes < 0)
{
    totalMinutes = 0;
}
double hours = totalMinutes / 60.0;
double activeRate = schedule.getHourlyRate() * (peakHour ? schedule.getPeakMultiplier() : 1.0);
double amount = hours * activeRate;
return ParkingBill(ticketId, vehiclePlate, schedule.getVehicleCategory(), hours, amount);
}
bool collectPayment(ParkingBill& bill, double amountPaid)
{
if (bill.getPaidStatus())
{
cout << "Bill " << bill.getTicketId() << " is already paid.\n";
return true;
}
if (amountPaid >= bill.getTotalPayable())
{
bill.markPaid();
totalRevenueCollected += bill.getTotalPayable();
double change = amountPaid - bill.getTotalPayable();
cout << fixed << setprecision(2);
cout << "Payment accepted for " << bill.getTicketId()
<< ". Change: $" << change << "\n";
return true;
}
cout << "Insufficient payment for " << bill.getTicketId() << ".\n";
return false;
}
double getTotalRevenueCollected() const
{
return totalRevenueCollected;
}
};
int main()
{
TariffSchedule carTariff("Car", 5.00, 1.25);
TariffSchedule motorcycleTariff("Motorcycle", 3.00, 1.15);
TariffPaymentEngine engine("Smart City Tariff & Payment Engine");
ParkingBill bill1 = engine.generateBill("TK-4821", "ABC-8920", carTariff, 195, false);
bill1.displayBill();
engine.collectPayment(bill1, 20.00);
ParkingBill bill2 = engine.generateBill("TK-4822", "LHR-512", motorcycleTariff, 120, true);
bill2.displayBill();
engine.collectPayment(bill2, 10.00);
cout << "\nTotal Revenue Collected: $" << fixed << setprecision(2)
<< engine.getTotalRevenueCollected() << "\n";
return 0;
}
