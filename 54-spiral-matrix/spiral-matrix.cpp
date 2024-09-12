class Solution {
private:
    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int dir =0;
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> res;
        int x=0,y=0;
        while(res.size()<m*n){
            res.push_back(matrix[x][y]);
            matrix[x][y] = 101;
            int nextX = x + dirs[dir].first;
            int nextY = y + dirs[dir].second;
            if(nextX>=0 && nextY>=0 && nextX<m && nextY<n && matrix[nextX][nextY]!=101){
                x=nextX;
                y=nextY;
            }
            else{
                dir = (dir+1)%4;
                x = x + dirs[dir].first;
                y = y + dirs[dir].second;
            }
        }
        return res;
    }
};