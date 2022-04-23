// 1. O(N^2) time and constant space solution --> not the best LC performance
// Need to revisit this question!

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int modulo = 1000000007;
        long count = 0;
     
        for(int i = 0; i < arr.size(); i++)
        {
            int freq[101] = {0};
            for(int j = i+1; j < arr.size(); j++)
            {
                int k = target - arr[i] - arr[j];
                if(k >= 0 and k <= 100 and freq[k] != 0)
                {
                    count += freq[k];
                    count %= modulo;
                }
                freq[arr[j]]++;
            }
        }
        return (int)count;
    }
};

// 2. 