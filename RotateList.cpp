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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        
        ListNode *prev=nullptr, *curr=head;
        int sz=0;
        while(curr){
            sz++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        
        for(int i=0; i<(sz-k%sz)%sz; ++i){
            prev = head;
            head = head->next;
        }
        prev->next = nullptr;
        
        return head;
    }
};