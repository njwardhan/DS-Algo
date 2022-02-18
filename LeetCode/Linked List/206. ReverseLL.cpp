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

// 1. Iterative method: O(N) time and constant space solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current;
        while(head != NULL)
        {
            current = head->next;
            head->next = prev;
            prev = head;
            head = current;
        }
        return prev;
    }
};

// 2. Recursive method: 