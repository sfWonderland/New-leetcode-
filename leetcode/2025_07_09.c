////LCR 079. 子集
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = 1 << numsSize;
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    *returnSize = n;
//    int sub[numsSize];
//    for (int i = 0; i < n; i++)
//    {
//        int m = 0;
//        ans[i] = (int*)malloc(sizeof(int) * i);
//        for (int j = 0; j < numsSize; j++)
//        {
//            if (i & (1 << j))
//                ans[i][m++] = nums[j];
//        }
//        (*returnColumnSizes)[i] = m;
//    }
//    return ans;
//}
//
////LCR 178. 训练计划 VI
//
//int trainingPlan(int* actions, int actionsSize)
//{
//    int arr[32] = { 0 };
//    for (int i = 0; i < actionsSize; i++)
//    {
//        int m = 0;
//        while (actions[i])
//        {
//            arr[m++] += actions[i] & 1;
//            actions[i] >>= 1;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        ans += (arr[i] % 3) << i;
//    }
//    return ans;
//}
//
////2544. 交替数字和
//
//int alternateDigitSum(int n)
//{
//    int flag = 1, ans = 0;
//    while (n)
//    {
//        ans += flag * (n % 10);
//        n /= 10;
//        flag = -flag;
//    }
//    if (flag == 1)
//        ans = -ans;
//
//    return ans;
//}
//
////2848. 与车相交的点
//
//int numberOfPoints(int** nums, int numsSize, int* numsColSize)
//{
//    int points[102] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        points[nums[i][0]]++;
//        points[nums[i][1] + 1]--;
//    }
//    int sum = 0, ans = 0;
//    for (int i = 1; i < 101; i++)
//    {
//        sum += points[i];
//        ans += sum > 0;
//    }
//    return ans;
//}
//
