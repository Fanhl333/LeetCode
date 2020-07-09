int sumNums[200001];
int subarraySum(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    sumNums[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sumNums[i] = sumNums[i - 1] + nums[i];
    }
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int subSum = sumNums[j] - sumNums[i] + nums[i];
            if (subSum == k) {
                ans++;
            }
        }
    }
    return ans;
}
