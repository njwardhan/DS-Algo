// 1. Hash map approach: O(N) time and space solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<int, const ListNode *> values;
        if(head == NULL)
            return NULL;
        
        values.insert({0, head});
        head = head->next;
        int i = 1;
        
        while(head != NULL)
        {
            for(auto x : values)
            {
                if(x.second == head)
                    return head;
            }  
            values.insert({i, head});
            head = head->next;
            i++;
        }
        return NULL;
    }
};

// 2. Not modifying the linked list and no extra space taken .. 