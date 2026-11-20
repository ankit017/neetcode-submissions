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

class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int preorderIndex, int inorderStart, int inorderEnd) {
        if(inorderStart>inorderEnd)
        return nullptr;

        int rootVal = preorder[preorderIndex];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = mp[rootVal];

        int leftSize = rootIndex - inorderStart;

        root->left = build(preorder, inorder, preorderIndex+1, inorderStart, rootIndex-1);

        root->right = build(preorder, inorder, preorderIndex+leftSize+1, rootIndex+1, inorderEnd);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, 0, inorder.size()-1);
        
    }
};
