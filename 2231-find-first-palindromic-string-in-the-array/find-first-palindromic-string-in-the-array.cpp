class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for (string& word : words) {
            int l = 0, r = word.length() - 1;
            for (; l <= r; l++, r--)
                if (word[l] != word[r])
                    break;
            if (l > r)
                return word;
        }
        return "";
    }
};