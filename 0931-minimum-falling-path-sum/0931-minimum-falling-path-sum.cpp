int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
private:
    int n;
    vector<vector<int>> minSum;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        n = matrix.size();
        minSum.resize(n, vector<int>(n, INT_MAX));
        int minimum = INT_MAX;
        for(int i = 0; i < n; i++)
            minimum = min(helper(matrix,0,i), minimum);
        return minimum;
    }
    int helper(vector<vector<int>>& matrix,int i,int j)
    {
        if(i<0 || i==n || j<0 || j==n)
            return INT_MAX;
        if(minSum[i][j] != INT_MAX)
            return minSum[i][j];
        int recursion = min(min(helper(matrix,i+1,j-1),helper(matrix,i+1,j)),helper(matrix,i+1,j+1));
        if(i == n-1)
            recursion = 0;
        minSum[i][j] = matrix[i][j] + recursion;
        return minSum[i][j];
    }
};