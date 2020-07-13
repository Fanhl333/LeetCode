/* 分治法超时 
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int f(int* heights, int left, int right)
{
    if (left > right) {
        return 0;
    }
    int minHeight = INT_MAX;
    int index = left;
    for (int i = left; i <= right; i++) {
        if (heights[i] < minHeight) {
            minHeight = heights[i];
            index = i;   // 重要
        }
    }
    int mid = (left + right) / 2;
    int curRet = minHeight * (right - left + 1);
    int fRet = MAX(f(heights, left, index - 1), f(heights, index + 1, right));
    return MAX(curRet, fRet);
}
int largestRectangleArea(int* heights, int heightsSize){
    return f(heights, 0, heightsSize - 1);
}
*/
typedef struct Stack {
    int data[50001];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

bool IsEmpty(Stack *s)
{
    return s->top == -1;
}

void StackPush(Stack *s, int val)
{
    s->top++;
    s->data[s->top] = val;
}

int StackTop(Stack *s)
{
    return s->data[s->top];
}

int StackPop(Stack *s)
{
    int ret = s->data[s->top];
    s->top--;
    return ret;
}

int largestRectangleArea(int* heights, int heightsSize){
    int maxArea = 0;
    int top;
    Stack s;
    InitStack(&s);
    for (int i = 0; i < heightsSize; i++) {
        top = i;
        while (!IsEmpty(&s) && heights[StackTop(&s)] > heights[i]) {
            top = StackPop(&s);
            if ((i - top) * heights[top] > maxArea) {
                maxArea = (i - top) * heights[top];
            }
        }
        heights[top] = heights[i];
        StackPush(&s, top);
    }
    while (!IsEmpty(&s) && heights[StackTop(&s)] > 0) {
        top = StackPop(&s);
        if ((heightsSize - top) * heights[top] > maxArea) {
            maxArea = (heightsSize - top) * heights[top];
        }
    }
    return maxArea;
}
