
#include <iostream>
using namespace std;

const int MIN_BALANCE = 5000;

// Procedural version
bool canTravel(long long balance, long long fare) {
    return balance - fare >= MIN_BALANCE;
}

// Object-oriented version
class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) {
        balance = b;
    }

    bool canTravel(long long fare) {
        return balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare) {
        if (canTravel(fare))
            balance -= fare;
    }

    long long getBalance() {
        return balance;
    }
};

int main() {
    long long balance = 10000;
    int fare = 2000;

    cout << "PROCEDURAL VERSION\n";
    if (canTravel(balance, fare)) {
        balance -= fare;
        cout << "Journey allowed\n";
        cout << "Balance: " << balance << " paise\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "\nOBJECT-ORIENTED VERSION\n";
    SmartCard card(10000);

    if (card.canTravel(fare)) {
        card.deduct(fare);
        cout << "Journey allowed\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "Balance: " << card.getBalance() << " paise\n";

    return 0;
}
