// O(N) time and constant space solution

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head_store = head;
        ListNode* ptr = NULL;
        int count = 0;
        
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        
        if(count == 1)
            return NULL;
        if(count == n)
            return head_store->next;
        
        int check = 0;
        head = head_store;
        
        while(head != NULL)
        {
            check++;
            if(check == count-n)
            {
                ptr = head->next->next;
                head->next = ptr;
            }
            head = head->next;
        }
        return head_store;
    }
};