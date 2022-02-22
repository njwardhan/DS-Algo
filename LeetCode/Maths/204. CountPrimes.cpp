// Sieve of Erastosthenes algorithm
// Total number of elements = n. First we check for multiples of 2, which makes it n/2, then for 3 that is n/3 and so on with other primes
// So the comparison scene comes out to be like: n/2 + n/3 + n/5 + n/7 + n/11 ...
// n(1/2+1/3+1/5+1/7+1/11+..) which is a Harmonic Progression of primes and converges to log(logN) via Taylor's Series
// Hence, time complexity = O(N*log(logN)) along with space complexity of O(N)

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> primes(n+1, true);
        
        primes[0] = primes[1] = false;
        
        for(int i = 2; i < n; i++)
        {
            if(primes[i])
            {
                count++;
                for(int j = 2*i; j < n; j+=i)
                    primes[j] = false;
            }
        }
        return count;
    }
};

// However, the Sieve of Erastosthenes method is not very suitable for very large value of N. That way we might run into "Memory Limited Exceeded" thing.
// To avoid that, we use the "Segmented Sieve" approach where we check for prime in ranges of size root(N) only. So this way, the extra 
// auxillar space comes out to be O(root(N)) only instead of the O(N) in normal cases .. 
// https://www.geeksforgeeks.org/segmented-sieve/