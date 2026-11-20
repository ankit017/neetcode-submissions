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
    int solve(TreeNode* root,int &ans) {
        if(root == nullptr)
        return 0;

        int leftSum = solve(root->left, ans);
        int rightSum = solve(root->right, ans);

        int maxBetweenLeftAndRightmax = max(leftSum+root->val, rightSum+root->val);
        int maxAtNode = max(maxBetweenLeftAndRightmax,max(root->val, root->val+leftSum+rightSum));
        int maxToParent = max(root->val, maxBetweenLeftAndRightmax);
        ans = max(ans, maxAtNode);
        return maxToParent;

    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
