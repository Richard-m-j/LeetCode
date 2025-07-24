// Last updated: 7/24/2025, 8:30:22 AM
class Solution {
private:
    int res = 0;
    vector<int> parent;

    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void make(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    void connect(int a, int b) {
        int parentA = find(a);
        int parentB = find(b); 

        if(parentA == parentB)
            return;
        
        parent[parentA] = parentB;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        make(n);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])
                    connect(i, j);
        
        for(int i = 0; i < n; i++)
            if(parent[i] == i)
                res++;

        return res;
    }
};