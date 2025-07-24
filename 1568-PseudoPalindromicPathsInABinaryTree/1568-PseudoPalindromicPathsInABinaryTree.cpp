// Last updated: 7/24/2025, 8:26:39 AM
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        unordered_map<int, int> pathFrequency;

        dfs(root, pathFrequency, count);

        return count;
    }

private:
    void dfs(TreeNode* node, unordered_map<int, int>& pathFrequency, int& count) {
        if (node == nullptr)
            return;

        // Update the frequency of the current node's value
        pathFrequency[node->val]++;

        // Check if it's a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            // Check if the path is pseudo-palindromic
            if (isPseudoPalindromic(pathFrequency))
                count++;
        } else {
            // Recursive calls for left and right subtrees
            dfs(node->left, pathFrequency, count);
            dfs(node->right, pathFrequency, count);
        }

        // Backtrack: restore the frequency to the state before the current node
        pathFrequency[node->val]--;

        return;
    }

    bool isPseudoPalindromic(const unordered_map<int, int>& pathFrequency) {
        int oddCount = 0;

        // Count the number of nodes with odd frequency
        for (const auto& entry : pathFrequency) {
            if (entry.second % 2 != 0)
                oddCount++;
        }

        // A path is pseudo-palindromic if it has at most one node with an odd frequency
        return oddCount <= 1;
    }
};