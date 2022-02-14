// O(N + NlogN) = O(NlogN) time (hopefully) and constant space solution
// Standard Binary Search Approach with some tweaks

bool isPossibleSol(vector<int>& weights, int days, int middle)
{
    int i = 0, allotment = 0, m = 1;
    while(i <= weights.size()-1)
    {
        if(allotment + weights[i] <= middle)
        {
            allotment += weights[i];
            i++;
            continue;
        }
        allotment = 0;
        m++;
        
        if(m > days)
            return false;
    }
    return true;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0, sum = 0;
        
        for(int i = 0; i <= weights.size()-1; i++)
            sum += weights[i];
        
        int end = sum;
        int answer = -1;
        int middle;
        
        while(start <= end)
        {
            middle = start + (end-start)/2;
            
            if(isPossibleSol(weights, days, middle))
            {
                answer = middle;
                end = middle - 1;
            }
            else
                start = middle + 1;   
        }
        return answer;
    }
};