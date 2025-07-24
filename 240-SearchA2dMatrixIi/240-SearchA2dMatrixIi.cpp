// Last updated: 7/24/2025, 8:32:17 AM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n=matrix.size();
        int m=matrix[0].size();
        int col = m - 1;
        int row = 0;
        while(col >= 0 && row < n){
            if(matrix[row][col] == target)
                return true;
            else if(target <matrix[row][col])
                col--;
            else 
                row++;
        }
        return false;
    }
};