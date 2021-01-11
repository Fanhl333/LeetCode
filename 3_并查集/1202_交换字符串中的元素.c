// https://leetcode-cn.com/problems/smallest-string-with-swaps/
void UnionFindInit(int *l, int n)  // 并查集初始化
{
    for (int i = 0; i < n; i++) {
        l[i] = i;
    }
}

int Find(int *l, int n, int x)   // 查找x的代表元
{
    int root = x;
    while (root != l[root]) {
        root = l[root];
    }
    int tmp = x;
    while (l[tmp] != root) {
        tmp = l[x];
        l[x] = root;
    }
    return root;
}

void Union(int *l, int n, int x, int y)  // 合并x 与 y
{
    int rootX = Find(l, n, x);
    int rootY = Find(l, n, y);
    if (rootX != rootY) {
        l[rootX] = rootY;
    }
}

char TakeCharFromBucket(int root, int **reBuild, int n)  // 从代表元的bucket里取出字典序最小的char
{
    char ans = '\0';
    int *bucket = reBuild[root];
    for (int i = 0; i < 26; i++) {
        if (bucket[i] > 0) {
            ans = i + 'a';
            bucket[i]--;
            return ans;
        }
    }
    return ans;
}

char *smallestStringWithSwaps(char *s, int **pairs, int pairsSize, int *pairsColSize)
{
    int n = strlen(s);
    int *l = malloc(sizeof(int) * n);
    char *ans = malloc(sizeof(char) * (n + 1));
    UnionFindInit(l, n);   // 并查集初始化
    for (int i = 0; i < pairsSize; i++) {   // 并查集分类
        Union(l, n, pairs[i][0], pairs[i][1]);
    }

    int **bucket = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        bucket[i] = malloc(sizeof(int) * 26);
        memset(bucket[i], 0, sizeof(int) * 26);
    }
    for (int i = 0; i < n; i++) {   // 将对应的元素存入代表元对应的bucket
        bucket[Find(l, n, i)][s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {      // 从代表元的bucket里取出字典序最小的char
        ans[i] = TakeCharFromBucket(Find(l, n, i), bucket, n);
    }
    ans[n] = '\0';

    free(l);
    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
    free(bucket);
 
    return ans;
}