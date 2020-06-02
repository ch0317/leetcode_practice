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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhead = new ListNode;
        ListNode *tail = dummyhead;
        int carry = 0;
        int sum = 0;
        while(l1 || l2 || carry)
        {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            ListNode *node = new ListNode;
            node->val = sum % 10;
            tail->next = node;
            tail = node;
            carry = sum / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return dummyhead->next;
    }
};