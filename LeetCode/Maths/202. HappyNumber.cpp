// O(number of digits in the square * number of time it takes to reach a 1 digit number ..)?! time and constant space
// 100% leetcode performance

class Solution {
public:
    int SquareSum(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            int d = n%10;
            sum += d*d;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        while(1)
        {
            int ss = SquareSum(n);
            n = ss;
            if(n == 1 or n == 7 or n == 10)
                return true;
            else if(n < 10)
                return false;
        }
    }
};