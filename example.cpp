int main() {
    int n = 10; // max value of n
    init_factorials(n, MOD);

    int n_val = 5, k_val = 2;

    // Modular Inverse
    long long inverse_of_3 = mod_inverse(3, MOD);
    std::cout << "Inverse of 3: " << inverse_of_3 << "\n";

    // Combinations
    long long comb = nCk(n_val, k_val, MOD);
    std::cout << "C(" << n_val << ", " << k_val << ") = " << comb << "\n";

    // Permutations
    long long perm = nPk(n_val, k_val, MOD);
    std::cout << "P(" << n_val << ", " << k_val << ") = " << perm << "\n";

    return 0;
}
