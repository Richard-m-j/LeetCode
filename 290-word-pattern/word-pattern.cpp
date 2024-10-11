class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mp;
        unordered_map<char, string> rmp;

        vector<string> words;
        int i = 0;
        string word = "";
        while (i < s.length()) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else
                word += s[i];
            i++;
        }
        words.push_back(word);

        if (words.size() != pattern.length())
            return false;
        for (int j = 0; j < words.size(); j++) {
            if (!mp.count(words[j]) && !rmp.count(pattern[j])) {
                mp[words[j]] = pattern[j];
                rmp[pattern[j]] = words[j];
            }
            else if(!mp.count(words[j]) || !rmp.count(pattern[j]))
                return false;
            else {
                if(mp[words[j]] != pattern[j] || rmp[pattern[j]] != words[j])
                    return false;
            }
        }
        return true;
    }
};