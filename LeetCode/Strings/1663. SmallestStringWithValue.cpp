// O(N) time and space solution
// Daily Challenge: 22nd March 2022

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n,'a');
        int sum = n;
        
        while (true) 
        {
            if (k - sum < 26) 
            {
                s[n-1] = 'a' + (k - sum);
                break;
            }
            else 
            {
                s[n-1] = 'z';
                n--;
                sum += 25;
            }
        }
        return s;
    }
};