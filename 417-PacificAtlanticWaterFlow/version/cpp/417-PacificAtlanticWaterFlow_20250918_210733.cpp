// Last updated: 9/18/2025, 9:07:33 PM
class Solution {
private: 
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& matrix, int i, int j, int val){
        if(i<0 || i==heights.size() || j<0 || j==heights[0].size() || matrix[i][j] || heights[i][j] < val){
            return;
        }
        matrix[i][j] = true;
        dfs(heights, matrix,i+1,j, heights[i][j]);
        dfs(heights, matrix,i-1,j, heights[i][j]);
        dfs(heights, matrix,i,j+1, heights[i][j]);
        dfs(heights, matrix,i,j-1, heights[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n)), atlantic(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            dfs(heights, pacific,i,0, 0);
            dfs(heights, atlantic,i,n-1, 0);
        }
        for(int i=0;i<n;i++){
            dfs(heights, pacific,0,i, 0);
            dfs(heights, atlantic,m-1,i, 0);
        }
        
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;        
    }
};