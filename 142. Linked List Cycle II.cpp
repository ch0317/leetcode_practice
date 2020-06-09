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
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                break;
            }
        }
        
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }else
        {
            ListNode *slow1 = head;
            ListNode *slow2 = fast;
            
            while(slow1 != slow2){
                slow1 = slow1->next;
                slow2 = slow2->next;
            }
        
            return slow1;
        }
        
    }
};