/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // 官方思路，后续遍历： left_node --> right_node --> mid_node
struct TreeNode *ans;
bool dfs(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (root == NULL) {
        return false;
    }
    bool left = dfs(root->left, p, q);
    bool right = dfs(root->right, p, q);
    if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))) {
        ans = root;
    }
    return left || right || root->val == p->val || root->val == q->val;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    dfs(root, p, q);
    return ans;
}

// method 2
struct TreeNode* dfs(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->val == p->val || root->val == q->val) {
        return root;
    }
    struct TreeNode* left  = dfs(root->left, p, q);
    struct TreeNode* right = dfs(root->right, p, q);
    if (left && right) {
        return root;
    }
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    return NULL;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *ans;
    ans = dfs(root, p, q);
    return ans;
}
