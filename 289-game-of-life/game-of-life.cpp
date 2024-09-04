class Solution {
private:
    vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                cout<<"+"<<i<<","<<j<<" "<<board[i][j]<<"-";
                for(auto &dir: dirs){
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if(x>=0 && x<n && y>=0 && y<m && (board[x][y] == 1 || board[x][y] == 2)){
                        count++;
                        cout<<" "<<x<<","<<y<<" ";
                    }
                }
                cout<<count<<endl;
                if(board[i][j] == 1 && (count<2 || count>3))
                    board[i][j] = 2; //new dead
                else if(board[i][j] == 0 && count == 3)
                    board[i][j] = 3; //new life
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j] == 2)
                    board[i][j] = 0;
                else if(board[i][j] == 3)
                    board[i][j] = 1;
        
    }
};