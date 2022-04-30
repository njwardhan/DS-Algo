// Daily challenge: 29th April 2022
// O(number of nodes in the graph) time ..

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colour(V, -1);

        for(int i = 0; i < V; i++)
        {
            if(colour[i] != -1)
                continue;
            
            queue <int> q;
            q.push(i);
            colour[i] = 1;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for(int x : graph[u])
                {
                    if(colour[x] == -1)
                    {
                        colour[x] = 1 - colour[u];
                        q.push(x);
                    }
                    else
                    {
                        if(colour[u] == colour[x])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};