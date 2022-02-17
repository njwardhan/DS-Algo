// O(N) time and constatn extra space. Little help needed, but overall, great LC feedback!

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j;
        int ansIndex = 0;
        
        while(i < chars.size())
        {
            j = i + 1;
            while(j < chars.size() && chars[j] == chars[i])
                j++;
            
            chars[ansIndex++] = chars[i];
                
            int count = j - i;
            
            if(count > 1)
            {
                string str_count = to_string(count);
                for(char ch : str_count)
                    chars[ansIndex++] = ch;
            }
            i = j;
        }
        return ansIndex;
    }
};