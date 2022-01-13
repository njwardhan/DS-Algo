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

// String Manipulation: O(length of the longer number) space-time. Poor solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = "", s2 = "", s = "";
        while(l1)
        {
            s1.append(to_string(l1->val));
            l1 = l1->next;
        }
        while(l2)
        {
            s2.append(to_string(l2->val));
            l2 = l2->next;
        }

        int temp_sum, carry = 0;
        while(!s1.empty() or !s2.empty() or carry)
        {
            int a = (!s1.empty()? s1.back() - '0' : 0);
            int b = (!s2.empty()? s2.back() - '0' : 0);
            
            temp_sum = 0;        
            temp_sum = a + b + carry;
            carry = 0;
            if(temp_sum >= 10)
            {
                temp_sum = temp_sum % 10;
                carry = 1;
            }
            s.append(to_string(temp_sum));
            
            if(!s1.empty())
                s1.pop_back();
            if(!s2.empty())
                s2.pop_back();
        }
        
        ListNode* next = NULL;
        for(int i = 0; i <= s.length()-1; i++)
        {
            int d = s[i] - '0';
            ListNode* newList = new ListNode(d, next);
            next = newList;
        }
        return next;        

    }
};