// Last updated: 7/24/2025, 8:25:01 AM
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> degree;
        for(vector<int>& node: pairs){
            graph[node[0]].push_back(node[1]);
            degree[node[0]]++;
            degree[node[1]]--;
        }
        int start=pairs[0][0];
        for(auto& it: degree)
            if(it.second==1){
                start = it.first;
                break;
            } 
        vector<int> path;  
        stack<int> nodeStack;
        nodeStack.push(start);
        while(!nodeStack.empty()){
            int node = nodeStack.top();
            vector<int>& neighbours = graph[node];
            if(neighbours.empty()){
                path.push_back(node);
                nodeStack.pop();
            }
            else{
                int next = neighbours.back();
                nodeStack.push(next);
                neighbours.pop_back();
            }
        }
        vector<vector<int>> res;
        for(int i=path.size()-1;i>0;i--){
            vector<int> pair = {path[i],path[i-1]};
            res.push_back(pair);
        }
        return res;
    }
};