class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> row = {1};
            vector<int> prevRow = pascal[i-1];
            for(int j=1;j<prevRow.size();j++)
                row.push_back(prevRow[j-1]+prevRow[j]);
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal;
    }
};
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1