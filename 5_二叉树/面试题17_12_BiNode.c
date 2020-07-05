/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // 面试题 17.12. BiNode : https://leetcode-cn.com/problems/binode-lcci/
struct TreeNode *head, *pre;
void InOrder(struct TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    InOrder(root->left);
    root->left = NULL;
    pre->right = root;
    pre = root;
    InOrder(root->right);

}

struct TreeNode* convertBiNode(struct TreeNode* root){
    struct TreeNode *head = malloc(sizeof(struct TreeNode));
    if (head == NULL) {
        return NULL;
    }
    head->left  = NULL;
    head->right = NULL;
    pre = head;
    InOrder(root);
    pre = head->right;
    free(head);
    return pre;
}