// Daily Challenge: 20th April 2022
// 1. Making use of a separate data structure: hasNext() and next() function having O(1) time, but overall space = O(N), which is not really good

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
class BSTIterator {
public:
    int iterator = 0;
    vector<int> values;
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while(1)
        {
            if(root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                if(s.empty())
                    break;
                root = s.top();
                values.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
    }
    
    int next() {
        int temp = values[iterator++];
        return temp;
    }
    
    bool hasNext() {
        if(iterator >= values.size())
            return false;
        else
            return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//--------------------------------------------------------------------------------------------------------------------------------------------

// 2. Without using any extra data strucutre, making the space complexity as O(height of tree) --> as asked in the question
// Time complexity of the hasNext() and next() on an average ~O(1) .. can take more in some cases too
// Lots of things to learn here:
//      a. Constructor will not be called again and again. If it is needed, create a private method for its work
//      b. In questions like this (where a set of commands .. "next", "hasNext" is used as input), we as users don't have to call those functions.
//          We just need to implement those working functions.
//      c. Questions based on OOP design are very very important! 

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
class BSTIterator {
private:
    stack<TreeNode*> s;
    
    void pushAll(TreeNode* root, stack<TreeNode*>& s)
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
       pushAll(root, s);
    }
    
    int next() {
        TreeNode* tempNode = s.top();
        s.pop();
        pushAll(tempNode->right, s);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */