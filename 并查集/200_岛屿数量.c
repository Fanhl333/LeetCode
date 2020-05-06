#define MAX_SIZE 100001
int g_pre[MAX_SIZE];
int g_count;
int Init(char** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                g_pre[i * (*gridColSize) + j] = i * (*gridColSize) + j;
                count++;
            } else {
                g_pre[i * (*gridColSize) + j] = -1;
            }
        }
    }
    return count;
}

int Find(int x)
{
    int root = x;
    while (g_pre[root] != root) {
        root = g_pre[root];
    }
    return root;
}

void Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY) {
        g_pre[rootX] = rootY;
        g_count--;
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL) {
        return 0;
    }
    g_count = Init(grid, gridSize, gridColSize);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (i > 0 && grid[i - 1][j] == '1' && grid[i][j] == '1') {
                Union((i - 1) * (*gridColSize) + j, i * (*gridColSize) + j);
            }
            if (j > 0 && grid[i][j] == '1' && grid[i][j - 1] == '1') {
                Union(i * (*gridColSize) + j - 1, i * (*gridColSize) + j);
            }            
        }
    }
    return g_count;
}