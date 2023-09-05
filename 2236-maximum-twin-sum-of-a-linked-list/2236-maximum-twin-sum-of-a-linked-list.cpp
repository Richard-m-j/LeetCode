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

#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values; values.reserve(1000);
        for (ListNode* itr = head; itr; itr = itr->next) values.push_back(itr->val);
        if (values.size() > 100000) return values.size();
        int res = 0, n = values.size();
        for (int i = 0; i < n / 2; ++i) res = max(values[i] + values[n-1-i], res);
        return res;
    }
};