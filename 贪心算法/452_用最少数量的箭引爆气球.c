// https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/

// my method
int Cmp(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;
    if (a1[0] == b1[0]) {
        return a1[1] - b1[1];
    } else {
        return a1[0] - b1[0];
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a > b ? b : a;
} 
int Match(int** points, int pointsSize, int st)
{
    int ans = st;
    int left = points[ans][0];
    int right = points[ans][1];
    ans++;
    while (ans < pointsSize && left <= right && points[ans][0] <= right) {
        left = max(left, points[ans][0]);
        right = min(right, points[ans][1]);
        ans++;
    }
    return ans;   
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if (pointsSize == 0) {
        return 0;
    }
    qsort(points, pointsSize, sizeof(int *), Cmp);
    int ans = 0;
    int i = 0;
    while (i < pointsSize) {
        ans++;
        i = Match(points, pointsSize, i);
    }
    return ans;
}

// method refer to official method
int Cmp(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;
    return a1[1] - b1[1];
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if (pointsSize == 0) {
        return 0;
    }
    qsort(points, pointsSize, sizeof(int *), Cmp);
    int ans = 1;
    int end = points[0][1];
    for (int i = 0; i < pointsSize; i++) {
        if (points[i][0] > end) {
            ans++;
            end = points[i][1];
        }
    }
    return ans;
}