/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// https://leetcode-cn.com/problems/validate-binary-search-tree/
bool helper(struct TreeNode* root, long long lower, long long upper)
{
    if (root == NULL) {
        return true;
    }
    if (root->val <= lower || root->val >= upper) {
        return false;
    }
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}
    

bool isValidBST(struct TreeNode* root){
    return helper(root, LONG_MIN, LONG_MAX);
}
