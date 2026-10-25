
#include <iostream>
#include <limits>
using namespace std;

enum class Zone { Inner = 1, Middle, Outer };

long long fare(int zone, int hour) {
    long long base;

    switch (zone) {
        case 1: base = 1000; break;
        case 2: base = 2000; break;
        case 3: base = 3000; break;
        default: return -1;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        base += base * 20 / 100;

    return base;
}
void testFiveJourneys() {
    int zones[] = {1, 2, 3, 1, 2};
    int hours[] = {10, 8, 12, 18, 20};
    long long total = 0;

    for (int i = 0; i < 5; i++) {
        long long f = fare(zones[i], hours[i]);
        total += f;
        cout << "Journey " << i + 1
             << ": " << f << " paise\n";
    }

    cout << "Total fare: " << total << " paise\n";
}

int main() {
    int zone, hour;
    long long balance;

    cout << "Enter zone (1-Inner, 2-Middle, 3-Outer): ";
    if (!(cin >> zone)) {
        cout << "Invalid zone input\n";
        return 0;
    }

    cout << "Enter hour (0-23): ";
    if (!(cin >> hour)) {
        cout << "Invalid hour input\n";
        return 0;
    }

    cout << "Enter balance in paise: ";
    if (!(cin >> balance)) {
        cout << "Invalid balance input\n";
        return 0;
    }

    if (hour < 0 || hour > 23) {
        cout << "Invalid hour\n";
        return 0;
    }

    if (balance < 0) {
        cout << "Invalid balance\n";
        return 0;
    }

    long long f = fare(zone, hour);

    if (f < 0) {
        cout << "Invalid zone\n";
    } else if (balance - f >= 5000) {
        cout << "Fare: " << f << " paise\n";
        cout << "Remaining balance: " << balance - f << " paise\n";
    } else {
        cout << "Journey denied: minimum Rs 50 must remain\n";
    }
testFiveJourneys();
    return 0;
}
