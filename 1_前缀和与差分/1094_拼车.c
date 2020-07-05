bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    if (trips == NULL || capacity <= 0) {
        return false;
    }
    int diff[1001] = {0};
    int maxLen = 0;
    for (int i = 0; i < tripsSize; i++) {
        diff[trips[i][1]] += trips[i][0];
        diff[trips[i][2]] -= trips[i][0];
        if (trips[i][2] > maxLen) {
            maxLen = trips[i][2];
        }
    }
    for (int i = 1; i <= maxLen; i++) {
        diff[i] = diff[i] + diff[i - 1];
        if (diff[i] > capacity) {
            return false;
        }
    }
    return true;  
}