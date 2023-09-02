// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n=grid.size();
//         vector<vector <int>> colGrid(n);

//         for(int i=0;i<n;i++)
//             for(int j=0;j<n;j++)
//                 colGrid[j].push_back(grid[i][j]);
//         int count=0;
//         for(int i=0;i<n;i++)
//             for(int j=0;j<n;j++)
//                 if(grid[i]==colGrid[j])
//                     count++;
//         return count;
                
//     }
// };
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<vector<int>, int> mp;
        int ans = 0;
        for(int row = 0; row < grid.size(); row++){
            mp[grid[row]]++;
        }
        for(int i = 0; i < grid.size(); i++){
            vector<int> v;
            for(int j = 0; j < grid.size(); j++){
                v.push_back(grid[j][i]);
            }
            ans += mp[v];
        }
        return ans;
    }
};