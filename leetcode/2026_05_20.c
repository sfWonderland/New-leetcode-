//// 面试题 17.08. 马戏团人塔
//
//int lower_bound(int* nums, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int lengthOfLIS(int* nums, int numsSize)
//{
//    int gSize = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int j = lower_bound(nums, gSize, nums[i]);
//        nums[j] = nums[i];
//
//        if (j == gSize)
//            gSize++;
//    }
//    return gSize;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] == (*(int**)e2)[0] ? (*(int**)e2)[1] - (*(int**)e1)[1] : (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int bestSeqAtIndex(int* height, int heightSize, int* weight, int weightSize)
//{
//    int n = heightSize;
//    int** persons = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        persons[i] = (int*)malloc(sizeof(int) * 2);
//        persons[i][0] = height[i];
//        persons[i][1] = weight[i];
//    }
//    qsort(persons, n, sizeof(int*), cmp);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = persons[i][1];
//    }
//    return lengthOfLIS(ans, n);
//}
//
//// 面试题 17.09. 第 k 个数   
//
//int getKthMagicNumber(int k)
//{
//    int f[k];
//    f[0] = 1;
//    int p3 = 0, p5 = 0, p7 = 0;
//    for (int i = 1; i < k; i++)
//    {
//        int x3 = f[p3] * 3;
//        int x5 = f[p5] * 5;
//        int x7 = f[p7] * 7;
//        f[i] = fmin(x3, fmin(x5, x7));
//        if (f[i] == x3)
//            p3++;
//        else if (f[i] == x5)
//            p5++;
//        else
//            p7++;
//        if (f[i] == f[i - 1])
//            i--;
//    }
//    return f[k - 1];
//}
//
//// 面试题 17.10. 主要元素
//
//int majorityElement(int* nums, int numsSize)
//{
//    int ans = nums[0], cnt = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (ans == nums[i])
//            cnt++;
//        else if (cnt > 0)
//            cnt--;
//        else
//        {
//            ans = nums[i];
//            cnt = 1;
//        }
//    }
//    cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (ans == nums[i])
//            cnt++;
//    }
//    return cnt > numsSize / 2 ? ans : -1;
//}
//
//// 面试题 17.11. 单词距离
//
//int findClosest(char** words, int wordsSize, char* word1, char* word2)
//{
//    int p1 = -1, p2 = -1, ans = INT_MAX;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (strcmp(word1, words[i]) == 0)
//            p1 = i;
//        else if (strcmp(word2, words[i]) == 0)
//            p2 = i;
//
//        if (p1 != -1 && p2 != -1)
//            ans = fmin(ans, abs(p1 - p2));
//    }
//    return ans;
//}
//
