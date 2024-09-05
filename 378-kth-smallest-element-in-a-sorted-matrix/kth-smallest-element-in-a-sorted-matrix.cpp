class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int l=matrix[0][0];
        int h=matrix[n-1][n-1];
        int m,count;
        while(l<h){
            m=l+(h-l)/2;
            count =0;
            for(int i=0;i<n;i++){
                count += upper_bound(matrix[i].begin(),matrix[i].end(),m) - matrix[i].begin();
            }
            if(count<k)
                l=m+1;
            else
                h=m;
        }
        return l;
    }
};