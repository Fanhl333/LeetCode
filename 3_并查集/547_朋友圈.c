int frends[10001];
int Find(int x)
{
    int root = x;
    while (frends[root] != root) {
        root = frends[root];
    }
    int tmp;
    while (frends[x] != root) {
        tmp = frends[x];
        frends[x] = root;
        x = tmp;
    }
    return root;
}

void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot != yRoot) {
        frends[xRoot] = yRoot;
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    for (int i = 0; i < MSize; i++) {
        frends[i] = i;
    }

    for (int i = 0; i < MSize; i++) {
        for (int j = i; j < MSize; j++) {
            if (M[i][j] == 1) {
                Union(i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < MSize; i++) {
        if (i == frends[i]) {
            count++;
        }
    }
    return count;
}