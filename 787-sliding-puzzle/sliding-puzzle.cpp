class Solution {
private:
    vector<vector<int>> goalPos = {{1, 2}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}};

    string boardToString(vector<vector<int>>& board) {
        string s = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                s += board[i][j] + '0';
            }
        }
        return s;
    }
    vector<vector<int>> stringToBoard(string s) {
        vector<vector<int>> board(2, vector<int>(3, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = s[i * 3 + j] - '0';
            }
        }
        return board;
    }

    // Heuristic function: Manhattan Distance + moves so far (A* search)
    int f(string s, int g) {
        vector<vector<int>> board = stringToBoard(s);
        int h = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                int val = board[i][j];
                if (val != 0) {
                    h += abs(goalPos[val][0] - i) + abs(goalPos[val][1] - j);
                }
            }
        }
        return h + g;
    }

    // Generate all possible successor states
    vector<string> generateSuccessors(string s) {
        vector<string> succ;
        int zeroIdx = s.find('0'); 
        int row = zeroIdx / 3, col = zeroIdx % 3;

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto move : moves) {
            int newRow = row + move.first, newCol = col + move.second;
            if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                string newS = s;
                swap(newS[zeroIdx], newS[newRow * 3 + newCol]); 
                succ.push_back(newS);
            }
        }

        return succ;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> visited;
        string goal = "123450";
        string boardString = boardToString(board);

        priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, greater<>> pq;

        pq.push({f(boardString, 0), {0, boardString}}); 
        visited.insert(boardString);

        while (!pq.empty()) {
            auto [fVal, node] = pq.top();
            auto [g, current] = node;
            pq.pop();

            if (current == goal) {
                return g; 
            }

            // Generate next possible states
            vector<string> nextStates = generateSuccessors(current);
            for (auto& next : nextStates) {
                if (!visited.count(next)) {
                    int nextG = g + 1;
                    pq.push({f(next, nextG), {nextG, next}});
                    visited.insert(next); 
                }
            }
        }

        return -1;
    }
};