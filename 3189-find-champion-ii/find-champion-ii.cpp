class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> indegree(n,0);
        for(auto edge: edges)
            indegree[edge[1]]++;
        int champion=-1;
        for(int i=0;i<n;i++)
            if(indegree[i]==0){
                if(champion==-1)
                    champion=i;
                else
                    return -1;
            }
                
        return champion;
    }
};