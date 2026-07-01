/*
Problem: Add Two Numbers

Approach:

Traverse both linked lists simultaneously.
Add corresponding digits along with the carry.
Create a new node containing sum % 10.
Update the carry as sum / 10.
Continue until both lists are exhausted and no carry remains.

Complexity:

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m)) (for the output list)
  */

// Code :-

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry)
        {
            int sum = 0;
            if(l1!=nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};
