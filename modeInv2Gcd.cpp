#include <iostream>
#define MOD 1000000007

// Function to perform the Extended Euclidean Algorithm
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
long long mod_inverse(long long a, long long mod) {
    long long x, y;
    long long g = extended_gcd(a, mod, x, y);
    if (g != 1) {
        std::cerr << "Inverse doesn't exist"; // Inverse exists only if gcd(a, mod) == 1
        return -1;
    } else {
        return (x % mod + mod) % mod; // Ensure the result is positive
    }
}
