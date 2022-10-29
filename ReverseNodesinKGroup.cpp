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
    pair<ListNode*,ListNode*> revList(ListNode* head){
        ListNode *rev=nullptr, *temp=head, *revEnd=head;
        while(head){
            temp = head;
            head = head->next;
            temp->next = rev;
            rev = temp;
        }
        return pair<ListNode*, ListNode*>(rev,revEnd);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode *ptr1=head, *ptr2=head;
        for(int i=1; i<k; ++i){
            ptr2 = ptr2->next;
            if(ptr2==nullptr){
                return ptr1;
            }
        }
        ListNode *nextPart = ptr2->next;
        ptr2->next = nullptr;
        
        pair<ListNode*, ListNode*> revPart = revList(ptr1);
        (get<1>(revPart))->next = reverseKGroup(nextPart, k);
        return get<0>(revPart);
    }
};