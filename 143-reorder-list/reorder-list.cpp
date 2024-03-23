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
    void reorderList(ListNode* head) {
        vector<ListNode*> nums;
        ListNode* ptr = head;
        while (ptr) {
            nums.push_back(ptr);
            ptr = ptr->next;
        }
        int n = nums.size();
        if (n == 1 || n == 2)
            return;
        ptr = head;
        head->next = nums[n - 1];
        ptr = ptr->next;
        int l = n % 2 ? n / 2 + 1 : n / 2;
        for (int i = 1; i < l; i++) {
            ptr->next = nums[i];
            ptr = ptr->next;

            ptr->next = nums[n - i - 1];
            ptr = ptr->next;
            cout << nums[i]->val << " " << nums[n - i - 1]->val << " ";
        }
        ptr->next = NULL;
        return;
    }
};