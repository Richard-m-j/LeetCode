class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<pair<int, int>> heap;
        int n = times.size();
        for (int i=0;i<n;i++)
            times[i].push_back(i);

        sort(times.begin(), times.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) 
                return a[1] < b[1];
            return a[0]<b[0];
            });
        set<int> freeChairs;
        for (int i = 0; i < n; i++) {
            int arrival = times[i][0];
            int leave = times[i][1];
            int index = times[i][2];
            while (!heap.empty() && arrival >= -(heap.top().first)){
                // cout<<arrival<<" "<<-(heap.top().first)<<endl;
                freeChairs.insert(heap.top().second);
                heap.pop();
            }
            int chair;
            if (freeChairs.size()) {
                chair = *freeChairs.begin();
                freeChairs.erase(chair);
            } else {
                chair = heap.size();
                // cout<<heap.size()<<" ";
            }
            heap.push({-leave, chair});
            if(index == targetFriend)
                return chair;
        }
        return -1;
    }
};