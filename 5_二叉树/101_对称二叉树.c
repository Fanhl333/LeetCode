// 用堆栈存储，官方递归更加简洁
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define STACK_SIZE 1001
struct Stack {
    int data[STACK_SIZE];
    int top;
};

void StackInit(struct Stack *s)
{
    s->top = -1;
}

bool StackIsEmpty(struct Stack *s)
{
    if (s->top == -1) {
        return true;
    } else {
        return false;
    }
}

void StackPush(struct Stack *s, int val)
{
    s->top++;
    s->data[s->top] = val;
}

int StackPop(struct Stack *s)
{
    int topVal = s->data[s->top];
    s->top--;
    return topVal;
}

int StackCount(struct Stack *s)
{
    return s->top + 1;
}

void RecordLeft(struct TreeNode* root, struct Stack *s)
{
    if (root == NULL) {
		// 对于没有的节点存为1保持对称性
        StackPush(s, -1);
        return;
    }
    StackPush(s, root->val);
    RecordLeft(root->left, s);
    RecordLeft(root->right, s);
}

void RecordRight(struct TreeNode* root, struct Stack *s)
{
    if (root == NULL) {
         StackPush(s, -1);
        return;
    }
    StackPush(s, root->val);
    RecordRight(root->right, s);
    RecordRight(root->left, s);
}

bool Judge(struct Stack *s1, struct Stack *s2)
{
    while (!StackIsEmpty(s1)) {
        if (StackPop(s1) != StackPop(s2)) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL) {
        return true;
    }
    struct Stack leftStack;
    struct Stack rightStack;
    StackInit(&leftStack);
    StackInit(&rightStack);
    RecordLeft(root->left, &leftStack);
    RecordRight(root->right, &rightStack);
    if (StackCount(&leftStack) != StackCount(&rightStack)) {
        return false;
    }
    return Judge(&leftStack, &rightStack);
}