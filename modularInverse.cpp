#include <iostream>
#define MOD 1000000007

// Function to compute a^b % MOD
long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

// Function to compute modular inverse of a % MOD
long long mod_inverse(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}
