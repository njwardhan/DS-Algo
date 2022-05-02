// Did solve in time
// O(N) time and constant space, where N = lenght of the string

class Solution {
public:
    string answer = "0";
    string removeDigit(string number, char digit) {
        int n = number.size();
        string store = number;
        for(int i = 0; i < n; i++)
        {
            if(number[i] == digit)
            {
                string temp = number.erase(i,1);
                if(temp >= answer)
                {
                    answer.clear();
                    answer = temp;
                }
            }
            number = store;
        }
        return answer;
    }
};