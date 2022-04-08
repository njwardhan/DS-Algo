// O(number of digits * number of time it takes to reach a single digit number) time .. and constant space !?
// 100% LC performance

class Solution {
public:
    int add(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            int d = n % 10;
            sum += d;
            n /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        
        while(1)
        {
            int njw = add(num);
            num = njw;
            if(num < 10)
                return num;
        }
    }
};