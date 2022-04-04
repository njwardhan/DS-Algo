// 1. O(3N) = O(N) time and constant space solution. Not the best LC performance though .. 

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* ptr3 = head;
        int count = 0;
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        
        int val1, val2;
        int k_check = 0;
        while(ptr1 != NULL)
        {
            k_check++;
            if(k_check == k)
                val1 = ptr1->val;
            if(k_check == count-k+1)
                val2 = ptr1->val;
            
            ptr1 = ptr1->next;                
        }
        k_check = 0;
        while(ptr2 != NULL)
        {
            k_check++;
            if(k_check == k)
                ptr2->val = val2;
            if(k_check == count-k+1)
                ptr2->val = val1;
            
            ptr2 = ptr2->next;
        }
        
        return ptr3;
    }
};

// 2. 