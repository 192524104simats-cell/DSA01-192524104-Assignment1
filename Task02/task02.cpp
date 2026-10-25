#include <iostream>
using namespace std;

int main() {
    constexpr int INNER_FARE = 10;
    constexpr int MIDDLE_FARE = 20;
    constexpr int OUTER_FARE = 30;

    int zone;
    cout << "Enter zone (1-Inner, 2-Middle, 3-Outer): ";
    cin >> zone;

    switch (zone) {
        case 1: cout << "Fare: Rs " << INNER_FARE; break;
        case 2: cout << "Fare: Rs " << MIDDLE_FARE; break;
        case 3: cout << "Fare: Rs " << OUTER_FARE; break;
        default: cout << "Invalid zone";
    }

    cout << endl;
    return 0;
}