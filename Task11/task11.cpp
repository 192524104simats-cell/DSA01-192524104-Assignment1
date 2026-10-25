
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_SURCHARGE = 20;

enum class Zone { Inner = 1, Middle, Outer };

class SmartCard {
    long long balance;

public:
    SmartCard(long long amount) : balance(amount) {}

    long long getBalance() const {
        return balance;
    }

    bool travel(Zone zone, int hour) {
        long long fare;

        switch (zone) {
            case Zone::Inner: fare = 1000; break;
            case Zone::Middle: fare = 2000; break;
            case Zone::Outer: fare = 3000; break;
            default: return false;
        }

        if ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20))
            fare += fare * PEAK_SURCHARGE / 100;

        if (hour < 0 || hour > 23 ||
            balance - fare < MIN_BALANCE)
            return false;

        balance -= fare;
        cout << "Fare: " << fare << " paise\n";
        cout << "Balance: " << balance << " paise\n";
        return true;
    }
};

int main() {
    SmartCard card(10000);

    cout << "Initial balance: " << card.getBalance()
         << " paise\n";

    if (!card.travel(Zone::Outer, 18))
        cout << "Journey denied\n";

    return 0;
}
