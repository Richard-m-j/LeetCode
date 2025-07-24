// Last updated: 7/24/2025, 8:31:18 AM
class Solution {
public:
    vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adjList;
        vector<double> ans;

        for (int i = 0; i < equations.size(); i++) {
            adjList[equations[i][0]][equations[i][1]] = values[i];
            adjList[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }

        for (const vector<string>& query : queries) {
            double result = -1.0;

            if (adjList.find(query[0]) != adjList.end() && adjList.find(query[1]) != adjList.end()) {
                if (query[0] == query[1]) {
                    result = 1.0;
                } else {
                    unordered_map<string, bool> visited;
                    result = dfs(query[0], query[1], 1.0, adjList, visited);
                }
            }

            ans.push_back(result);
        }
        return ans;
    }

private:
    double dfs(const string& from, const string& to, double product, unordered_map<string, unordered_map<string, double>>& adjList, unordered_map<string, bool>& visited) {
        if (from == to) {
            return product;
        }

        visited[from] = true;
        
        for (const auto& neighbor : adjList[from]) {
            if (!visited[neighbor.first]) {
                double temp = dfs(neighbor.first, to, product * neighbor.second, adjList, visited);
                if (temp != -1.0) {
                    return temp;
                }
            }
        }

        return -1.0;
    }
};
