// Last updated: 7/24/2025, 8:24:05 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<int> tree;
    void update(int node, int st, int end, int i, int val) {
        if (st == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (st + end) / 2;
        if (i <= mid)
            update(node * 2, st, mid, i, val);
        else
            update(node * 2 + 1, mid + 1, end, i, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
    int query(int node, int st, int end, int x, int y) {
        if (x > end || y < st)
            return -1e9;
        if (st >= x && end <= y)
            return tree[node];

        int mid = (st + end) / 2;
        int left = query(2 * node, st, mid, x, y);
        int right = query(2 * node + 1, mid + 1, end, x, y);
        return max(left, right);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int m = *max_element(nums.begin(), nums.end());
        tree.clear();
        tree.resize(4 * m + 10);
        for (int i = n - 1; i >= 0; i--) {
            int l = nums[i] + 1, r = min(nums[i] + k, m);
            int x = query(1, 0, m, l, r);
            if (x == -1e9)
                x = 0;
            update(1, 0, m, nums[i], x + 1);
        }
        return tree[1];
    }
};