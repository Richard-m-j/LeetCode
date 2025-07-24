// Last updated: 7/24/2025, 8:22:54 AM
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> indegree(n,0);
        for(const vector<int>& edge: edges)
            indegree[edge[1]]++;
        int champion=-1;
        for(int i=0;i<n;i++)
            if(indegree[i]==0){
                if(champion!=-1)
                    return -1;
                champion=i;
            }
                
        return champion;
    }
};