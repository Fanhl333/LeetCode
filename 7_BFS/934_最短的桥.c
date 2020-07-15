typedef struct Point_ {
    int x;
    int y;
} Point;

int g_direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void findstartpoint(int** A, int ASize, int AColSize, Point *p)
{
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < AColSize; j++) {
            if (A[i][j] == 1) {
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
    return;
}

void dfs(int** A, int ASize, int AColSize, int x, int y)
{
    if (x < 0 || x >= ASize || y < 0 || y >= AColSize) {
        return;
    }
    if (A[x][y] != 1) {
        return;
    }
    A[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int dx = x + g_direction[i][0];
        int dy = y + g_direction[i][1];
        dfs(A, ASize, AColSize, dx, dy);

    }
    return;
}

int shortestBridge(int** A, int ASize, int* AColSize)
{
    int ans = 0;
    Point startP;
    findstartpoint(A, ASize, *AColSize, &startP);
    dfs(A, ASize, *AColSize, startP.x, startP.y);
    // 模拟队列
    int head = 0;
    int tail = 0;
    Point *q = malloc(sizeof(Point) * ASize * (*AColSize) + 2);
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < *AColSize; j++) {
            if (A[i][j] == 2) {
                q[tail].x = i;
                q[tail].y = j;
                tail++;
            }
        }
    }

    while (head < tail) {
        int tmp_head = head;
        int tmp_tail = tail;
        for (int i = tmp_head; i < tmp_tail; i++) {
            Point *tmpPoint = &q[i];
            for (int j = 0; j < 4; j++) {
                int dx = tmpPoint->x + g_direction[j][0];
                int dy = tmpPoint->y + g_direction[j][1];
                if (dx < 0 || dx >= ASize || dy < 0 || dy >= *AColSize) {
                    continue;
                }
                if (A[dx][dy] == 2) {
                    continue;
                }
                if (A[dx][dy] == 1) {
                    return ans;
                }
                q[tail].x = dx;
                q[tail].y = dy;
                tail++;
                A[dx][dy] = 2;
            }
        }
        head = tmp_tail;
        ans++;
    }
    free(q);
    return ans;
}
