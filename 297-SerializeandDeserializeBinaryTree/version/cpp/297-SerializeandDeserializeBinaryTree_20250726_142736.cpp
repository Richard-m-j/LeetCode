// Last updated: 7/26/2025, 2:27:36 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) {
            return "#";
        }
        
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == nullptr) {
                result += "# ";
                continue;
            }
            
            result += to_string(node->val) + " ";
            q.push(node->left);
            q.push(node->right);
        }
        
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") {
            return nullptr;
        }
        
        int pos = 0;
        auto getNext = [&]() {
            int start = pos;
            while (pos < data.length() && data[pos] != ' ') {
                pos++;
            }
            string token = data.substr(start, pos - start);
            pos++; 
            return token;
        };

        string root_val_str = getNext();
        TreeNode* root = new TreeNode(stoi(root_val_str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            string left_val_str = getNext();
            if (left_val_str != "#") {
                node->left = new TreeNode(stoi(left_val_str));
                q.push(node->left);
            }
            
            string right_val_str = getNext();
            if (right_val_str != "#") {
                node->right = new TreeNode(stoi(right_val_str));
                q.push(node->right);
            }
        }
        
        return root;
    }
};