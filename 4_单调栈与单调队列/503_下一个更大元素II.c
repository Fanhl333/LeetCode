/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Stack {
    int data[10000];
    int top;
} Stack;

void IniteStack(Stack *s)
{
    s->top = -1;
}

bool IsEmpty(Stack *s)
{
    return s->top == -1;
}

bool IsFull(Stack *s)
{
    return s->top == sizeof(s->data) / sizeof(int) - 1;
}

int StackTop(Stack *s)
{
    if (!IsEmpty(s)) {
        return s->data[s->top];
    } else {
        return -1;
    }   
}

int StackPop(Stack *s)
{
    if (!IsEmpty(s)) {
        return s->data[s->top--];
    } else {
        return -1;
    }   
}

void StackPush(Stack *s, int val)
{
    if (!IsFull(s)) {
        s->top++;
        s->data[s->top] = val;
    }
}
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *ret = malloc(numsSize * sizeof(int));
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, -1, numsSize * sizeof(int));
    Stack s;
    IniteStack(&s);
    for (int i = 0; i < numsSize; i++) {
        while (!IsEmpty(&s) && nums[StackTop(&s)] < nums[i]) {
            int k = StackPop(&s);
            ret[k] = nums[i];
        }
        StackPush(&s, i);
    }

    for (int i = 0; i < numsSize; i++) {
        while (!IsEmpty(&s) && nums[StackTop(&s)] < nums[i]) { 
            int k = StackPop(&s);
            if (ret[k] == -1) {
                 ret[k] = nums[i];
            }
        }
        StackPush(&s, i);
    }    

    *returnSize = numsSize;
    return ret;
}
