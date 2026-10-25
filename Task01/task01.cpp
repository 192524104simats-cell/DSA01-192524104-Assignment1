
#include <iostream>
using namespace std;

class SmartCard {
private:
    int balance;

public:
    SmartCard(int b) {
        balance = b;
    }

    void display() {
        cout << "Balance: Rs " << balance << endl;
    }
};

class Journey {
public:
    void display() {
        cout << "Journey records source, destination and fare." << endl;
    }
};

class FareTable {
public:
    int getFare(int zone) {
        if (zone == 1) return 10;
        if (zone == 2) return 20;
        if (zone == 3) return 30;
        return 0;
    }
};

int main() {
    SmartCard card(100);
    Journey journey;
    FareTable fare;

    cout << "City Metro Smart-Card System" << endl;
    card.display();
    journey.display();

    cout << "Outer zone fare: Rs "
         << fare.getFare(3) << endl;

    cout << "Minimum balance after journey: Rs 50" << endl;

    return 0;
}
