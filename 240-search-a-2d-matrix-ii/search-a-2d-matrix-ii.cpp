class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(matrix[i][0]>target)
                return false;
            int l = lower_bound(matrix[i].begin(),matrix[i].end(),target) - matrix[i].begin();
            if(l<m && matrix[i][l] == target)
                return true;
        }
        return false;
    }
};