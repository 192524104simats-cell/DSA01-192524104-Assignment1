
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;
void warningDemo() {
    int total = 3000000000LL;
    int a = -1;
    unsigned int b = 1;

    cout << total << '\n';
    cout << (a < b) << '\n';
}

int main() {
    int journeys[] = {20000, 500000, 3000000};
    long long farePaise = 1000;

    cout << fixed << setprecision(2);

    for (int n : journeys) {
        long long integerTotal = n * farePaise;
        double doubleTotal = n * 10.0;
        long long expected = integerTotal;

        cout << "\nJourneys: " << n << '\n';
        cout << "Integer-paise total: " << integerTotal << " paise\n";
        cout << "Double total: Rs " << doubleTotal << '\n';
        cout << "Integer total in Rs: Rs " << expected / 100.0 << '\n';

        if (integerTotal <= INT_MAX)
            cout << "Int total: " << integerTotal << '\n';
        else
            cout << "Int total: OVERFLOW risk\n";
    }

    cout << "\nINT_MAX: " << INT_MAX << '\n';
    return 0;
}
