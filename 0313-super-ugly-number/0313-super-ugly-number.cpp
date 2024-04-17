class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<int> dp(n);
        vector<int> pointer(primes.size(), 0);
        dp[0] = 1;
        
        for(int i = 1; i < n; i++) {
            long long mini = LLONG_MAX; // Initialize with the maximum value of long long
            for(int j = 0; j < primes.size(); j++) {
                long long p = (long long) primes[j] * dp[pointer[j]]; // Cast to long long
                mini = min(mini, p);
            }
            dp[i] = (int) mini; // Convert back to int after finding minimum
            for(int j = 0; j < primes.size(); j++) {
                long long p = (long long) primes[j] * dp[pointer[j]];
                if(mini == p) {
                    pointer[j]++;
                }
            }
        }
        
        return dp[n - 1];
    }
};
