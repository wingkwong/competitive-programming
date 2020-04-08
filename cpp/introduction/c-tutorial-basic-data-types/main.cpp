#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int d;
    long ld;
    char c;
    float f;
    double lf;

    cin >> d >> ld >> c >> f >> lf;
    // Int ("%d"): 32 Bit integer
    cout << d << "\n";
    // Long ("%ld"): 64 bit integer
    cout << ld << "\n";
    // Char ("%c"): Character type
    cout << c << "\n";
    // Float ("%f"): 32 bit real value
    cout << f << "\n";
    // Double ("%lf"): 64 bit real value
    cout << lf << "\n";

    return 0;
}
