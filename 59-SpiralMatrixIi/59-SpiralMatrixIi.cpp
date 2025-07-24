// Last updated: 7/24/2025, 8:35:25 AM
class Solution {
private: 
    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));

        int num = 0;
        int x = 0, y = 0;
        int dir = 0;
        while(num<n*n){
            num++;
            // cout<<x<<" "<<y<<endl;
            mat[x][y] = num;
            int nextX = x + dirs[dir].first;
            int nextY = y + dirs[dir].second;
            if(nextX<0 || nextX==n || nextY<0 || nextY==n || mat[nextX][nextY]){
                dir = (dir+1)%4;
                x = x + dirs[dir].first;
                y = y + dirs[dir].second;
            }
            else{
                x = nextX;
                y = nextY;
            }
        }
        return mat;
    }
};