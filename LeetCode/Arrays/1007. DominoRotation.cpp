// O(N) time and constant space
// Daily Challenge: 20th March 2022

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> count(6, 0);
        
        // Checking for the top array
        int count1;
        for(int i = 0; i < 6; i++)
        {
            count1 = 0;
            int temp = i+1;
            for(int j = 0; j < tops.size(); j++)
            {
                if(tops[j] == temp)
                    continue;
                else if(bottoms[j] == temp)
                {
                    count1++;
                    continue;
                }
                else
                {
                    count[temp-1] = -1;
                    break;
                }
            }
            if(count[temp-1] != -1)
                count[temp-1] = count1;
         }
        
        // Checking for the bottom array
        int count2;
        for(int i = 0; i < 6; i++)
        {
            count2 = 0;
            int temp = i+1;
            for(int j = 0; j < bottoms.size(); j++)
            {
                if(bottoms[j] == temp)
                    continue;
                else if(tops[j] == temp)
                {
                    count2++;
                    continue;
                }
                else
                    break;
            }
            if(count[temp-1] != -1 and count[temp-1] > count2)
                count[temp-1] = count2;
        }
        
        // Returning the minimum value
        int min = INT_MAX;
        for(int i = 0; i < 6; i++)
        {
            if(count[i] < min and count[i] != -1)
                min = count[i];
        }

        if(min == INT_MAX)
            return -1;
        else
            return min;
    }
};