// Problem Link: https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// Very basic but very important problem!
// Generally graph builing using adjacency list happnes in O(N+M) space which is much better than O(N^2) of an adjacency matrix

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // First we create a vector whose each index contains an array of size n. Why n? Because each node will at max have connections
    // with all the nodes which is = n. 
    // So in this data structure, we basically collect the data for edges in a proper format, that is why the loop also runs till the 
    // number of edges. Also, m = edges.size(), obviously
    vector<int> store[n];
	
	for(int i = 0; i < m; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		
		store[u].push_back(v);
		store[v].push_back(u);
	}
	
    // After the edges data is collected, another data structure is created which is a vector of vectors (as per the return type specified 
    // by the question)
    // We also need to specify the size of this data structure --> VERY IMPORTANT! Because if a vector of vector has a specified size, it basically
    // takes up indexes from 0 to size-1 and whose data can then be directly accessed. 
    // Without the size specification, we will get segmentation fault or runtime error, and rightly so!
    // This data structure will obviously have info. for n nodes, hence the loop constraint.
    // Finally the data is entered as per the output format of the question and the return statement is executed!
	vector<vector<int>> answer{n};
	
	for(int i = 0; i < n; i++)
	{
		answer[i].push_back(i);
		for(int j = 0; j < store[i].size(); j++)
			answer[i].push_back(store[i][j]);
	}
	return answer;
}