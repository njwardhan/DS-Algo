// Problem Link: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// Binary Search solution with O(NlogN) time and constant space complexities

bool isPossibleSol(vector<int> &stalls, int k, int middle)
{
    int cows = 1;
    int last_position = stalls[0];
    for(int i = 0; i < stalls.size(); i++)
    {
        if(abs(stalls[i] - last_position) >= middle)
        {
            cows++;
			if(cows == k)
	            return true;        
            last_position = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int max = -1; 
    for(int i = 1; i <= stalls.size()-1; i++)
    {
        if(stalls[i] >= max)
            max = stalls[i];
    }
    int start = 0, middle;
    int answer = -1;
    int end = max;
    
    while(start <= end)
    {
        middle = start + (end-start)/2;
        if(isPossibleSol(stalls, k, middle))
        {
            answer = middle;
            start = middle + 1;
        }
        else
            end = middle - 1;
    }
    return answer;
}