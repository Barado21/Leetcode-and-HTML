/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
           
        // int carry = 0;
        // ListNode p, dummy = new ListNode(0);
        // p = dummy;
        // while (l1 != null || l2 != null || carry != 0) {
        //     if (l1 != null) {
        //         carry += l1.val;
        //         l1 = l1.next;
        //     }
        //     if (l2 != null) {
        //         carry += l2.val;
        //         l2 = l2.next;
        //     }
        //     p.next = new ListNode(carry%10);
        //     carry /= 10;
        //     p = p.next;
        // }
        // return dummy.next;
        
        ListNode newHead = new ListNode(0);
        ListNode temp = newHead;
        int carry = 0;
        
        while(l1!=null || l2!=null || carry!=0){
            int val = 0;
            if(l1!=null){
                val+=l1.val;
                l1=l1.next;
            }
            if(l2!=null){
                val+=l2.val;
                l2 = l2.next;
            }
            int finalVal = val + carry;
            
            temp.next = new ListNode(finalVal%10);
            temp = temp.next;
            carry = finalVal/10;
        }
        return newHead.next;

    
    }
}
