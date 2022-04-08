// O(constant * length of string) time !? and constant space approach

class Solution {
public:
    int sumReturn(string n)
    {
        int sum = 0;
        
        for(int i = 0; i < n.size(); i++)
            sum += (n[i] - '0');
            
        return sum;
    }
    
    int getLucky(string s, int k) {
        string number;
        
        for(int i = 0; i < s.size(); i++)
            number += to_string(s[i]-96);
        
        int count = 0;
        int answer;
        while(1)
        {
            answer = sumReturn(number);
            number = to_string(answer);
            count++;
            if(count == k)
                break;
        }
        
        return answer;
    }
};