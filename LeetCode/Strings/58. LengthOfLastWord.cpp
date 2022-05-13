// O(N) time (in worst case) and constant space

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length()-1;
        
        while(i >= 0)
        {
            if(isspace(s[i]))
            {
                i--;
                continue;
            }
            else
            {
                while(!isspace(s[i]))
                {
                    count++;
                    if(i == 0)
                        break;
                    i--;
                }
                break;
            }
        }
        return count;
    }
};