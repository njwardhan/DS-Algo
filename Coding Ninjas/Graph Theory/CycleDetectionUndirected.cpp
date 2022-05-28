// Problem Link: https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// 1. DFS Approach
// Linear time and space

#include<map>
string answer = "No";
void dfs(map<int, vector<int>>& adj, int node, int parent_node, map<int, bool>& visited)
{
	visited[node] = 1;
	for(auto it : adj[node])
	{
		if(!visited[it])
			dfs(adj, it, node, visited);
		else if(visited[it] and it == parent_node)
			continue;
		else if(visited[it] and it != parent_node)
			answer = "Yes";
	}
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    map<int, vector<int>> adj;
	for(int i = 0; i < edges.size(); i++)
	{
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	
	map<int, bool> visited;
	
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
			dfs(adj, i, -1, visited);
		
		if(answer == "Yes")
		{
			answer = "No";
			return "Yes";
		}
	}
	return "No";
}

// 2. BFS Approach
// 