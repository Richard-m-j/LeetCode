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

        string rev;
        for(int i = s.length() - 1; i > -1; i--) 
            rev += s[i];
        
        return rev == s;
    }
};