class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort the intervals
        sort(intervals.begin(),intervals.end(),[](const auto &a, const auto &b){
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    });
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<","<<intervals[i][1]<<" ";
        }
        cout<<endl;
        vector<int> dp(intervals.size(),0);
        int res = 0;
        int l = intervals[0][0];
        int r = intervals[0][1];
    
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]==l){
                res++;
                cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            }
            else if(intervals[i][0]<r){
                r = min(r,intervals[i][1]);
                res++;
            }
            else{
                l  = intervals[i][0];
                r = intervals[i][1];
            }
        }
        return res;
    }
};