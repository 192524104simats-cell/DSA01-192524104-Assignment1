
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_SURCHARGE = 20;
constexpr int WEEKEND_DISCOUNT = 10;

enum class Zone { Inner = 1, Middle, Outer, Airport };

const long long fares[] = {0, 1000, 2000, 3000, 6000};

class MonthlyPass {
    Zone zone1, zone2;

public:
    MonthlyPass(Zone a, Zone b) : zone1(a), zone2(b) {}

    bool covers(Zone z) const {
        return z == zone1 || z == zone2;
    }
};

class SmartCard {
    long long balance;

public:
    SmartCard(long long amount) : balance(amount) {}

    void travel(Zone zone, int hour, bool weekend,
                const MonthlyPass* pass = nullptr) {
        if (hour < 0 || hour > 23) {
            cout << "Invalid hour\n";
            return;
        }

        int z = static_cast<int>(zone);

        if (z < 1 || z > 4) {
            cout << "Invalid zone\n";
            return;
        }

        if (pass != nullptr && pass->covers(zone)) {
            cout << "Monthly pass: Free journey\n";
            cout << "Balance: " << balance << " paise\n";
            return;
        }

        long long fare = fares[z];

        if (weekend) {
            fare -= fare * WEEKEND_DISCOUNT / 100;
        } else if ((hour >= 8 && hour < 10) ||
                   (hour >= 17 && hour < 20)) {
            fare += fare * PEAK_SURCHARGE / 100;
        }

        if (balance - fare < MIN_BALANCE) {
            cout << "Journey denied: minimum Rs 50 must remain\n";
            return;
        }

        balance -= fare;
        cout << "Fare: " << fare << " paise\n";
        cout << "Balance: " << balance << " paise\n";
    }
};

int main() {
    SmartCard card(20000);
    MonthlyPass pass(Zone::Inner, Zone::Airport);

    cout << "1. Airport weekday peak:\n";
    card.travel(Zone::Airport, 18, false);

    cout << "\n2. Airport weekend:\n";
    card.travel(Zone::Airport, 18, true);

    cout << "\n3. Inner zone with monthly pass:\n";
    card.travel(Zone::Inner, 9, false, &pass);

    cout << "\n4. Middle zone during peak:\n";
    card.travel(Zone::Middle, 8, false);

    return 0;
}
