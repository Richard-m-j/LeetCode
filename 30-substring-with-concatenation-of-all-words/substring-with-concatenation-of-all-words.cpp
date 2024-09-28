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
        
        // Build the frequency map of words
        for (string &word : words) {
            wordMap[word]++;
        }
        
        // Try each possible starting position within a single word length window
        for (int i = 0; i < wordLen; ++i) {
            int start = i;  // Sliding window start
            unordered_map<string, int> windowMap;
            int count = 0;
            
            for (int j = i; j + wordLen <= s.length(); j += wordLen) {
                string word = s.substr(j, wordLen);
                
                // If the word is in words, update the window map
                if (wordMap.count(word)) {
                    windowMap[word]++;
                    count++;
                    
                    // If we exceed the count in wordMap, shrink the window
                    while (windowMap[word] > wordMap[word]) {
                        string firstWord = s.substr(start, wordLen);
                        windowMap[firstWord]--;
                        start += wordLen;
                        count--;
                    }
                    
                    // If the window size matches the number of words, we found a valid starting index
                    if (count == wordCount) {
                        res.push_back(start);
                    }
                } else {
                    // If the word is not in words, reset the window
                    windowMap.clear();
                    count = 0;
                    start = j + wordLen;
                }
            }
        }
        
        return res;
    }
};
