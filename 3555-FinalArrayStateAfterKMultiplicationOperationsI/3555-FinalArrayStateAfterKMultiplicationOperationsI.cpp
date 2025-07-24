// Last updated: 7/24/2025, 8:22:18 AM
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});
        for(int i=0;i<k;i++){
            auto [num,idx] = pq.top();
            pq.pop();
            nums[idx]=num*multiplier;
            pq.push({nums[idx],idx});
        }
        return nums;
    }
};