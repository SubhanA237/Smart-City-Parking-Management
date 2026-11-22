#include <iostream>
#include "admin.h"
using namespace std;

int main()
{
    AdminAnalytics admin;

    admin.setData(100, 65, 12500, 2);

    admin.displayDashboard();

    return 0;
}
