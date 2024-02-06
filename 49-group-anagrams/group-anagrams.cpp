class Solution {
private:
    struct VectorHash {
        size_t operator()(const vector<int>& vec) const {
            size_t hash = 0;
            for (auto& i : vec) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, int, VectorHash> mp;
        vector<vector<string>> res;
        int index = 0;

        for (const auto& str : strs) {
            vector<int> mapping(26, 0);
            for (char c : str) {
                mapping[c - 'a']++;
            }

            if (mp.find(mapping) != mp.end()) {
                res[mp[mapping]].push_back(str);
            } else {
                mp[mapping] = index++;
                res.push_back({str});
            }
        }

        return res;
    }
};
