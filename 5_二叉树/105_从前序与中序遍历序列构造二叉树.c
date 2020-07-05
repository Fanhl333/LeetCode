/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };Right
 */

int FindRootIndexFromInorder(int val, int *inorder, int inLeft, int inRight)
{
    for (int i = inLeft; i <= inRight; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

struct TreeNode *CreateNewNode(int val)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* helper(int* preorder, int preLeft, int preRight, int* inorder, int inLeft, int inRight)
{
    if (preLeft > preRight || inLeft > inRight) {
        return NULL;
    }
    struct TreeNode *root = CreateNewNode(preorder[preLeft]);
    int rootIndex = FindRootIndexFromInorder(preorder[preLeft], inorder, inLeft, inRight);
    root->left  = helper(preorder, preLeft + 1,  rootIndex - inLeft + preLeft, inorder, inLeft, rootIndex - 1);
    root->right = helper(preorder, rootIndex - inLeft + preLeft + 1, preRight, inorder, rootIndex + 1, inRight);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize != inorderSize) {
        return NULL;
    }
    if (preorderSize == 0) {
        return NULL;
    }
    return helper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}