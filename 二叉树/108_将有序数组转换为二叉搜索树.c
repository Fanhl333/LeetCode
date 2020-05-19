/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *CreateNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->val =val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode *CreateBST(int *nums, int start, int end)
{
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    // printf("%d\n", mid);
    struct TreeNode *root = CreateNode(nums[mid]);
    root->left  = CreateBST(nums, start, mid - 1);
    root->right = CreateBST(nums, mid + 1, end);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    struct TreeNode *root;
    root = CreateBST(nums, 0, numsSize - 1);
    return root;
}