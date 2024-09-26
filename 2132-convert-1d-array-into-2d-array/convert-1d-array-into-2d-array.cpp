class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if(original.size() != m*n)
            return {};
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                row.push_back(original[i*n + j]);
            }
            res.push_back(row);
        }
        return res;
    }
};