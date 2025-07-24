// Last updated: 7/24/2025, 8:35:07 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int lrow = 0, rrow = n-1;

        while(lrow <= rrow)
        {
            int mrow = lrow + (rrow-lrow)/2;
            if(matrix[mrow][0] <= target && target <= matrix[mrow][m-1])
            {
                int lcol = 0, rcol = m-1;
                while(lcol <= rcol)
                {
                    int mcol = lcol + (rcol - lcol)/2;
                    if(target == matrix[mrow][mcol])
                        return true;
                    else if (target < matrix[mrow][mcol])
                        rcol = mcol - 1;
                    else
                        lcol = mcol + 1;
                }
                return false;
            }
            else if(matrix[mrow][0] < target)
                lrow = mrow + 1;
            else
                rrow = mrow - 1;
        }
        return false;
    }
};