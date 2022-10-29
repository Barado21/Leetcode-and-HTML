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
    pair<ListNode*, ListNode*> revList(ListNode* head){
        ListNode *rev=nullptr, *temp=nullptr, *revEnd=head;
        while(head){
            temp = head;
            head = head->next;
            temp->next = rev;
            rev = temp;
        }
        return pair<ListNode*, ListNode*>(rev, revEnd);
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int k=0;
        ListNode *a=nullptr, *b=head, *c=head, *d=head->next;
        
        while(d){
            k++;
            int currentSize=1;
            for(int i=1; c->next!=nullptr && i<k; ++i){
                c = c->next;
                currentSize++;
            }
            d = c->next;
            
            if(currentSize%2==0){
                a->next = nullptr;
                c->next = nullptr;
                pair<ListNode*, ListNode*> revPart = revList(b);
                a->next = get<0>(revPart);
                (get<1>(revPart))->next = d;
                a = get<1>(revPart);
                b = d;
                c = b;
            }
            else{
                a = c;
                b = d;
                c = b;
            }
        }
        
        return head;
    }
};