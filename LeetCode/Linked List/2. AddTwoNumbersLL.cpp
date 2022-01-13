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

// String manipulation solution: O(length of longer number) time and constant space

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp_sum, carry = 0;
        string sum = " ";
        
        while(l1 or l2 or carry)
        {   
            temp_sum = 0;
            int v1 = (l1? l1->val : 0);
            int v2 = (l2? l2->val : 0);
            
            temp_sum = v1 + v2 + carry;
            carry = 0;
            if (temp_sum >= 10)
            {
                temp_sum = temp_sum % 10;
                carry = 1;
            }
            sum.append(to_string(temp_sum));
            
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        
        ListNode* next = NULL;
        for(int i = sum.size()-1; i > 0; i--)
        {
            int d = sum[i] - '0';
            ListNode* newList = new ListNode(d, next);
            next = newList;
        }
        
        return next;
    }
};