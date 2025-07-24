// Last updated: 7/24/2025, 8:28:45 AM
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;

        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        long long minSum = 0;
        const int MOD = (1e9 + 7);

        for (int i = 0; i < n; ++i) {
            minSum = (minSum + static_cast<long long>(arr[i]) * (i - left[i]) * (right[i] - i)) % MOD;
        }

        return static_cast<int>(minSum);
    }
};
