/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define QUEUE_SIZE 1001
typedef struct Queue_ {
    struct TreeNode *data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void QueueInit(Queue *q)
{
    q->front = 0;
    q->rear  = 0;
}

bool QueueIsEmpty(Queue *q)
{
    return q->front == q->rear;
}

bool QueueIsFull(Queue *q)
{
    int rearNext = (q->rear + 1) % QUEUE_SIZE;
    return rearNext == q->front;
}

void EnQueue(Queue *q, struct TreeNode *node)
{
    if (QueueIsFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (node == NULL) {
        return;
    }
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
}

struct TreeNode *DeQueue(Queue *q)
{
    if (QueueIsEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;  
    }
    struct TreeNode *node;
    node = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    return node;
}

int QueueCount(Queue *q)
{
    if (q->rear - q->front >= 0) {
        return q->rear - q->front;
    } else {
        return q->rear - q->front + QUEUE_SIZE;
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int **ans = (int **)malloc(sizeof(int *) * 10001);
    *returnColumnSizes = malloc(sizeof(int *) * 10001);
    Queue q;
    QueueInit(&q);
    EnQueue(&q, root);
    while (!QueueIsEmpty(&q)) {
        int cnt = QueueCount(&q);
        ans[*returnSize] = malloc(sizeof(int) * cnt);
        returnColumnSizes[0][*returnSize] = cnt;
        for (int i = 0; i < cnt; i++) {
            struct TreeNode *tmp;
            tmp = DeQueue(&q);
            ans[*returnSize][i] = tmp->val;
            EnQueue(&q, tmp->left);
            EnQueue(&q, tmp->right);
        }
        *returnSize = *returnSize + 1;
    }
    return ans;
}
