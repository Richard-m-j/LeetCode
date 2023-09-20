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
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int carry{0};
        ListNode* head;
        ListNode* ptr;
        head = new ListNode();
        ptr = head;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            if(sum>9)
            {
                carry = sum / 10;
                sum %= 10;
            }
            else
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int sum = l1->val + carry;
            if(sum>9)
            {
                carry = sum / 10;
                sum %= 10;
            }
            else
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int sum =  l2->val + carry;
            if(sum>9)
            {
                carry = sum / 10;
                sum %= 10;
            }
            else
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l2 = l2->next;
        }
        while(carry)
        {
            int sum =  carry;
            if(sum>9)
            {
                carry = sum / 10;
                sum %= 10;
            }
            else
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }
        return head->next;
    }
};