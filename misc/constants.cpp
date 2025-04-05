#include <iostream>
#include <climits> 
#include <cfloat>  // Needed for floating-point limits
#include <cmath>   // Needed for constants like M_PI and M_E

using namespace std;

int main() {
    // Integer types
    cout << "Max int: " << INT_MAX << endl;
    cout << "Min int: " << INT_MIN << endl;

    cout << "Max long: " << LONG_MAX << endl;
    cout << "Min long: " << LONG_MIN << endl;

    cout << "Max long long: " << LLONG_MAX << endl;
    cout << "Min long long: " << LLONG_MIN << endl;

    // Floating point types
    cout << "Max float: " << FLT_MAX << endl;
    cout << "Min negative float: " << -FLT_MAX << endl;
    cout << "Smallest positive float: " << FLT_MIN << endl;

    cout << "Max double: " << DBL_MAX << endl;
    cout << "Min negative double: " << -DBL_MAX << endl;
    cout << "Smallest positive double: " << DBL_MIN << endl;

    cout << "Max long double: " << LDBL_MAX << endl;
    cout << "Min negative long double: " << -LDBL_MAX << endl;
    cout << "Smallest positive long double: " << LDBL_MIN << endl;

    // constants
    // specify pi
    cout << "Pi: " << M_PI << endl;
    // specify e
    cout << "e: " << M_E << endl;
    // specify inf
    cout << "inf: " << INFINITY << endl;
    // specify -ve inf
    cout << "-inf: " << -INFINITY << endl;


    // specify nan
    cout << "nan: " << NAN << endl;
    // specify -ve nan
    cout << "-nan: " << -NAN << endl;
    return 0;
}
