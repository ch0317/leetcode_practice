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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* tail = dummyhead;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        while(l1){
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        while(l2){
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
        
        return dummyhead->next;
    }
};