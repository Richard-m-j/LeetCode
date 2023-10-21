class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        for(int i=0; i<equations.size(); i++)
        {
            adjList[equations[i][0]].emplace_back(equations[i][1],values[i]);
            adjList[equations[i][1]].emplace_back(equations[i][0],1.00000/values[i]);
        }
        for(auto q: queries)
        {
            visited.clear();
            if(adjList.find(q[1]) == adjList.end())
            {
                ans.push_back(-1.0000);
                continue;
            }
            double searchResult = dfs(q[0],q[1],1.0000);
            ans.push_back(searchResult);
            if(searchResult != -1.0000)
                adjList[q[0]].emplace_back(q[1],searchResult);
        }
        return ans;
    }
    double dfs(string from, string to,double product)
    {
        if(visited.find(from) != visited.end())
            return -1.0000;
        if(adjList.find(from) == adjList.end())
            return -1.0000;
        visited[from] = true;
        
        vector <pair<string,double>> edgeList = adjList[from];
        double search = -1.0000;;
        for(auto edge: edgeList)
        {
            if(edge.first == to)
                return product * edge.second;
            search = dfs(edge.first,to,product * edge.second);
            if(search != -1.0000)
                break;
        }
        return search;      
    }

private:
    unordered_map <string, vector <pair<string,double>>> adjList;
    unordered_map <string, bool> visited;
    vector<double> ans;
};