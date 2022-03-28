// 1. First ever hard question, but somehow xD

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void RightTraversal(TreeNode* root, map<TreeNode*, pair<int,int>>& map, pair<int,int> coordinates)
    {
        if(root == NULL)
            return;
        
        map[root] = coordinates;
        
        RightTraversal(root->right, map, make_pair(++coordinates.first, ++coordinates.second));
        --coordinates.second;
        --coordinates.first;
        RightTraversal(root->left, map, make_pair(++coordinates.first, --coordinates.second));
        ++coordinates.second;
        --coordinates.first;
    }
    
    void LeftTraversal(TreeNode* root, map<TreeNode*, pair<int,int>>& map, pair<int,int> coordinates)
    {
        if(root == NULL)
            return;
        
        map[root] = coordinates;
        
        LeftTraversal(root->left, map, make_pair(++coordinates.first, --coordinates.second));
        ++coordinates.second;
        --coordinates.first;
        LeftTraversal(root->right, map, make_pair(++coordinates.first, ++coordinates.second));
        --coordinates.second;
        --coordinates.first;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<TreeNode*, pair<int,int>> map;
        vector<vector<int>> answer;
        
        map[root] = make_pair(0,0);
        
        LeftTraversal(root->left, map, make_pair(1,-1));
        RightTraversal(root->right, map, make_pair(1,1));
        
        int min_col = INT_MAX, max_col = INT_MIN;
        for(auto x : map)
        {
            if(x.second.second >= max_col)
                max_col = x.second.second;
            if(x.second.second <= min_col)
                min_col = x.second.second;
        }

        while(min_col <= max_col)
        {
            int col = min_col;
            vector<int> njw;
            vector<vector<int>> help;

            for(auto x : map)
            {
                if(x.second.second == col)
                {
                    int min_row = INT_MAX, max_row = INT_MIN;
                    for(auto y : map)
                    {
                        if(y.second.first >= max_row and y.second.second == col)
                            max_row = y.second.first;
                        if(y.second.first <= min_row and y.second.second == col)
                            min_row = y.second.first;
                    }
                    while(min_row <= max_row)
                    {
                        int row = min_row;
                        vector<int> temp;
                        for(auto z : map)
                        {
                            if(z.second.first == row and z.second.second == col)
                                temp.push_back(z.first->val);
                        }
                        sort(temp.begin(), temp.end());
                        if(!temp.empty() and !count(help.begin(), help.end(), temp))
                        {
                            help.push_back(temp);
                            temp.clear();
                        }
                        min_row++;
                    }
                }
            }
            for(int i = 0; i < help.size(); i++)
            {
                for(int j = 0; j < help[i].size(); j++)
                    njw.push_back(help[i][j]);
            }
            answer.push_back(njw);
            njw.clear();
            help.clear();
            min_col++;
        }
        return answer;
    }
};

// 2.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    void Traversal(TreeNode* root, map<TreeNode*, pair<int,int>>& map, pair<int,int> coordinates)
    {
        if(root == NULL)
            return;
        
        map[root] = coordinates;
        
        Traversal(root->left, map, make_pair(coordinates.first+1, coordinates.second-1));
        Traversal(root->right, map, make_pair(coordinates.first+1, coordinates.second+1));
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<TreeNode*, pair<int,int>> map;
        vector<vector<int>> answer;
        
        map[root] = make_pair(0,0);
        
        Traversal(root->left, map, make_pair(1,-1));
        Traversal(root->right, map, make_pair(1,1));
        
        int min_col = INT_MAX, max_col = INT_MIN;
        for(auto x : map)
        {
            if(x.second.second >= max_col)
                max_col = x.second.second;
            if(x.second.second <= min_col)
                min_col = x.second.second;
        }

        while(min_col <= max_col)
        {
            int col = min_col;
            vector<int> njw;
            vector<vector<int>> help;

            for(auto x : map)
            {
                if(x.second.second == col)
                {
                    int min_row = INT_MAX, max_row = INT_MIN;
                    for(auto y : map)
                    {
                        if(y.second.first >= max_row and y.second.second == col)
                            max_row = y.second.first;
                        if(y.second.first <= min_row and y.second.second == col)
                            min_row = y.second.first;
                    }
                    while(min_row <= max_row)
                    {
                        int row = min_row;
                        vector<int> temp;
                        for(auto z : map)
                        {
                            if(z.second.first == row and z.second.second == col)
                                temp.push_back(z.first->val);
                        }
                        sort(temp.begin(), temp.end());
                        if(!temp.empty() and !count(help.begin(), help.end(), temp))
                        {
                            help.push_back(temp);
                            temp.clear();
                        }
                        min_row++;
                    }
                }
            }
            for(int i = 0; i < help.size(); i++)
            {
                for(int j = 0; j < help[i].size(); j++)
                    njw.push_back(help[i][j]);
            }
            answer.push_back(njw);
            njw.clear();
            help.clear();
            min_col++;
        }
        return answer;
    }
};