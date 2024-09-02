class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }
    void connect(int a, int b) {
        int bParent = find(b);
        int aParent = find(a);
        if (aParent != bParent) {
            if (size[aParent] < size[bParent]) {
                parent[aParent] = bParent;
                size[bParent] += size[aParent];
            } else {
                parent[bParent] = aParent;
                size[aParent] += size[bParent];
            }
        }
    }
    // void connect(int a, int b){
    // int bParent = find(b);
    // int aParent = find(a);
    // if(aParent != bParent){
    //     if(size[aParent] < size[bParent]){
    //         parent[aParent] = bParent; // Make bParent the parent of aParent
    //         size[bParent] += size[aParent]; // CORRECTION: Add the size of
    //         aParent's set to bParent's set
    //     } else {
    //         parent[bParent] = aParent; // Make aParent the parent of bParent
    //         size[aParent] += size[bParent]; // CORRECTION: Add the size of
    //         bParent's set to aParent's set
    //     }
    // }


public : int
         longestConsecutive(vector<int>& nums) {
    for (int& num : nums) {
        if (parent.find(num) == parent.end()) {
            parent[num] = num;
            size[num] = 1;
        }
        if (parent.find(num + 1) != parent.end() && find(num) != find(num + 1))
            connect(num + 1, num);
        if (parent.find(num - 1) != parent.end() && find(num) != find(num - 1))
            connect(num, num - 1);
    }
    int res = 0;
    for (auto& it : size)
        res = max(res, it.second);
    return res;
}
}
;
