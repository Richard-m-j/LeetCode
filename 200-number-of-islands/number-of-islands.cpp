class Solution {
private: 
    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';
        for(auto& dir: dirs){
            int x = row + dir.first;
            int y = col + dir.second;
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == '1')
                dfs(grid,x,y);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    res++;
                }
        return res; 
    }
};