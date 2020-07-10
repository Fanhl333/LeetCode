/* 
// methon:前缀和 -- 超时
int subarraysDivByK(int* A, int ASize, int K){
    int s[30001] = {0};
    s[0] = A[0];
    for (int i = 1; i < ASize; i++) {
        s[i] = A[i] + s[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < ASize; i++) {
        for (int j = i; j < ASize; j++) {
            int subSum = s[j] - s[i] + A[i];
            if (subSum % K == 0) {
                ans++;
            }
        }
    }
    return ans;
}
*/
// methon:前缀和 + hash
int subarraysDivByK(int* A, int ASize, int K){
    int map[10001] = {0};
    map[0] = 1;
    int preSum = 0;
    int ans = 0;
    for (int i = 0; i < ASize; i++) {
        preSum = preSum + A[i];
        int key = preSum % K;
        if (key < 0) {
            key += K;
        }
        ans += map[key];
        map[key]++;
    }
    return ans;
}
