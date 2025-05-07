#include <iostream>
#include <cmath>  // For power function
using namespace std;

// Function to calculate compound interest with default arguments
double compoundInterest(double principal, double rate, int time, int n = 1) {
    // Formula for compound interest: A = P(1 + r/n)^(nt)
    // A is the amount, P is the principal, r is the rate, t is the time, n is the number of times the interest is compounded per year
    return principal * pow(1 + rate / (100 * n), n * time) - principal;
}

int main() {
    double principal, rate;
    int time;

    // Input principal, rate, and time
    cout << "Enter principal amount: ";
    cin >> principal;
    cout << "Enter rate of interest (in %): ";
    cin >> rate;
    cout << "Enter time (in years): ";
    cin >> time;

    // Calculate compound interest with default n = 1 (annual compounding)
    double interest = compoundInterest(principal, rate, time);
    cout << "Compound interest (annual compounding): " << interest << endl;

    // Calculate compound interest with custom n (quarterly compounding, for example)
    int n = 4;  // Quarterly compounding
    interest = compoundInterest(principal, rate, time, n);
    cout << "Compound interest (quarterly compounding): " << interest << endl;

    return 0;
}
