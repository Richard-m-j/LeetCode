class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=grid.size();
        vector<vector <int>> colGrid(n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                colGrid[j].push_back(grid[i][j]);
        int count=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i]==colGrid[j])
                    count++;
        return count;
                
    }
};