class Solution {
public:
    bool isprime(int n) {
        if(n == 1) return false;  // Comparison should use '=='
        if(n == 2) return true;   // Special case: 2 is prime
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;  // Return false if divisible
        }
        return true;  // Return true if no divisors found
    }

    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primes;  // Use a set to store distinct prime factors

        // For each number in the input array
        for(int num : nums) {
            // Check for prime factors from 2 up to the number itself
            for(int i = 2; i <= num; i++) {
                if(num % i == 0 && isprime(i)) {
                    primes.insert(i);  // Insert the prime factor
                }
            }
        }

        return primes.size();  // Return the number of distinct prime factors
    }
};
