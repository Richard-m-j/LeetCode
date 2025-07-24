// Last updated: 7/24/2025, 8:24:14 AM
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        sort(intervals.begin(),intervals.end());
        int res=0;
        priority_queue<int,vector<int>,greater<int>> heap;
        for(auto& it: intervals){
            while(!heap.empty() && it[0]>heap.top())
                heap.pop();
            heap.push(it[1]);
            res = max(res,int(heap.size()));
        }
        return res;
    }
};