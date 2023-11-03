class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        ios_base::sync_with_stdio(0);cin.tie(nullptr);
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int depth{0};
        while (!q.empty()) 
        {
            
            int size = q.size();
            
            for (int i = 0; i < size; i++) 
            {
                auto current = q.front();
                q.pop();
                int x = current.first;
                int y = current.second;

                if (x != entrance[0] || y != entrance[1]) 
                    if (x == 0 || y == 0 || x == m - 1 || y == n - 1) 
                        return depth;

                for (const auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if (newX>=0 && newX<m && newY>=0 && newY<n && !visited[newX][newY] && maze[newX][newY]=='.') 
                    {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};
