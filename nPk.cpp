// Function to calculate n perm k % MOD
long long nPk(int n, int k, long long mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[n - k] % mod;
}
