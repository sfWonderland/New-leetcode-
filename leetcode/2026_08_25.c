//// 4030. 判断 ASCII 值回文
//
//char reverse(char c)
//{
//    char res = 0, t = 8;
//    while (t--)
//    {
//        res <<= 1;
//        res += (c & 1);
//        c >>= 1;
//    }
//    return res;
//}
//bool isPalindromic(char* s)
//{
//    int n = strlen(s);
//    if (n & 1)
//    {
//        int l = 0, r = 7;
//        int x = s[n / 2];
//        while (l < r)
//        {
//            int a = (x >> l) & 1;
//            int b = (x >> r) & 1;
//            if (a != b) return false;
//            l++; r--;
//        }
//    }
//    int left = 0, right = n - 1;
//    while (left < right)
//    {
//        char x = reverse(s[left++]);
//        if (x != s[right--])
//            return false;
//    }
//    return true;
//}
//
//char reverse(char c)
//{
//    char res = 0, t = 8;
//    while (t--)
//    {
//        res <<= 1;
//        res += (c & 1);
//        c >>= 1;
//    }
//    return res;
//}
//bool isPalindromic(char* s)
//{
//    int n = strlen(s);
//    if (n & 1)
//    {
//        int l = 0, r = 7;
//        int x = s[n / 2];
//        while (l < r)
//        {
//            int a = (x >> l) & 1;
//            int b = (x >> r) & 1;
//            if (a != b) return false;
//            l++; r--;
//        }
//    }
//    int left = 0, right = n - 1;
//    while (left < right)
//    {
//        char x = s[left++];
//        char y = s[right--];
//        if (((x & 0x67) != 0x66) || ((y & 0x67) != 0x66))
//            return false;
//        // printf("%x %x\n", x & 0x67, y & 0x67);
//        // printf("%d %d\n", (x >> 4) & 1, (y >> 3) & 1);
//        if (((x >> 4) & 1) != ((y >> 3) & 1) || ((x >> 3) & 1) != ((y >> 4) & 1))
//            return false;
//    }
//    return true;
//}
//
//// 4031. 找到所有数组中消失的数字 II
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int** findDisappearedNumbers(int* nums, int numsSize, int lower, int upper, int* returnSize, int** returnColumnSizes)
//{
//    int n = numsSize;
//    qsort(nums, n, sizeof(int), cmp);
//    int capacity = 8;
//    int** ans = (int**)malloc(sizeof(int*) * capacity);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
//    *returnSize = 0;
//    for (int i = 0; i < n && lower <= upper; i++)
//    {
//        if (nums[i] < lower)
//            continue;
//        else if (nums[i] == lower)
//            lower++;
//        else
//        {
//            ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
//            ans[*returnSize][0] = lower;
//            ans[*returnSize][1] = fmin(nums[i] - 1, upper);
//            (*returnColumnSizes)[(*returnSize)++] = 2;
//            if (*returnSize >= capacity)
//            {
//                capacity *= 2;
//                ans = (int**)realloc(ans, sizeof(int*) * capacity);
//                *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
//            }
//            lower = nums[i] + 1;
//        }
//    }
//    if (lower <= upper)
//    {
//        ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
//        ans[*returnSize][0] = lower;
//        ans[*returnSize][1] = upper;
//        (*returnColumnSizes)[(*returnSize)++] = 2;
//        if (*returnSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (int**)realloc(ans, sizeof(int*) * capacity);
//            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
//        }
//    }
//    return ans;
//}
//
//// 4032. 至多 K 个不同质因数集合的最长子数组
//
//int longestSubarray(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    // 预处理质数
//    int mx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        mx = fmax(mx, nums[i]);
//    }
//    mx++;
//    int* prime_factors[mx];
//    int len[mx];
//    int capacity[mx];
//    memset(prime_factors, 0, sizeof(prime_factors));
//    memset(len, 0, sizeof(len));
//    for (int i = 2; i < mx; i++)
//    {
//        if (len[i]) continue;
//        for (int j = i; j < mx; j += i)
//        {
//            if (!len[j])
//            {
//                capacity[j] = 8;
//                prime_factors[j] = (int*)malloc(sizeof(int) * capacity[j]);
//            }
//            prime_factors[j][len[j]++] = i;
//            if (len[j] == capacity[j])
//            {
//                capacity[j] *= 2;
//                prime_factors[j] = (int*)realloc(prime_factors[j], sizeof(int) * capacity[j]);
//            }
//        }
//    }
//    // 滑动窗口
//    int cnt[mx];
//    memset(cnt, 0, sizeof(cnt));
//    int ans = 0, left = 0, cntSize = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int x = nums[i];
//        for (int j = 0; j < len[x]; j++)
//        {
//            int p = prime_factors[x][j];
//            if (cnt[p] == 0) cntSize++;
//            cnt[p]++;
//        }
//        while (cntSize > k)
//        {
//            int y = nums[left];
//            for (int j = 0; j < len[y]; j++)
//            {
//                int p = prime_factors[y][j];
//                cnt[p]--;
//                if (cnt[p] == 0) cntSize--;
//            }
//            left++;
//        }
//        ans = fmax(ans, i - left + 1);
//    }
//    return ans;
//}
//
