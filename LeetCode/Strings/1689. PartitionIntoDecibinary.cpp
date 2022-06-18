// O(length of the number) time and constant space

class Solution {
public:
    int minPartitions(string n) {
        int max = INT_MIN;
        for(int i = 0; i < n.size(); i++)
        {
            int temp = (int)(n[i] - '0');
            if(temp >= max)
                max = temp;
        }
        return max;
    }
};