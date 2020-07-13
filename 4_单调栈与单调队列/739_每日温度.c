/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
 //暴力破解法超时
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *ret;
    if (TSize == NULL || TSize == 0) {
        return NULL;
    }
    ret = malloc(sizeof(int) * TSize);
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(int) * TSize);
    int i, j;
    for (i = 0; i < TSize - 1; i++) {
        for (j = i + 1; j < TSize; j++) {
            if (T[i] < T[j]) {
                ret[i] = j - i;
                break;
            }
        }
    }
    *returnSize = TSize;
    return ret;
}
*/
typedef struct Stack {
    int data[30000];
    int top;
} Stack;

void IniteStack(Stack *s)
{
    memset(s->data, 0, sizeof(s->data));
    s->top = -1;
}

bool IsEmptyStack(Stack *s)
{
    return s->top == -1;
}
bool IsFullStack(Stack *s)
{
    return s->top == 29999;
}
void StackPush(Stack *s, int value)
{   
    s->top++;
    s->data[s->top] = value;
}
int StackPop(Stack *s)
{   
    int ret;
    ret = s->data[s->top];
    s->top--;
    return ret;
}

int StackTop(Stack *s)
{   
    return s->data[s->top];
}


int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *ret;
    Stack s;
    IniteStack(&s);
    if (TSize == NULL || TSize == 0) {
        return NULL;
    }
    ret = malloc(sizeof(int) * TSize);
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(int) * TSize);
    int j;
    for (int i = 0; i < TSize; i++) {
        while (!IsEmptyStack(&s) && T[StackTop(&s)] < T[i]) {
            j = StackPop(&s);
            ret[j] = i - j;
        }
        StackPush(&s, i);
    }

    *returnSize = TSize;
    return ret;
}
