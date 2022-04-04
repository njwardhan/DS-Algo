// O(N) time and O(N) space solution ..

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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* previous_node = head;
        ListNode* answer = previous_node;
        
        int sum = 0;
        while(head != NULL)
        {
            if(head->val != 0)
                sum += head->val;
            else
            {
                ListNode* new_node = new ListNode;
                new_node->val = sum;
                sum = 0;
                previous_node->next = new_node;
                previous_node = previous_node->next;
            }
            
            head = head->next;
        }
        return answer->next;
        
    }
};