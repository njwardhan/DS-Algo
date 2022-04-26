// Daily Challenge: 26th April 2022
// No clue about graphs lol, need to study

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int vertices = points.size();
        
        // Building the adjacency list for the points        
        vector<pair<int,int>> adj[vertices + 1];
        
        for(int i = 0; i < points.size(); i++)
        {
            int wt = 0;
            for(int j = i+1; j < points.size(); j++)
            {
                wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        
        // Applying Prim's algorithm on the graph
        int parent[vertices];
        int key[vertices];
        bool mstSet[vertices];
        
        for(int i = 0; i < vertices; i++)
        {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        
        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            if(mstSet[u])
                continue;
            
            mstSet[u] = true;
            
            for(auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;
                if(!mstSet[v] and weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }
        
        int answer = 0;
        
        for(int i = 0; i < vertices; i++)
            answer += key[i];
        
        return answer;
    }
};