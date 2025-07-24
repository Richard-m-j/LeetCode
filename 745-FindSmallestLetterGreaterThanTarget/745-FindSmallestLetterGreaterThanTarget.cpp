// Last updated: 7/24/2025, 8:29:26 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,n =letters.size();
        int r = n-1;
        int m;
        while(l<=r)
        {
            m = l+(r-l)/2;
            if(letters[m] == target)
            {
                while(m<n-1 && letters[m+1] == target)
                    m++;
                if(m!=n-1)
                    return letters[m+1];
                else
                    return letters[0];
            }
            else if(letters[m]<target)
                l = m + 1;
            else
                r = m - 1;
        }
        if(r<0 || l>=n)
            return letters[0];
        return letters[l];
    }
};