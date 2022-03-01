// 1. O(NlogN) time and O(N+1) = O(N) space solution
// Daily Coding challenge of March 1 2022

int BinaryCount(int n)
{
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 1;
    
    int count = 0;
    while(n != 1)
    {
        if(n % 2 != 0)
            count++;
        n /= 2;
    }
    return count+1;
}

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        
        for(int i = 0; i <= n; i++)
        {
            int c = BinaryCount(i);
            answer.push_back(c);
        }
        return answer;
    }
};

// Other specific algorithms can be used to reduce the time complexity ..