// ..

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int id, map<int, vector<int>>& adj, int& answer, map<int,int>& imp)
    {
        if(id == 0)
            return;
        
        answer += imp[id];
        for(auto it : adj[id])
            dfs(it, adj, answer, imp);
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int V = employees.size();
        map<int,int> imp;
        
        for(int i = 0; i < V; i++)
            imp[employees[i]->id] = employees[i]->importance;
        
        map<int, vector<int>> adj;
            
        for(int i = 0; i < V; i++)
        {
            vector<int> subordinate = employees[i]->subordinates;
            if(subordinate.empty())
            {
                adj[employees[i]->id].push_back(0);
                continue;
            }
            for(auto it : subordinate)
                adj[employees[i]->id].push_back(it);
        }
        
        int answer = 0;
        
        dfs(id, adj, answer, imp);
        
        return answer;
    }
};