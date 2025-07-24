// Last updated: 7/24/2025, 8:24:23 AM
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
    struct VectorHash {
        size_t operator()(const std::vector<int>& vec) const {
            size_t hash = 0;
            for (int num : vec) {
                hash ^= std::hash<int>{}(num);
            }
            return hash;
        }
    };
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        std::unordered_map<std::vector<int>, int, VectorHash> mp;
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