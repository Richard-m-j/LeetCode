class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;
        
        unordered_map<string, int> wordMap;
        int wordLen = words[0].length();
        int wordCount = words.size();
        int sequenceLen = wordLen * wordCount;
        
        if (s.length() < sequenceLen) return res;
        
        for (string &word : words) {
            wordMap[word]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int start = i;  
            unordered_map<string, int> windowMap;
            int count = 0;
            
            for (int j = i; j + wordLen <= s.length(); j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (wordMap.find(word)!=wordMap.end()) {
                    windowMap[word]++;
                    count++;
                    
                    while (windowMap[word] > wordMap[word]) {
                        string firstWord = s.substr(start, wordLen);
                        windowMap[firstWord]--;
                        start += wordLen;
                        count--;
                    }
                    
                    if (count == wordCount) {
                        res.push_back(start);
                    }
                } else {
                    windowMap.clear();
                    count = 0;
                    start = j + wordLen;
                }
            }
        }
        
        return res;
    }
};
