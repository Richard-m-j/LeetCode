class Solution {
private:
    vector<int> parent;
    vector<int> res = {0, 0};

    int find(int i) {
        if(parent[i] != i) 
            parent[i] = find(parent[i]);

        return parent[i];
    }

    void connect(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB)
            res = {a, b};
        else 
            parent[parentA] = parentB;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() + 1);

        for(int i = 1; i <= edges.size(); i++)
            parent[i] = i;

        for(int i = 0; i < edges.size(); i++)
            connect(edges[i][0], edges[i][1]);

        return res;    
    }
};