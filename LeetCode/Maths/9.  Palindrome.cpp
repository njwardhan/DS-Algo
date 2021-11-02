// Constant space and O(number of digits in the number) time

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int check = x, r;
        double sum = 0;
        do
        {     
            r = x % 10;
            sum = sum * 10 + r;
            x = x / 10;
        }
        while(x > 0);
        if (sum == check)
            return true;
        else
            return false;
    }
};