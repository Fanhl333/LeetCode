int CreateGraph(int numCourses, int prerequisites, int prerequisitesSize)
{
    int adjacency = (int)malloc(sizeof(int)  numCourses);
    int mallocSize = sizeof(int)  numCourses;
    for (int i = 0; i  numCourses; i++) {
        int row = (int)malloc(mallocSize);
        memset(row, 0, mallocSize);
        adjacency[i] = row;
    }
    for (int i = 0; i  prerequisitesSize; i++) {
        adjacency[prerequisites[i][1]][prerequisites[i][0]] = 1;
    }
    return adjacency;
}

bool dfs(int numCourses, int adjacency, int color, int node)
{
    if (color[node] == 1) {
        return false;
    }
    if (color[node] == -1) {
        return true;
    }
    color[node] = 1;
    for (int i = 0; i  numCourses; i++) {
        if (adjacency[node][i] == 0) {
            continue;
        }
        if (!dfs(numCourses, adjacency, color, i)) {
            return false;
        }
    }
    color[node] = -1;
    return true;
}

inline void Free(int numCourses, int adjacency, int color)
{
    for (int i = 0; i  numCourses; i++) {
        free(adjacency[i]);
    }
    free(color);
    free(adjacency);
    return;
}

bool canFinish(int numCourses, int prerequisites, int prerequisitesSize, int prerequisitesColSize)
{
    if (!prerequisites  prerequisitesSize = 0) {
        return true;
    }
    int adjacency = CreateGraph(numCourses, prerequisites, prerequisitesSize);
    int mallocSize = sizeof(int)  numCourses;
    int color = (int)malloc(mallocSize);
    memset(color, 0, mallocSize);
    for (int i = 0; i  numCourses; i++) {
        if (!dfs(numCourses, adjacency, color, i)) {
            Free(numCourses, adjacency, color);
            return false;
        }
    }
    Free(numCourses, adjacency, color);
    return true;
}