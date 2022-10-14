// 1. O(N) time and constant space --> not the best LC performance

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* answer = head;
        ListNode* node = NULL;
        ListNode* prev = NULL;
        int count = 0;
        
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        
        if(count == 1)
            return NULL;
        head = answer;
        int middle = count/2;
        count = 0;
        
        while(head != NULL)
        {
            if(count == middle-1)
            {
                prev = head;
                node = head->next;
                
                prev->next = node->next;
                break;
            }
            count++;
            head = head->next;
        }
        return  answer;
    }
};

// 2. O(N) time and constant space --> better LC performance
// While finding the middle position of any data structure, this slow-fast concept can come very handy. Point to remember!!

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
            return NULL;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        
        while(1)
        {
            if(fast == NULL or fast->next == NULL)
                break;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};