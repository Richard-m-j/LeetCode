class Solution {
private:
    vector<vector<char>> board;
    vector<vector<bool>> visited;

    string word;
    int n, m;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool helper(int x, int y, int k) {
        visited[x][y] = true;
        if(k+1 < word.size()){
            for (auto& dir : dirs) {
                int xi = x + dir.first;
                int yi = y + dir.second;
                if (xi >= 0 && xi < n && yi >= 0 && yi < m) {
                    if (!visited[xi][yi] && k<word.size() - 1 && word[k+1] == board[xi][yi])
                        if(helper(xi, yi, k + 1))
                            return true;
                }
            }
        }
        else
            return true;
            
        visited[x][y] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& b, string w) {
        board = b;
        word = w;
        n = board.size();
        m = board[0].size();
        visited.resize(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(word[0] == board[i][j] && helper(i,j,0))
                    return true;
        return false;
    }
};