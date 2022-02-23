// 1. Recursive solution

long long int TwoPower(int x)
{
    if(x == 0)
        return 1;
    
    return 2 * TwoPower(x-1);
}

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int x = 0; x <= 31; x++)
        {
            if(n == TwoPower(x))
                return true;
        }
        return false;
    }
};

// 2. Better Recursive Approach

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1)
            return true;
        
        if(n == 0 or n % 2 != 0)
            return false;
        
        return isPowerOfTwo(n/2);
    }
};