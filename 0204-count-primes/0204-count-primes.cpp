class Solution {
public:
    void fillSieve(vector<bool>& sieve) {
        int n = sieve.size() - 1;
        for(int i = 2; i * i <= n; i++) {
            if(sieve[i]) { // Only mark multiples if i is still considered prime
                for(int j = i * i; j <= n; j += i) {
                    sieve[j] = 0;
                }
            }
        }
    }
    
    int countPrimes(int n) { 
        if(n <= 2) return 0;
        int count = 0;
        n = n - 1;
        vector<bool> sieve(n + 1, 1); // 1 means prime, 0 will mean not prime
        fillSieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i = 2; i <= n; i++) {
            if(sieve[i] == 1) {
                count++;
            }
        }
        return count;
    }
};
