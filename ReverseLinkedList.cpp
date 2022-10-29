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
    ListNode* reverseList(ListNode* head) {
        ListNode *rev = nullptr;
        ListNode* temp = head;
        while(head){
            head = head->next;
            temp->next = rev;
            rev = temp;
            temp = head;
        }
        head = rev;
        return head;
    }
};