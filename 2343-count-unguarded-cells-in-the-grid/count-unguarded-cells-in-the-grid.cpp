class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> mat(m,vector<int>(n,0));
        //0 empty
        //1 guarded
        //2 wall
        //3 guard
        for(auto& wall: walls)
            mat[wall[0]][wall[1]]=2;
        
        for(auto& guard: guards)
            mat[guard[0]][guard[1]]=3;
        
        for(auto& guard: guards){
            vector<pair<int,int>> dirs = {{0,-1},{0,1},{1,0},{-1,0}};
            for(auto& dir: dirs){
                int i=guard[0] + dir.first;
                int j=guard[1] + dir.second;
                while(i>=0 && j>=0 && i<m && j<n){
                    if(mat[i][j]>1)
                        break;
                    if(mat[i][j] == 0)
                        mat[i][j] = 1;
                    i += dir.first;
                    j += dir.second;
                }
            }
        }
        int res = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j] == 0)
                    res++;
        return res;
    }
};