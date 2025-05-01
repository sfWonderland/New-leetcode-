////2841. 几乎唯一子数组的最大和
//
//long long maxSum(int* nums, int numsSize, int m, int k)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, nums[i]);
//    }
//    int* hash = (int*)calloc(max + 1, sizeof(int));
//    long long ans = 0, sum = 0;
//    int diff = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        diff += (hash[nums[i]] == 0);
//        ++hash[nums[i]];
//        sum += nums[i];
//        if (i < k - 1)
//            continue;
//
//        ans = diff >= m ? fmax(ans, sum) : ans;
//        sum -= nums[i - k + 1];
//        --hash[nums[i - k + 1]];
//        diff -= (hash[nums[i - k + 1]] == 0);
//    }
//    free(hash);
//    return ans;
//}
//
//
//
////1652. 拆炸弹(re)
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* decrypt(int* code, int codeSize, int k, int* returnSize)
//{
//    int* ret = (int*)calloc(codeSize, sizeof(int));
//    if (k)
//    {
//        int sum = 0;
//        int t = abs(k);
//        for (int i = 0; i < codeSize + t - 1; i++)
//        {
//            sum += code[i % codeSize];
//            if (i < t - 1)
//                continue;
//
//            int index = k > 0 ? (codeSize + i - t) % codeSize : (i + 1) % codeSize;
//            ret[index] = sum;
//            //printf("%d", i - t + 1);
//            sum -= code[i - t + 1];
//        }
//    }
//    *returnSize = codeSize;
//    return ret;
//}
//
////838. 推多米诺
//
//char* pushDominoes(char* dominoes)
//{
//    int n = strlen(dominoes);
//    int pre = -1;
//    for (int i = 0; i <= n; ++i)
//    {
//        char ch = i < n ? dominoes[i] : 'R';
//        if (ch == '.')
//            continue;
//
//        if (ch == (pre < 0 ? 'L' : dominoes[pre]))
//        {
//            for (int j = pre + 1; j < i; j++)
//            {
//                dominoes[j] = ch;
//            }
//        }
//        else if (ch == 'L')
//        {
//            int left = pre + 1;
//            int right = i - 1;
//            while (left < right)
//            {
//                dominoes[left++] = 'R';
//                dominoes[right--] = 'L';
//            }
//        }
//        pre = i;
//    }
//    return dominoes;
//}
//
////2134. 最少交换次数来组合所有的 1 II
//
//int minSwaps(int* nums, int numsSize)
//{
//    int k = 0;
//    for (int i = 0; i < numsSize; ++i)
//    {
//        k += nums[i];
//    }
//    int ans = k, sum = 0;
//    for (int i = 0; i < numsSize + k - 1; ++i)
//    {
//        sum += (nums[i % numsSize] == 0);
//        if (i < k - 1)
//            continue;
//
//        ans = fmin(ans, sum);
//        sum -= (nums[(numsSize + i - k + 1) % numsSize] == 0);
//    }
//    return ans;
//}
//
