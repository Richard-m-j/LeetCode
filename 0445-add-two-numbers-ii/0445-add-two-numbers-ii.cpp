/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
**/
int speedUp = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1 = "", num2 = "";

        // Convert linked list values to strings
        ListNode* ptr = l1;
        while (ptr) {
            num1 += to_string(ptr->val);
            ptr = ptr->next;
        }

        ptr = l2;
        while (ptr) {
            num2 += to_string(ptr->val);
            ptr = ptr->next;
        }

        int n1 = num1.length();
        int n2 = num2.length();
        ListNode* ans = new ListNode();
        ListNode* ptrAns = ans; 
        int carry = 0;
        int i = n1 - 1, j = n2 - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

            int sum = digit1 + digit2 + carry;

            carry = sum / 10;
            sum = sum % 10;
            ptrAns -> val = sum;
            ans = new ListNode();
            ans -> next = ptrAns; 
            ptrAns = ans;
        }

        return ans->next; // Skip the dummy node
    }
};
