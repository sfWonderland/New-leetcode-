////3356. 零数组变换 II
//
//int minZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize)
//{
//    int zero = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        zero |= nums[i];
//    }
//    if (zero == 0)
//        return 0;
//    int left = 0, right = queriesSize - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        int hash[numsSize + 1];
//        for (int i = 0; i <= numsSize; i++)
//        {
//            hash[i] = 0;
//        }
//        for (int i = 0; i <= mid; i++)
//        {
//            int l = queries[i][0], r = queries[i][1];
//            hash[l] += queries[i][2];
//            hash[r + 1] -= queries[i][2];
//        }
//
//        int check[numsSize + 1];
//        check[0] = hash[0];
//        for (int j = 1; j < numsSize; j++)
//        {
//            check[j] = check[j - 1] + hash[j];
//        }
//
//        int flag = 0;
//        for (int i = 0; i < numsSize; i++)
//        {
//            if (check[i] < nums[i])
//            {
//                flag = 1;
//                break;
//            }
//        }
//
//        if (flag == 0)
//            right = mid - 1;
//        else
//            left = mid + 1;
//
//        //printf("%d %d\n", left, right);
//    }
//
//    return left == queriesSize ? -1 : left + 1;
//}
//
////1313. 解压缩编码列表
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* decompressRLElist(int* nums, int numsSize, int* returnSize)
//{
//    int n = 0;
//    for (int i = 0; i < numsSize; i += 2)
//    {
//        n += nums[i];
//    }
//    int* ans = (int*)calloc(n, sizeof(int));
//    n = 0;
//    for (int i = 0; i < numsSize; i += 2)
//    {
//        int t = nums[i];
//        while (t)
//        {
//            ans[n++] = nums[i + 1];
//            t--;
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////1689. 十-二进制数的最少数目
//
//int minPartitions(char* n)
//{
//    int max = 0;
//    for (int i = 0; n[i]; i++)
//    {
//        max = fmax(n[i], max);
//        if (max == '9')
//            return 9;
//    }
//    return max - '0';
//}
//
////1769. 移动所有球到每个盒子所需的最小操作数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minOperations(char* boxes, int* returnSize)
//{
//    int left = boxes[0] - '0', right = 0, operations = 0;
//    int n = strlen(boxes);
//    for (int i = 1; i < n; i++)
//    {
//        if (boxes[i] == '1')
//        {
//            right++;
//            operations += i;
//        }
//    }
//    int* ans = (int*)calloc(n, sizeof(int));
//    ans[0] = operations;
//    for (int i = 1; i < n; i++)
//    {
//        operations += left - right;
//        if (boxes[i] == '1')
//        {
//            left++; right--;
//        }
//        ans[i] = operations;
//    }
//    *returnSize = n;
//    return ans;
//}
//
