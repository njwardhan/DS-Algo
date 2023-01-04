// O(N) time and space solution

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        int answer = 0;

        for(int i = 0; i < tasks.size(); i++)
            m[tasks[i]]++;

        for(auto x : m)
        {
            int temp = x.second/3;

            if(x.second == 1)
                return -1;

            else if(x.second % 3 == 0)
                answer += temp;

            else if(x.second % 3 == 1)
                answer += temp + 1;
            
            else if(x.second % 3 == 2)
                answer += temp - 1 + (x.second - 3 * (temp-1))/2;
        }

        return answer;
    }
};