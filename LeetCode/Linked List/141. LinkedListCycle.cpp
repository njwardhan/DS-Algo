// 1. Hash map usage: O(N) time and space solution (N = number of nodes in the list)

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
    bool hasCycle(ListNode *head) {
        map<int, const ListNode *> values;
        if(head == NULL)
            return false;
        
        values.insert({0, head});
        head = head->next;
        int i = 1;
        
        while(head != NULL)
        {
            for(auto x : values)
            {
                if(x.second == head)
                    return true;
            }  
            values.insert({i, head});
            head = head->next;
            i++;
        }
        return false;
    }
};

// 2. Modifying the linked list approach: O(N) time and constant space solution

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
    bool hasCycle(ListNode *head) {
        while(head != NULL)
        {
            if(head->val == 1000000)
                return true;
            
            else
            {
                head->val = 1000000;
                head = head->next;
            }
        }
        return false;
    }
};

// 3. Not modifying the linked list and no extra space taken .. 