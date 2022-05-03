// Problem Link: https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// Here, the traversal function is called per component of the graph, so new queue is created for each component of the graph
// If the graph is not disconnected, then the BFS traversal is completed in one call of the Traversal function only .. we won't even need to make the initial call from within a for loop in that case!
// Also, if for each node, we need the adjacent nodes stored in ascending (sorted) order, we make use of set instead of list/vector in the adjacency matrix
// Otherwise list/vector also works good enough

// O(nodes + edges) space and time algorithm

#include<map>
#include<queue>
#include<set>
void BFSTraversal(int node, map<int,set<int>>& adj, vector<int>& answer, map<int,bool>& visited)
{
	queue<int> q;
	
	q.push(node);
	visited[node] = 1;
	
	while(!q.empty())
	{
		int frontnode = q.front();
		q.pop();
		answer.push_back(frontnode);
		for(auto it : adj[frontnode])
		{
			if(!visited[it])
			{
				q.push(it);
				visited[it] = 1;
			}
		}
	}
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> answer;
	map<int,set<int>> adj;
	
	for(int i = 0; i < edges.size(); i++)
	{
		adj[edges[i].first].insert(edges[i].second);
		adj[edges[i].second].insert(edges[i].first);
	}
	
	map<int,bool> visited;
			
	for(int i = 0; i < vertex; i++)
	{
		if(!visited[i])
			BFSTraversal(i, adj, answer, visited);
	}
	return answer;
}