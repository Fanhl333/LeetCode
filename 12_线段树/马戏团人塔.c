logo
探索
题库
圈子
竞赛
面试
职位
商店
0


马戏团人塔
提交记录
43 / 43 个通过测试用例
状态：通过
执行用时: 116 ms
内存消耗: 12.1 MB
提交时间：8 天前
执行用时分布图表
执行消耗内存分布图表
邀请好友来挑战 马戏团人塔
提交的代码： 8 天前
语言： c


typedef struct _ManInfo {
    int height;
    int weight;
} ManInfo;

int CmpFuc(const void *a, const void *b)
{
    ManInfo *manA = (ManInfo *)a;
    ManInfo *manB = (ManInfo *)b;
    if (manA->height == manB->height) {
        return manB->weight - manA->weight;
    }
    return manA->height - manB->height;
}

int BSearch(int *dp, int dpLen, int left, int right, int aim)
{
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(dp[mid] >= aim) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;                                  //目标值的位置
}

int bestSeqAtIndex(int* height, int heightSize, int* weight, int weightSize){
    if (heightSize == 0) {
        return 0;
    }
    int ans = 1;
    ManInfo *manInfos = malloc(sizeof(ManInfo) * heightSize);
    for (int i = 0; i < heightSize; i++) {
        manInfos[i].height = height[i];
        manInfos[i].weight = weight[i];
    }
    qsort(manInfos, heightSize, sizeof(ManInfo), CmpFuc);
    int *dp = malloc(sizeof(int) * (heightSize + 1));
    dp[1] = manInfos[0].weight;
    for (int i = 1; i < heightSize; i++) {
        if (manInfos[i].weight > dp[ans]) {
            ans++;
            dp[ans] = manInfos[i].weight;
        } else {
            int idx = BSearch(dp, heightSize + 1, 1, ans, manInfos[i].weight);
            dp[idx] = manInfos[i].weight;
        }
    }
    return ans;
}