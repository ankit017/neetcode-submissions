/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
        return "";
        queue<TreeNode*> q;
        string encodedString="";
        q.push(root);

        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp==nullptr)
            encodedString+="N,";
            else {
                encodedString+=to_string(tmp->val)+",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            
        }

        encodedString.pop_back();

        return encodedString;     
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        return nullptr;
        stringstream ss(data);
        vector<string> tokens;
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        queue<TreeNode*> q;

        int i=0;

        TreeNode* node = new TreeNode(stoi(tokens[0]));
        q.push(node);
        i++;
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tokens[i] != "N") {
                tmp->left = new TreeNode(stoi(tokens[i]));
                q.push(tmp->left);
            }
            else {
                tmp->left = nullptr;
            }

            i++;

            if(tokens[i] != "N") {
                tmp->right = new TreeNode(stoi(tokens[i]));
                q.push(tmp->right);
            }
            else {
                tmp->right = nullptr;
            }
            i++;
        }
        return node;
    }
};
