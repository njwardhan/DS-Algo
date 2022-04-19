// 1. Making use of an array to store list elements, then again creating sub-arrays to process the solution
// O(N) time ..

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* Solve(vector<int> nums)
    {
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
        
        root->left = Solve(left);
        root->right = Solve(right);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> node_values;
        
        while(head != NULL)
        {
            node_values.push_back(head->val);
            head = head->next;
        }
        
        return Solve(node_values);
    }
};

// 2. Not making use of sub-arrays for processing - very poor LC performance 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> node_values;
        
        while(head != NULL)
        {
            node_values.push_back(head->val);
            head = head->next;
        }
        
        return Solve(node_values, 0, node_values.size()-1);
    }
};