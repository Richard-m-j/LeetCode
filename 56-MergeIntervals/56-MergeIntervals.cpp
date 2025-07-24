// Last updated: 7/24/2025, 8:35:29 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(end<intervals[i][0]){
                merged.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                end = max(intervals[i][1],end);
            }
        }
        merged.push_back({start,end});
        return merged;
    }
};