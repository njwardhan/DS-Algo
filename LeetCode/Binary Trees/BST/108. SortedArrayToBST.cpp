// 1. Not making use of smaller arrays .. 
// O(N) time, where N = number of elements in the array, and O(height of tree) space

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
    TreeNode* Solve(vector<int> nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int middle = (start + end) / 2;
        
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = Solve(nums, start, middle-1);
        root->right = Solve(nums, middle+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {        
        return Solve(nums, 0, nums.size()-1);
    }
};

// 2. Making use of smaller arrays - Much better LC performance lol?
// O(N) time, where N = number of elements in the array ..

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        
        if(nums.size() == 1)
        {
            TreeNode* temp = new TreeNode(nums[0]);
            return temp;
        }
        
        int middle = nums.size()/2;
        
        vector<int> left(nums.begin(), nums.begin()+middle);
        vector<int> right(nums.begin()+middle+1, nums.end());
            
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        
        return root;
    }
};