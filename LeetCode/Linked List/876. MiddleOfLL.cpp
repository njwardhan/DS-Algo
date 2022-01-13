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

// O(N+N) = O(2N) = O(N) time  and constant space solution

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int counter = 0;
        ListNode* temp = head;
        while(head != NULL)
        {
            counter += 1;
            head = head->next;
        }
        
        int middle = counter/2;
        counter = 1;
        while(temp != NULL & counter <= middle)
        {
            temp = temp->next;
            counter += 1;
        }
        
        return temp;
    }
};
