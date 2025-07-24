// Last updated: 7/24/2025, 8:32:55 AM
int speedUp= []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        int numVisited=0;
        // vector<bool> visited(numCourses,false);
        for(auto& edge: prerequisites)
            graph[edge[0]].push_back(edge[1]);
        
        for(int i=0;i<prerequisites.size();i++){
            vector<bool> visited(numCourses,false);
            visited[prerequisites[i][0]] = true;
            if(!dfs(graph,visited,prerequisites[i][1])){
                // cout<<"- "<<i<<" ";
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
        if(visited[node]){
            // cout<<node<<" ";
            return false;
        }
        visited[node] = true;
        // cout<<"v"<<node<<"_"<<graph[node].size()<<" ";
        for(int i=graph[node].size()-1;i>=0;i--)
            if(!dfs(graph,visited,graph[node][i])){
                // cout<<node<<" ";
                return false;
            }
            else{
                graph[node].pop_back();
            }
        visited[node] = false;
        
        return true;
    }
};