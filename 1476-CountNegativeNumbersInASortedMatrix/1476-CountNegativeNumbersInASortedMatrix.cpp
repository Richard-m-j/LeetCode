// Last updated: 7/24/2025, 8:27:04 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int l = 0, r = n - 1, mid = 0;
        int i, j = 0;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(grid[mid][0] <= 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(grid[0][mid] <= 0 && l + 1 < n)
            i = l;
        else if(grid[0][0] < 0)
            return n * m;
        else
            i = n - 1;

        int count = 0;
        while(i >= 0 && j < m)
        {
            while(j < m && grid[i][j] >= 0)
            {
                count += i+1;
                j++;
            }
            i--;
        }
        return n*m - count;
    }
};