class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        int res = 0;

        for(int j=0;j<n-1;j++){
            bool nextCol = false;
            for(int i=0;i<m;i++){
                if(j> 0 && !dp[i][j])
                    continue;
                if(i>0 && grid[i-1][j+1]>grid[i][j])
                    dp[i-1][j+1] += 1,nextCol=true;
                if(grid[i][j+1]>grid[i][j])
                    dp[i][j+1] += 1,nextCol=true;
                if(i<m-1 && grid[i+1][j+1]>grid[i][j])
                    dp[i+1][j+1] += 1,nextCol=true;
                // cout<<j<<" ";
            }
            if(nextCol)
                res = j+1;
            else
                break;
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return res;
    }
};