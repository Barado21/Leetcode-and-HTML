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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return head;
        }
        
        ListNode *oddStart=head, *oddEnd=head, *evenStart=head->next, *evenEnd=head->next, *ptr=head->next->next, *temp=nullptr;
        bool isOdd = true;
        
        while(ptr){
            temp = ptr;
            ptr = ptr->next;
            
            if(isOdd){
                evenEnd->next = ptr;
                evenEnd = ptr;
                oddEnd->next = temp;
                temp->next = evenStart;
                oddEnd = temp;
            }
            
            isOdd = !isOdd;
        }
        
        return head;
    }
};