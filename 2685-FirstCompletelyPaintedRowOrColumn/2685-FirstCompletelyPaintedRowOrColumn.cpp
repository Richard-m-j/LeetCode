// Last updated: 7/24/2025, 8:23:32 AM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(),n=mat[0].size();
        vector<int> row(m,n),col(n,m);
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                mp[mat[i][j]]={i,j};
        
        for(int i=0;i<arr.size();i++){
            row[mp[arr[i]].first]--;
            col[mp[arr[i]].second]--;
            // cout<<mp[i].first<<" "<<mp[i].second<<endl;
            if(!row[mp[arr[i]].first] || !col[mp[arr[i]].second])
                return i;
        }
        return -1;
    }
};