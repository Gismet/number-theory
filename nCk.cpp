// Function to calculate n choose k % MOD
long long nCk(int n, int k, long long mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
