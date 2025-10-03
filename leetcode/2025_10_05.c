////3701. 计算交替和
//
//int alternatingSum(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i % 2)
//            ans -= nums[i];
//        else
//            ans += nums[i];
//    }
//    return ans;
//}
//
////3702. 按位异或非零的最长子序列
//
//int longestSubsequence(int* nums, int numsSize)
//{
//    int x = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        x ^= nums[i];
//    }
//    int deduct = 0;
//    if (x == 0)
//    {
//        int left = 0;
//        int right = numsSize - 1;
//        while (left < numsSize && nums[left] == 0)
//            left++;
//        while (right > 0 && nums[right] == 0)
//            right--;
//        deduct = fmin(left, numsSize - 1 - right) + 1;
//    }
//    return numsSize - deduct;
//}
//
////3703. 移除K-平衡子字符串
//
//char* removeSubstring(char* s, int k)
//{
//    int n = strlen(s);
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    strcpy(ans, s);
//    char* st = (char*)malloc(sizeof(char) * (n + 1));
//    while (1)
//    {
//        int top = -1, nums[2] = { 0 };
//        for (int i = 0; i < n; i++)
//        {
//            st[++top] = ans[i];
//            nums[ans[i] - '(']++;
//            if (nums[1] > 0 && (nums[0] < k || ans[i] == '('))
//            {
//                nums[0] = ans[i] == '(';
//                nums[1] = 0;
//            }
//            else if (nums[0] >= k && nums[1] >= k)
//            {
//                top -= 2 * k;
//                nums[0] -= k;
//                nums[1] -= k;
//            }
//            //printf("%d %d %d\n", i, nums[0], nums[1]);
//        }
//        st[++top] = '\0';
//        if (strcmp(st, ans))
//        {
//            strcpy(ans, st);
//            n = top;
//        }
//        else
//            break;
//        //printf("%s\n", ans);
//    }
//    return ans;
//}
//
////1929. 数组串联
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getConcatenation(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize * 2);
//    for (int i = 0; i < 2 * numsSize; i++)
//    {
//        ans[i] = nums[i % numsSize];
//    }
//    *returnSize = 2 * numsSize;
//    return ans;
//}
//
