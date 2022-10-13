/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1. O(1) space-time solution

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        node->next = temp->next;
        node->val = temp->val;
        delete temp;
    }
};

// 2. O(N) time and constant space
// Copying all values from node onwards till end to the previous node .. 
// Very very bad approach xD

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp = node->next->val;
        while(node->next->next != NULL)
        {
            node->val = temp;
            temp = node->next->next->val;
            node = node->next;
        }
        node->val = temp;
        node->next = NULL;
    }
};