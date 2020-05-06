char **g_grid;
int g_gridSize;
int g_gridColSize;
int g_m[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Init(char** grid, int gridSize, int* gridColSize)
{
    g_grid = grid;
    g_gridSize = gridSize;
    g_gridColSize = *gridColSize;
}

bool IsValid(int x, int y)
{
    if (x < 0 || x >= g_gridSize || y < 0 || y >= g_gridColSize) {
        return false;
    }

    if (g_grid[x][y] != '1') {
        return false;
    }

    return true;
}
void dfs(int x, int y)
{
    g_grid[x][y] = '0';
    for (int i = 0; i < 4; i++) {
        int dx = x + g_m[i][0];
        int dy = y + g_m[i][1];
        if (IsValid(dx, dy)) {
            dfs(dx, dy);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || *gridColSize == 0) {
        return 0;
    }
    Init(grid, gridSize, gridColSize);
    int numLands = 0;
    for (int i = 0; i < g_gridSize; i++) {
        for(int j = 0; j < g_gridColSize; j++) {
            if (g_grid[i][j] == '1') {
                dfs(i, j);
                numLands++;
            }
        }
    }
    return numLands;
}