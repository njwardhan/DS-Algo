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

// O(2N) = O(N) time and constant space solution

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int counter = 0;
        ListNode* ptr = head;
        while(head != NULL)
        {
            counter += 1;
            head = head->next;
        }
        int c = counter - 1;
        long int sum = 0;
        while(ptr != NULL)
        {
            sum += ptr->val * pow(2, c);
            c--;
            ptr = ptr->next;
        }
        return sum;
    }
};