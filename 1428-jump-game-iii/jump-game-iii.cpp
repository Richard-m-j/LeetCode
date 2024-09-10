class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size(),false);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            if(arr[node] == 0)
                return true;
            int left = node - arr[node];
            int right = node + arr[node];
            if( left >=0 && !visited[left])
                q.push(left);
            if( right <arr.size() && !visited[right])
                q.push(right);
        }
        return false;
    }
};