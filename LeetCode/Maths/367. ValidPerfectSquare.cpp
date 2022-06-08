// 1. Poor method - O(N) time (N = number being checked) and constant space solution

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        long x = num;
        for(long i = 1; i <= num/2; i++)
        {
            if(i*i == x)
                return true;
        }
        return false;
    }
};

// 2. Binary Search approach - O(logN) time and constant space --> Much better LC performance

class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 1, end = num/2, middle;
        if(num == 1)
            return true;
        
        long x = num;
        
        while(start <= end)
        {
            middle = start + (end-start)/2;
            
            if(middle * middle == x)
                return true;
            else if(middle * middle < x)
                start = middle + 1;
            else
                end = middle - 1;
        }
        return false;
    }
};