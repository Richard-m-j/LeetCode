// Last updated: 7/24/2025, 8:23:40 AM
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums1.size(); i++)
            arr.push_back({nums1[i], nums2[i]});
        sort(arr.begin(), arr.end(), compareSecond());
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> nums1Queue;
        long long maxScore = 0;
        for (int i = 0; i < k; i++) 
        {
            sum += arr[i].first;
            nums1Queue.push(arr[i].first);
            maxScore = sum * arr[i].second;
        }
        
        for (int i = k; i < nums1.size(); i++) {
            sum = sum - nums1Queue.top() + arr[i].first;
            nums1Queue.pop();
            nums1Queue.push(arr[i].first);
            maxScore = max(maxScore, sum * arr[i].second); 
        }
        return maxScore;
    }

private:
    struct compareSecond {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second > b.second;
        }
    };
};