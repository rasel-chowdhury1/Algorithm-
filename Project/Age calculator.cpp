#include <bits/stdc++.h>

using namespace std;

int main()
{

    time_t now = time(0);

    tm *current_time = localtime(&now);  // Convert current time to tm struct

    int birth_year;
    cout << "Enter birth year: ";
    cin >> birth_year;

    int birth_month;
    cout << "Enter birth month: ";
    cin >> birth_month;

    int birth_day;
    cout << "Enter birth day: ";
    cin >> birth_day;
 
    tm birthday = {0, 0, 0, birth_day, birth_month - 1, birth_year - 1900}; // Convert birth year, month, and day to tm struct

    double seconds = difftime(now, mktime(&birthday)); // Calculate difference between current time and birth time
    double years = seconds / 31557600; // 31557600 seconds in a year

    cout << "Your age is " << years << " years." << endl;

    return 0;
}
