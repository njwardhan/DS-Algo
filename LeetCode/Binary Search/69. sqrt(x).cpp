// Standard O(logN) time and O(1) space binary search solution
// We can also be asked to find out solution with a higher precision. So that would be done by double for loop Brute Force approach

class Solution {
public:
    long long int mySqrt(int x) {
        int start = 0, end = x;
        long long int middle, answer;
        
        while(start <= end)
        {
            middle = start + (end - start)/2;
            long long int square = middle * middle;
            
            if(square == x)
                return middle;
            else if (square < x)
            {
                start = middle + 1;
                answer = middle;
            }
            else
                end = middle - 1;
        }
        return answer;
    }
};