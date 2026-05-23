//// 面试题 17.21. 直方图的水量
//
//int trap(int* height, int heightSize)
//{
//    int n = heightSize;
//    int* st = (int*)malloc(sizeof(int) * (n + 1));
//    int top = -1;
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int h = height[i];
//        while (top >= 0 && height[st[top]] <= h)
//        {
//            int bottom_h = height[st[top]];
//            top--;
//            if (top < 0)
//                continue;
//            int left = st[top];
//            int len = i - left - 1;
//            ans += (fmin(h, height[left]) - bottom_h) * len;
//        }
//        st[++top] = i;
//    }
//    return ans;
//}
//
//int trap(int* height, int heightSize)
//{
//    if (heightSize == 0)
//        return 0;
//    int n = heightSize;
//    int pre_max[n], suf_max[n];
//    pre_max[0] = height[0];
//    suf_max[n - 1] = height[n - 1];
//    for (int i = 1; i < n; i++)
//    {
//        pre_max[i] = fmax(pre_max[i - 1], height[i]);
//        suf_max[n - 1 - i] = fmax(suf_max[n - i], height[n - 1 - i]);
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans += fmin(pre_max[i], suf_max[i]) - height[i];
//    }
//    return ans;
//}
//
//int trap(int* height, int heightSize)
//{
//    if (heightSize == 0)
//        return 0;
//    int n = heightSize;
//    int ans = 0, left = 0, suf_max = 0, pre_max = 0, right = n - 1;
//    while (left < right)
//    {
//        pre_max = fmax(pre_max, height[left]);
//        suf_max = fmax(suf_max, height[right]);
//        if (pre_max <= suf_max)
//        {
//            ans += pre_max - height[left];
//            left++;
//        }
//        else
//        {
//            ans += suf_max - height[right];
//            right--;
//        }
//    }
//    return ans;
//}
//
//// 3940. 限制有序数组中的元素出现次数   
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* limitOccurrences(int* nums, int numsSize, int k, int* returnSize)
//{
//    int j = 0, cnt = 0;
//    for (int i = 0; i < numsSize; )
//    {
//        if (i + k - 1 < numsSize && nums[i + k - 1] == nums[i])
//        {
//            // printf("%d ", nums[i]);
//            for (int d = 0; d < k; d++)
//            {
//                nums[j++] = nums[i + d];
//            }
//            while (i < numsSize && nums[i] == nums[j - 1])
//                i++;
//        }
//        else
//        {
//            int x = nums[i];
//            while (i < numsSize && x == nums[i])
//                nums[j++] = nums[i++];
//        }
//    }
//    *returnSize = j;
//    return nums;
//}
//
//// 3941. 密码强度
//
//int passwordStrength(char* password)
//{
//    bool sym[128] = { 0 };
//    int ans = 0;
//    for (int i = 0; password[i]; i++)
//    {
//        if (sym[password[i]])
//            continue;
//        if (password[i] >= 'a')
//            ans++;
//        else if (password[i] >= 'A')
//            ans += 2;
//        else if (password[i] >= '0')
//            ans += password[i] == '@' ? 5 : 3;
//        else
//            ans += 5;
//        sym[password[i]] = true;
//    }
//    return ans;
//}
//
//// 3942. 排序排列的最少操作数
//
//int minOperations(int* nums, int numsSize)
//{
//    if (numsSize == 1)
//        return 0;
//    int cnt = 0;
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        int a = nums[i] - nums[i - 1];
//        int b = nums[i + 1] - nums[i];
//        if (a != b)
//        {
//            if (abs(a) != numsSize - 1 && abs(b) != numsSize - 1)
//                return -1;
//
//            cnt = i + (abs(a) == 1);
//        }
//    }
//    if (abs(nums[0] - nums[numsSize - 1]) == numsSize - 1)
//        return nums[0] == numsSize - 1;
//    return nums[0] > nums[numsSize - 1] ? fmin(cnt, numsSize - cnt + 2) : 1 + fmin(numsSize - cnt, cnt);
//}
//
