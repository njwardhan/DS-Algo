// 1. Using multimap --> O(N^2) time and O(N) space - Not the best LC performance though

class Solution {
    int answer = INT_MIN;
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        
        int count;
        multimap<int, int> m;
        for(int i = 0; i < points.size(); i++)
            m.insert(pair<int, int>(points[i][0], points[i][1]));
        
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i+1; j < points.size(); j++)
            {
                count = 0;
                for(auto x : m)
                {
                    if((points[j][1] - points[i][1]) * (x.first - points[i][0]) == (x.second - points[i][1]) * (points[j][0] - points[i][0]))
                        count++;
                }
                if(count >= answer)
                    answer = count;
            }
        }
        return answer;
    }
};

// 2. Using normal hash map --> O(N^2) time and O(N) space - better performance than the above

class Solution {
    int answer = INT_MIN;
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        
        int count;
        map<int, pair<int,int>> m;
        for(int i = 0; i < points.size(); i++)
            m[i] = make_pair(points[i][0], points[i][1]);
        
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i+1; j < points.size(); j++)
            {
                count = 0;
                for(auto x : m)
                {
                    if((points[j][1] - points[i][1]) * (x.second.first - points[i][0]) == (x.second.second - points[i][1]) * (points[j][0] - points[i][0]))
                        count++;
                }
                if(count >= answer)
                    answer = count;
            }
        }
        return answer;
    }
};