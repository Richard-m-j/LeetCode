class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> q;
        unordered_map<char, int> mp;
        for (char& task : tasks)
            mp[task-'A']++;
        for (auto& it : mp)
            q.push({it.second, it.first});
        int res = 0;
        while (!q.empty()) {
            priority_queue<pair<int,char>> q1;
            int count = min((int)q.size(), n+1);
            int delta = 0;
            for (int i = 0; i < count; i++) {
                auto it = q.top();
                q.pop();
                delta++;
                if(it.first>1)
                    q1.push({it.first - 1, it.second});
            }
            while (!q.empty()) {
                q1.push(q.top());
                q.pop();
            }
            if(!q1.empty())
                res += delta <= n ? n + 1 : delta;
            else
                res += delta;
            q = q1;
        }
        return res;
    }
};