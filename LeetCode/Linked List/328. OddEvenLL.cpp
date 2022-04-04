// O(N) time and constant space

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_store = even;
                
        while(odd != NULL and odd->next != NULL)
        {
            ListNode* temp1 = odd->next->next;
            ListNode* temp2 = odd->next;
            odd->next = temp1;
            if(odd->next != NULL)
                odd = odd->next;
            if(even != temp2)
            {
                even->next = temp2;            
                even = even->next;
            }
        }

        even->next = NULL;
        odd->next = even_store;
        return head;
    }
};