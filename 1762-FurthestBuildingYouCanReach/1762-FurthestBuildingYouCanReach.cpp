// Last updated: 7/24/2025, 8:26:09 AM
const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> bricksUsed;
        int n = heights.size();
        
        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                bricksUsed.push(-diff);
                //use bricks only if ladders are unavailable
                if (bricksUsed.size() > ladders) {
                    //since it is a minheap, the smallest number will be subtracted from bricks
                    bricks += bricksUsed.top(); 
                    bricksUsed.pop();
                }
                if (bricks < 0) {
                    return i; // Can't go further, return the current index
                }
            }
        }
        
        return n - 1; // Reachable till the last building
    }
};