// 1. Recursive approach: O(number of nodes) time and O(number of nodes) space as well?!

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
class Solution {
public:
    ListNode* solve(ListNode*& head, ListNode* prev)
    {
        if(head == NULL or head->next == NULL)
            return head;
           
        head = head->next;
        ListNode* temp = head->next;
        head->next = prev;
        prev->next = temp;
        
        head->next->next = solve(temp, temp);
        
        return head;
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = head;
        
        return solve(head, prev);
    }
};

// 2.