// Last updated: 7/24/2025, 8:35:22 AM
class Solution {
private: 
    vector<vector<int>> dp;
    int m,n;
public:
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        dp.resize(m,vector<int>(n,-1));
        
        return helper(0,0);
    }
    int helper(int row, int col)
    {
        if(row == m || row <0 || col == n || col <0)
            return 0;
        if(dp[row][col] != -1)
            return dp[row][col];
        if(row == m-1 && col == n-1)
            return 1;
        dp[row][col] = helper(row,col+1) + helper(row + 1, col);
        return dp[row][col];
    }
};