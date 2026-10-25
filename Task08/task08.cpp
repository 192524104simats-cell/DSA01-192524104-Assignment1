
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int zone;

    cout << "METRO GATE PROGRAM\n";
    cout << "Enter zone (1-Inner, 2-Middle, 3-Outer): ";

    while (!(cin >> zone)) {
        cout << "Invalid input! Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int fare = 0;

    switch (zone) {
        case 1: fare = 1000; break;
        case 2: fare = 2000; break;
        case 3: fare = 3000; break;
        default:
            cout << "Invalid zone!\n";
            return 0;
    }

    cout << "\nJOURNEY REPORT\n";
    cout << "Zone: " << zone << '\n';
    cout << "Fare: Rs " << fixed << setprecision(2)
         << fare / 100.0 << '\n';

    return 0;
}
