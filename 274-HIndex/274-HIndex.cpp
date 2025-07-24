// Last updated: 7/24/2025, 8:32:09 AM
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int res = min(n,citations.back());
        for (int i = n - 1; i >= 0; i--) {
            if(citations[i]<n-i)
                return res;
            res = n-i;
        }
        return res;
    }
};