class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0; // End word must be in the dictionary
        }

        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;

        while (!q.empty()) {
            int levelSize = q.size(); // Number of elements at the current level
            for (int i = 0; i < levelSize; ++i) {
                string currentWord = q.front();
                q.pop();
                
                if (currentWord == endWord) {
                    return ladderLength;
                }

                // Generate all possible transformations
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue; // Skip the same character replacement
                        currentWord[j] = c;
                        if (dict.find(currentWord) != dict.end()) {
                            q.push(currentWord);
                            dict.erase(currentWord); // Remove from dictionary to prevent revisiting
                        }
                    }
                    currentWord[j] = originalChar; // Restore the original character
                }
            }
            ladderLength++; // Increase the path length for the next level
        }

        return 0; // If no path was found
    }
};
