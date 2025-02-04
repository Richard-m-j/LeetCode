class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long row1Sum = 0;
        for(int& num: grid[0])
            row1Sum += num;
        long long row2Sum = 0,res=LLONG_MAX;
        for(int i=0;i<n;i++){
            row1Sum -= grid[0][i];
            res = min(res,max(row1Sum,row2Sum));
            row2Sum += grid[1][i];
        }
        return res;
    }
};