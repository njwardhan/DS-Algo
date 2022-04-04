// 1. O(N^2) time in worst case and constant space. Poor LC performance, obviously .. 

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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* current_node = head;
        vector<int> answer;
        int key;
        
        while(head != NULL)
        {
            key = 0;
            current_node = head->next;
            while(current_node != NULL)
            {
                if(current_node->val > head->val)
                {
                    answer.push_back(current_node->val);
                    key = 1;
                    break;
                }
                current_node = current_node->next;
            }
            if(key == 0)
                answer.push_back(0);
            head = head->next;
        }
        return answer;
    }
};

// 2.