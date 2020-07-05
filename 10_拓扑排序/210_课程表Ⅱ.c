/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_QUEQUE_SIZE 2001
typedef struct Queue_ {
    int head;
    int tail;
    int data[MAX_QUEQUE_SIZE];
} queue;

void queueInit(queue *obj)
{
    obj->head = 0;
    obj->tail = 0;  
}
bool isEmpty(queue *obj)
{
    return obj->head == obj->tail;
}
bool isFull(queue *obj)
{
    return (obj->tail + 1) % MAX_QUEQUE_SIZE == obj->head;
}
void enQueue(queue *obj, int val)
{
    if (isFull(obj)) {
        printf("queue is full.\n");
        return;
    }
    obj->data[obj->tail] = val;
    obj->tail = (obj->tail + 1) % MAX_QUEQUE_SIZE;
}
int deQueue(queue *obj)
{
    if (isEmpty(obj)) {
        printf("queue is empty.\n");
        return -1;
    }
    return obj->data[obj->head++];
}
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int ingress[MAX_QUEQUE_SIZE];
    for (int i = 0; i < numCourses; i++) {
        ingress[i] = 0;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        ingress[prerequisites[i][0]]++;
    }
    queue q;
    int top = 0;
    int *ans = malloc(sizeof(int) * numCourses);
    if (ans == NULL) {
        // error process
        return;
    }
    queueInit(&q);
    for (int i = 0; i < numCourses; i++) {
        if (ingress[i] == 0) {
            enQueue(&q, i);
        }
    }
    while (!isEmpty(&q)) {
        ans[top++] = deQueue(&q);
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == ans[top - 1]) {
                ingress[prerequisites[i][0]]--;
                if (ingress[prerequisites[i][0]] == 0) {
                    enQueue(&q, prerequisites[i][0]);
                }
            }
        }
    }
    if (top != numCourses) {
        *returnSize = 0;
        free(ans);
        return NULL;
    }
    *returnSize = numCourses;
    return ans;
}