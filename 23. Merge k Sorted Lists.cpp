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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode *a, ListNode *b){return a->val > b->val;};
        priority_queue<ListNode *,vector<ListNode*>, decltype(comp)> q(comp);
        ListNode Dummyhead;
        ListNode *p = &Dummyhead;
        
        for(ListNode *l : lists){
            if(l) q.push(l);
        }
        
        while(!q.empty()){
            ListNode *Node = q.top();
            p->next = Node;
            q.pop();
            p = p->next;
            if(Node->next) q.push(Node->next);
        }
        
        return Dummyhead.next;
    }
};