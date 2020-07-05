/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *ret = malloc(sizeof(int) * n);
    if (ret == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(ret, 0, sizeof(int) * n);
    for (int i = 0; i < bookingsSize; i++) {
        ret[bookings[i][0] - 1] = ret[bookings[i][0] - 1] + bookings[i][2];
        if (bookings[i][1] < n) {
            ret[bookings[i][1]] = ret[bookings[i][1]] - bookings[i][2];
        }
    }
    for (int i = 1; i < n; i++) {
        ret[i] = ret[i - 1] + ret[i];
    }
    *returnSize = n;
    return ret;
}