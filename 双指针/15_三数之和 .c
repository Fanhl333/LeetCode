/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// https://leetcode-cn.com/problems/3sum/
int Cmp (const void * a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret = malloc( sizeof(int *) * (numsSize * 6));
    returnColumnSizes[0] = malloc(sizeof(int) * (numsSize * 6));
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), Cmp);
    int left, right, target;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > 0 || nums[numsSize - 1] < 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        left = i + 1;
        right = numsSize - 1;
        while (left < right) {
            target = nums[i] + nums[left] + nums[right];
            if (target > 0) {
                right--;
            } else if (target < 0) {
                left++;
            } else {
                ret[*returnSize] = (int *)malloc(3 * sizeof(int));
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                returnColumnSizes[0][*returnSize] = 3;
                *returnSize += 1;
                while (left < right && nums[left] == nums[++left]) { }
                while (left < right && nums[right] == nums[--right]) { }
            }
        }
    }
    return ret;
}