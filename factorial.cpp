#include <vector>
#define MAXN 1000000 // Set according to the maximum n you expect
std::vector<long long> fact(MAXN + 1), inv_fact(MAXN + 1);

// Precompute factorials and modular inverses of factorials
void init_factorials(int n, long long mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[n] = mod_inverse(fact[n], mod);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}
