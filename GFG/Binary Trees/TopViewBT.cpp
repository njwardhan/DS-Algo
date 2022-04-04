// O(N) time and O(height of tree) space

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void Traversal(Node* root, map<Node*, pair<int,int>>& njw, pair<int,int> coordinates)
    {
        if(root == NULL)
            return;
        
        njw[root] = coordinates;
        
        Traversal(root->left, njw, make_pair(coordinates.first+1, coordinates.second-1));
        Traversal(root->right, njw, make_pair(coordinates.first+1, coordinates.second+1));
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> answer;
        map<Node*, pair<int,int>> njw;
        
        njw[root] = make_pair(0,0);
        
        Traversal(root->left, njw, make_pair(1,-1));
        Traversal(root->right, njw, make_pair(1,1));        
        
        int min_col = INT_MAX, max_col = INT_MIN;
        for(auto x : njw)
        {
            if(x.second.second >= max_col)
                max_col = x.second.second;
            if(x.second.second <= min_col)
                min_col = x.second.second;
        }
        
        while(min_col <= max_col)
        {
            int col = min_col;
            
            int hope;
            int min_row = INT_MAX;
            for(auto x : njw)
            {
                if(x.second.second == col)
                {
                    if(x.second.first < min_row)
                    {
                        hope = x.first->data;
                        min_row = x.second.first;
                    }
                }
            }
            answer.push_back(hope);
            min_col++;
        }
        return answer;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends