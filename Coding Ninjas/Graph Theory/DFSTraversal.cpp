// Problem Link: https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// Quite simple algorithm. Would be simpler if directly the DFS printing is needed, unlike this question
// O(N+E) or linear time and space algorithm!

void DFS(map<int,vector<int>>& adj, int node, map<int,bool>& visited, vector<int>& temp)
{
	visited[node] = 1;
	temp.push_back(node);
	
	for(auto it : adj[node])
	{
        // Recursive calls made
		if(!visited[it])
			DFS(adj, it, visited, temp);
	}
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
	vector<vector<int>> answer;
	map<int,vector<int>> adj;
    for(int i = 0; i < edges.size(); i++)
	{
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	map<int,bool> visited;
	
	for(int i = 0; i < V; i++)
	{
		vector<int> temp;
		if(!visited[i])
		{
			DFS(adj, i, visited, temp);
			answer.push_back(temp);
		}
	}
	return answer;
}

