// Daily Challenge: 14th May 2022
// Linear space and time approach .. 

class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &graph, int node, vector<int> &weight_store, int temp, vector<bool> &visited)
    {
        visited[node] = 1;
        for(auto it : graph[node])
            if(temp + it.second < weight_store[it.first])
            {
                weight_store[it.first] = temp + it.second;
                dfs(graph, it.first, weight_store, weight_store[it.first], visited);
            }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto it : times)
            graph[it[0]].push_back(make_pair(it[1], it[2]));

        vector<int> weight_store(n + 1, INT_MAX);
        vector<bool> visited(n + 1, 0);
        weight_store[k] = 0;
        dfs(graph, k, weight_store, 0, visited);

        for(int i = 1; i <= n; i++)
            if(!visited[i])
                return -1;

        int answer = 0;
        for(int i = 1; i <= n; i++)
            answer = max(answer, weight_store[i]);

        return answer;
    }
};