#include <stdio.h>
#include <gmp.h>

// Fast Doubling Method to find the nth Fibonacci number
// F(2n)   = F(n) * [2*F(n+1) - F(n)]
// F(2n+1) = F(n)^2 + F(n+1)^2
void fibonacci_fast_doubling(long unsigned int n, mpz_t f_n) {
    mpz_t a, b, c, d;
    mpz_inits(a, b, c, d, NULL);

    mpz_set_ui(a, 0); // F(0)
    mpz_set_ui(b, 1); // F(1)

    // Find the highest bit position
    long unsigned int mask = 1UL << (sizeof(long unsigned int) * 8 - 1);
    while (mask > 0 && (n & mask) == 0) {
        mask >>= 1;
    }

    // Process bits from MSB to LSB
    while (mask > 0) {
        // c = a * (2*b - a) -> F(2k)
        mpz_mul_ui(c, b, 2);
        mpz_sub(c, c, a);
        mpz_mul(c, c, a);

        // d = a^2 + b^2     -> F(2k+1)
        mpz_mul(a, a, a);
        mpz_mul(b, b, b);
        mpz_add(d, a, b);

        if (n & mask) {
            mpz_set(a, d);     // F(2k+1)
            mpz_add(b, c, d);  // F(2k+2)
        } else {
            mpz_set(a, c);     // F(2k)
            mpz_set(b, d);     // F(2k+1)
        }
        mask >>= 1;
    }

    mpz_set(f_n, a);
    mpz_clears(a, b, c, d, NULL);
}

int main() {
    long unsigned int n = 1000000;
    mpz_t result;
    mpz_init(result);

    fprintf(stdout, "Computing F(%lu)...\n", n);
    fibonacci_fast_doubling(n, result);

    // Get the total number of digits in base 10
    size_t digits = mpz_sizeinbase(result, 10);
    fprintf(stdout, "Successfully computed! Total digits: %zu\n", digits);

    // Optional: Write the massive number to a text file
    FILE *fib_file_out = fopen("fib_1000000.txt", "w");
    if (fib_file_out != NULL) {
        mpz_out_str(fib_file_out, 10, result);
        fclose(fib_file_out);
        fprintf(stdout, "The full number has been saved to 'fib_1000000.txt'\n");
    }

    mpz_clear(result);
    return 0;
}