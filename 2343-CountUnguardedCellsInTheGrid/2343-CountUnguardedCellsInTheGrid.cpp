// Last updated: 7/24/2025, 8:24:36 AM
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> mat(m,vector<int>(n,0));
        vector<pair<int,int>> dirs = {{0,-1},{0,1},{1,0},{-1,0}};
        //0 empty
        //1 guarded
        //2 wall
        //3 guard
        for(auto& wall: walls)
            mat[wall[0]][wall[1]]=2;
        
        for(auto& guard: guards)
            mat[guard[0]][guard[1]]=3;
        int count=0;
        for(auto& guard: guards){
            for(auto& dir: dirs){
                int i=guard[0] + dir.first;
                int j=guard[1] + dir.second;
                while(i>=0 && j>=0 && i<m && j<n){
                    if(mat[i][j]>1)
                        break;
                    if(mat[i][j] == 0){
                        mat[i][j] = 1;
                        count++;
                    }
                    i += dir.first;
                    j += dir.second;
                }
            }
        }
        return m*n - walls.size() - guards.size() - count;
    }
};