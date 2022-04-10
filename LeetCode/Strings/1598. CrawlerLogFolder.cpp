// O(N) time and constant space, N = size of the input 'logs' array

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        
        for(int i = 0; i < logs.size(); i++)
        {
            if(logs[i] == "./")
                continue;
            else if(logs[i] == "../")
            {
                if(count == 0)
                    continue;
                else
                    count--;
            }
            else
                count++;
        }
        return count;
    }
};