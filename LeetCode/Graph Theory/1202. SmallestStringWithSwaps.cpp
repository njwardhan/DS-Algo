// Daily Challenge: 27th April 2022
// Again, just solved somehow. Graph theory knowledge needed!!

class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& componentDfs, string& s, string& st)
    {
        componentDfs.push_back(node);
        st += s[node];
        visited[node] = 1;
        for(int i = 0; i < adj[node].size(); i++)
        {
            if(!visited[adj[node][i]])
                dfs(adj[node][i], visited, adj, componentDfs, s, st);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int V = pairs.size();
        
        // Build the graph as a vector of vectors
        vector<vector<int>> adj(s.size());
        
        for(int i = 0; i < V; i++)
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }
    
        vector<int> visited(adj.size(),0);
        
        // Perform DFS on the graph and go on updating the original string on the basis of the traversal ..
        for(int i = 0; i < adj.size(); i++)
        {
            if(!visited[i])
            {
                vector<int> componentDfs;
                string st = ""; 
                dfs(i, visited, adj, componentDfs, s, st);
            
                sort(componentDfs.begin(), componentDfs.end());
                sort(st.begin(), st.end());
            
                for(int j = 0; j < st.size(); j++)
                    s[componentDfs[j]] = st[j];
            }        
        }   
        return s;
    }
};