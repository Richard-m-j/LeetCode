// Last updated: 7/24/2025, 8:28:00 AM
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++)
            for(int j=1;j<n;j++)
                matrix[i][j] += matrix[i][j - 1];

        int count = 0;
        for(int l = 0; l<n; l++)
            for(int r = l;r<n;r++)
            {
                unordered_map<int,int> hashSum;
                hashSum[0]++;
                int sum = 0;
                for(int i = 0; i<m; i++)
                {
                    sum += matrix[i][r] - (l > 0 ? matrix[i][l-1] : 0);
                    count += hashSum[sum - target];
                    hashSum[sum]++;
                }
            }
        
        return count;
    }
};