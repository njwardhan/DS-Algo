// O(number of digits) time in the worst case and constant space solution
// Faster than 100%

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        int carry = 0;
        
        digits[n] += 1;
        
        while(n >= 0)
        {
            digits[n] += carry;
            
            if(digits[n] == 10)
            {
                digits[n] = 0;
                carry = 1;
            }
            else
            {
                carry = 0;
                break;
            }
            n--;
        }
        if(carry == 1)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};