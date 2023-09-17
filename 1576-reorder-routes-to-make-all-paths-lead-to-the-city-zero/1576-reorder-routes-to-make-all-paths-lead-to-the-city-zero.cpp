class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector <vector <pair <int, bool>>> graph(n);

        // Build the graph with direction information
        for (const auto& con : connections) 
        {
            graph[con[0]].emplace_back(con[1], true);   // Forward edge
            graph[con[1]].emplace_back(con[0], false);  // Reverse edge
        }
        int ans = 0;
        vector<bool> visited(n, false);
        stack<int> stack;
        stack.push(0);

        while (!stack.empty()) 
        {
            int node = stack.top();
            stack.pop();
            visited[node] = true;

            for (const auto& neighbor : graph[node]) 
            {
                int nextNode = neighbor.first;
                bool isForwardEdge = neighbor.second;

                if (!visited[nextNode]) 
                {
                    if (isForwardEdge) 
                        ans++;  // Reorder needed for this edge
                    
                    stack.push(nextNode);
                }
            }
        }

        return ans;
    }
};
