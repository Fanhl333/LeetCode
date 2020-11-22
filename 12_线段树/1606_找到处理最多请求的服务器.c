#define MAX_SIZE 100001
struct Node {
    int l;
    int r;
    int mn;
} g_tree[MAX_SIZE * 4];

int Min(int a, int b)
{
    return a > b ? b : a;
}

void PushUp(int node)
{
    g_tree[node].mn = Min(g_tree[2 * node].mn, g_tree[2 * node + 1].mn);
}

void Build(int node, int l, int r)
{
    g_tree[node].l = l;
    g_tree[node].r = r;
    if (l == r) {
        g_tree[node].mn = 0;
        return;
    }
    int mid = (l + r) / 2;
    Build(2 * node, l, mid);
    Build(2 * node + 1, mid + 1, r);
    PushUp(node);
}

void Update(int node, int x, int val)
{
    if (g_tree[node].l == g_tree[node].r) {
        g_tree[node].mn = val;
        return;
    }
    int mid = (g_tree[node].l + g_tree[node].r) / 2;
    if (x <= mid) {
        Update(2 * node, x, val);
    } else {
        Update(2 * node + 1, x, val);
    }
    PushUp(node);
}

int RequirePos(int node, int l, int r, int val)
{
    if (g_tree[node].l == g_tree[node].r) {
        if (g_tree[node].mn <= val) {
            return g_tree[node].l;
        } else {
            return -1;
        }
    }
    if (g_tree[node].l >= l && g_tree[node].r <= r) {
        if (g_tree[node].mn > val) {
            return -1;
        }
    }
    int mid = (g_tree[node].l + g_tree[node].r) / 2;
    if (r <= mid) {
        return RequirePos(2 * node, l, r, val);
    } else if (l > mid) {
        return RequirePos(2 * node + 1, l, r, val); 
    }
    int tmp = RequirePos(2 * node, l, mid, val);
    if (tmp != -1) {
        return tmp;
    } else {
        return RequirePos(2 * node + 1, mid + 1, r, val);
    }
}

int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize){
    int *res = (int *)malloc(k * sizeof(int));
    int i;
    int max = 0;
    int cnt = 0;
    memset(res, 0, k * sizeof(int));
    Build(1, 0, k - 1);
    for (i = 0; i < arrivalSize; i++) {
        if ((i % k) <= (k - 1)) {
            int pos1 = RequirePos(1, i % k, k - 1, arrival[i]);
            if (pos1 >= 0 && pos1 < k) {
                res[pos1]++;
                if (res[pos1] > max) {
                    max = res[pos1];
                }
                Update(1, pos1, arrival[i] + load[i]);
                continue;
            }
        }
        if((i % k) - 1 >= 0){
            int pos2 = RequirePos(1,0,i % k - 1,arrival[i]);
            if (pos2 >= 0 && pos2 < k) {
                res[pos2]++;
                if (res[pos2] > max) {
                    max = res[pos2];
                }
                Update(1, pos2, arrival[i] + load[i]);
                continue;
            }
        }
    }

    for (i = 0; i < k; i++) {
        if (res[i] == max) {
            cnt++;
        }
    }
    int *ans = (int *)malloc(cnt * sizeof(int));
    int j = 0;
    for (i = 0; i < k; i++) {
        if (res[i] == max) {
            ans[j] = i;
            j++;
        }
    }
    returnSize[0] = cnt;
    free(res);
    return ans;
}