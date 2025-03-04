////1800. 最大升序子数组和
//
//int maxAscendingSum(int* nums, int numsSize)
//{
//    int max = 0;
//    int sum = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] > nums[i - 1])
//            sum += nums[i];
//        else
//        {
//            max = fmax(sum, max);
//            sum = nums[i];
//        }
//    }
//    return fmax(sum, max);
//}
//
////1805. 字符串中不同整数的数目
//
//bool is_num(char s)
//{
//    return s >= '0' && s <= '9';
//}
//int numDifferentIntegers(char* word)
//{
//    int len = strlen(word);
//    int** nums = (int**)malloc(sizeof(int*) * len);
//    for (int i = 0; i < len; i++)
//    {
//        nums[i] = (int*)malloc(sizeof(int) * 2);
//        nums[i][0] = 0;
//        nums[i][1] = 0;
//    }
//    int n = 0;
//    int t = 0;
//    while (t < len)
//    {
//        if (is_num(word[t]))
//        {
//            while (t < len && word[t] == '0')
//                t++;
//            if (0 == is_num(word[t]))
//            {
//                nums[n][0] = t - 1;
//                nums[n++][1] = t - 1;
//                continue;
//            }
//            nums[n][0] = t++;
//            while (t < len && is_num(word[t]))
//                t++;
//            nums[n++][1] = t - 1;
//        }
//        t++;
//    }
//    // for(int i = 0; i < n; i++)
//    // {
//    //     printf("nums[%d][0] = %d, nums[%d][1] = %d\n", i, nums[i][0], i, nums[i][1]);
//    // }
//    int ret = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int j = i + 1;
//        for (; j < n; j++)
//        {
//            int length = fmax(nums[i][1] - nums[i][0], nums[j][1] - nums[j][0]);
//            if (0 == strncmp((word + nums[i][0]), (word + nums[j][0]), length + 1))
//            {
//                //printf("%d %d %d\n", i, j, strncmp((word + nums[i][0]), (word + nums[j][0]), length + 1));
//                break;
//            }
//        }
//        if (j == n)
//            ret++;
//    }
//    return ret;
//}
//
////1827. 最少操作使数组递增
//
//int minOperations(int* nums, int numsSize)
//{
//    int max = 0;
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(nums[i] - i, max);
//        ret += max + i - nums[i];
//    }
//    return ret;
//}
//
////3402. 使每一列严格递增的最少操作次数
//
//int minimumOperations(int** grid, int gridSize, int* gridColSize)
//{
//    int ret = 0;
//    for (int i = 0; i < *gridColSize; i++)
//    {
//        int max = 0;
//        for (int j = 0; j < gridSize; j++)
//        {
//            max = fmax(grid[j][i] - j, max);
//            ret += max + j - grid[j][i];
//        }
//    }
//    return ret;
//}
//
