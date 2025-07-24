// Last updated: 7/24/2025, 8:31:45 AM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;

        while(l<r){
            swap(s[l],s[r]);
            l++,r--;
        }
    }
};