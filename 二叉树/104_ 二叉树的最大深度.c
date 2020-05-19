// Method 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
    return a > b ? a : b;
}
int dfs(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int left  = 1 + dfs(root->left);
    int right = 1 + dfs(root->right);
    return max(left, right);
}
int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return dfs(root);
}

// Method 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_ans;
int max(int a, int b)
{
    return a > b ? a : b;
}
void dfs(struct TreeNode* root, int *ans)
{
    if (root == NULL) {

        if (g_ans < *ans) {
            g_ans = *ans;
        }
        return;
    }
    int tmp = *ans + 1;
    dfs(root->left, &tmp);
    dfs(root->right, &tmp);
    return;
}
int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int ans = 0;
    g_ans = 0;
    dfs(root, &ans);
    return g_ans;
}