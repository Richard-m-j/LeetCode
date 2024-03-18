class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),bucketSort);
        int count = 1;
        int end = points[0][1];
        for(auto & point: points)
            cout<<point[0]<<","<<point[1]<<" ";
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end)
            {
                count++;
                end = points[i][1];
            }
            else if(points[i][1]>end){
                ;
            }
            else{
                end = points[i][1];
            }
        }
        return count;
    }
    static bool bucketSort(const vector<int> a,const vector<int> b){
        if(a[0] == b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
};