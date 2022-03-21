// Daily Challenge: 21st March 2022

// 1. O(N^2) time and constant space, although lesser auxillary space than the solution below!

class Solution {
public:
    vector<int> partitionLabels(string s) {            
        vector<int> answer;
        int i = 0;
        
        while(i <= s.size()-1)
        {
            int temp = s[i];
            int last_pos = i;
            for(int j = i+1; j <= s.size()-1; j++)
            {
                if(s[j] == temp)
                    last_pos = j;
            }
            
            if(last_pos == i)
                answer.push_back(1);
            else
            {
                int k = i+1;
                while(k <= last_pos)
                {
                    int temp2 = s[k];
                    for(int l = k+1; l <= s.size()-1; l++)
                    {
                        if(s[l] == temp2 and l >= last_pos)
                            last_pos = l;
                    }
                    k++;
                }
                answer.push_back(last_pos-i+1);
            }

            i = last_pos+1;
        }
        return answer;
    }
};

// 2. O(N) time and constant space

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_pos(26, 0);
        
        for(int i = 0; i < s.size(); i++)
        {
            last_pos[s[i] - 'a'] = i;
        }
        
        vector<int> answer;
        int end = 0, i = 0;
        
        while(i < s.size())
        {
            end = last_pos[s[i] - 'a'];
            for(int k = i+1; k <= end; k++)
            {
                if(last_pos[s[k] - 'a'] >= end)
                    end = last_pos[s[k] - 'a'];
            }
            answer.push_back(end-i+1);
            i = end+1;
        }
        return answer;
    }
};