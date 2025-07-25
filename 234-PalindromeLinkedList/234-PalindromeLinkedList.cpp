// Last updated: 7/24/2025, 8:32:30 AM
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
    bool isPalindrome(ListNode* head) {
        string s;

        while(head) {
            s += to_string(head -> val);
            head = head -> next;
        }

        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
};