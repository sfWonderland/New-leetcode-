////3638. 平衡装运的最大数量
//
//int maxBalancedShipments(int* weight, int weightSize)
//{
//    int ans = 0, max = 0;
//    for (int i = 0; i < weightSize; i++)
//    {
//        if (max <= weight[i])
//            max = weight[i];
//        else
//        {
//            max = 0;
//            ans++;
//        }
//    }
//    return ans;
//}
//
////1992. 找到所有的农场组
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = landSize, n = landColSize[0];
//    int max = fmax(m * n / 2, 1);
//    int** ans = (int**)malloc(sizeof(int*) * max);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * max);
//    int size = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (land[i][j] == 0 || i > 0 && land[i - 1][j] || j > 0 && land[i][j - 1])
//                continue;
//            ans[size] = (int*)malloc(sizeof(int) * 4);
//            ans[size][0] = i;
//            ans[size][1] = j;
//            int k;
//            for (k = i + 1; k < m && land[k][j]; k++) {}
//            ans[size][2] = k - 1;
//            for (k = j + 1; k < n && land[i][k]; k++) {}
//            ans[size][3] = k - 1;
//            (*returnColumnSizes)[size++] = 4;
//        }
//    }
//    *returnSize = size;
//    return ans;
//}
//
////3147. 从魔法师身上吸取的最大能量
//
//int maximumEnergy(int* energy, int energySize, int k)
//{
//    int ans = INT_MIN;
//    for (int i = 0; i < k; i++)
//    {
//        int sum = energy[i];
//        for (int j = i + k; j < energySize; j += k)
//        {
//            sum = sum > 0 ? sum + energy[j] : energy[j];
//        }
//        ans = fmax(ans, sum);
//    }
//    return ans;
//}
//
////453. 最小操作次数使数组元素相等
//
//int minMoves(int* nums, int numsSize)
//{
//    int min = INT_MAX;
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        min = fmin(min, nums[i]);
//    }
//    return sum - min * numsSize;
//}
//
