#include <iostream>
#include "Rational.h"
using namespace std;

int main() {
    Rational n1, n2(3, 4), n3(2, 3);

    cout << "Addition:" << endl;
    n1 = n2 + n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    cout << "Addition Assignment:" << endl;
    n2 += n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    n2 = Rational(3, 4);  // Reset n2

    cout << "Subtraction:" << endl;
    n1 = n2 - n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    cout << "Subtraction Assignment:" << endl;
    n2 -= n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    n2 = Rational(3, 4);  // Reset n2

    cout << "Multiplication:" << endl;
    n1 = n2 * n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    cout << "Multiplication Assignment:" << endl;
    n2 *= n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    n2 = Rational(3, 4);  // Reset n2

    cout << "Division:" << endl;
    n1 = n2 / n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    cout << "Division Assignment:" << endl;
    n2 /= n3;
    cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << endl;

    cout << "Comparison when NOT equal:" << endl;
    if (n2 == n3)
        cout << "n2 equals n3" << endl;
    else
        cout << "n2 not equal n3" << endl;

    n2 = Rational(2, 3);  // Set n2 equal to n3

    cout << "Comparison when equal:" << endl;
    if (n2 == n3)
        cout << "n2 equals n3" << endl;
    else
        cout << "n2 not equal n3" << endl;

    return 0;
}
