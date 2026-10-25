
#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << "DATA TYPES IN METRO SYSTEM\n\n";

    cout << "Size of bool: " << sizeof(bool) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of unsigned: " << sizeof(unsigned) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";

    cout << "\nINT RANGE:\n";
    cout << "Minimum: " << INT_MIN << endl;
    cout << "Maximum: " << INT_MAX << endl;

    cout << "\nMONEY PRECISION:\n";
    double rupees = 0.1 + 0.2;
    cout << "Double result of 0.1 + 0.2: " << rupees << endl;

    long long paise = 10 + 20;
    cout << "Integer paise result: " << paise << " paise\n";

    cout << "\nUse long long paise for accurate money calculations.\n";

    return 0;
}
