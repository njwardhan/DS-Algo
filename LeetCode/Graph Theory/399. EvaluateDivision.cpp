// Daily Challenge: 30th April 2022 --> Got me the April LC badge!
// Using a return type for the DFS function + its optimum working did the job .. to be revisted still though

class Solution {
public:
    double dfs(string node, map<string, vector<pair<string,double>>>& adj, vector<string> query, double product, map<string, int>& visited)
    {
        for(auto it : adj[node])
        {
            if(it.first == query[1])
                return product * it.second;

            if(!visited[it.first])
            {
                visited[it.first] = 1;
                double temp = dfs(it.first, adj, query, product * it.second, visited);
                if(temp == -1)
                    continue;
                return temp;
            }
        }   
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int V = equations.size();
        
        map<string, vector<pair<string,double>>> adj;
        
        for(int i = 0; i < V; i++)
        {
            adj[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            adj[equations[i][1]].push_back(make_pair(equations[i][0], 1/values[i]));
        }

        vector<double> answer;
        
        for(int i = 0; i < queries.size(); i++)
        {   
            if(queries[i][0] == queries[i][1] and adj.find(queries[i][0]) != adj.end())
                answer.push_back(1.0);
            
            else if(queries[i][0] == queries[i][1] and adj.find(queries[i][0]) == adj.end())
                answer.push_back(-1.0);
            
            else
            {
                map<string, int> visited;
                answer.push_back(dfs(queries[i][0], adj, queries[i], 1.0, visited));
            }
        }
        return answer;
    }
};