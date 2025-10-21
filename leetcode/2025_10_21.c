////3346. 执行操作后元素的最高频率 I
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//void add_item(HashItem** hash, int x, int dx)
//{
//    HashItem* tmp = NULL;
//    HASH_FIND_INT(*hash, &x, tmp);
//    if (tmp == NULL)
//    {
//        tmp = (HashItem*)malloc(sizeof(HashItem));
//        tmp->key = x;
//        tmp->val = dx;
//        HASH_ADD_INT(*hash, key, tmp);
//        //printf("%d %d\n", tmp -> key, tmp -> val);
//    }
//    else
//        tmp->val += dx;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return ((HashItem*)e1)->key - ((HashItem*)e2)->key;
//}
//int maxFrequency(int* nums, int numsSize, int k, int numOperations)
//{
//    HashItem* diff = NULL;
//    HashItem* cnt = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        add_item(&cnt, nums[i], 1);
//        add_item(&diff, nums[i], 0);
//        add_item(&diff, nums[i] - k, 1);
//        add_item(&diff, nums[i] + k + 1, -1);
//    }
//
//    HASH_SORT(diff, cmp);
//
//    int ans = 0, sum_d = 0;
//    HashItem* tmp = NULL;
//    HashItem* p = NULL;
//    HASH_ITER(hh, diff, tmp, p)
//    {
//        sum_d += tmp->val;
//        int limit = numOperations;
//        HashItem* pEntry = NULL;
//        HASH_FIND_INT(cnt, &tmp->key, pEntry);
//        if (pEntry)
//            limit += pEntry->val;
//        ans = fmax(ans, fmin(sum_d, limit));
//        HASH_DEL(diff, tmp);
//        free(tmp);
//    }
//    HASH_ITER(hh, cnt, tmp, p)
//    {
//        HASH_DEL(cnt, tmp);
//        free(tmp);
//    }
//    return ans;
//}
//
////3347. 执行操作后元素的最高频率 II
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxFrequency(int* nums, int numsSize, int k, int numOperations)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0, cnt = 0, left = 0, right = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        cnt++;
//        if (i < numsSize - 1 && x == nums[i + 1])
//            continue;
//        while (nums[left] < x - k)
//            left++;
//        while (right < numsSize && nums[right] <= x + k)
//            right++;
//
//        ans = fmax(ans, fmin(cnt + numOperations, right - left));
//        cnt = 0;
//    }
//
//    if (ans >= numOperations)
//        return ans;
//
//    left = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        while (nums[left] < x - 2 * k)
//            left++;
//
//        ans = fmax(ans, i - left + 1);
//    }
//
//    return fmin(ans, numOperations);
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxFrequency(int* nums, int numsSize, int k, int numOperations)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0, cnt = 0, left = 0, left2 = 0, right = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        //不在数组内的点，滑动窗口，得到在以x为操作的最大元素，在[x - 2 * k, x]范围内最小的元素
//        while (nums[left2] < x - 2 * k)
//            left2++;
//        //不在数组内的点的最高频率为可操作次数
//        ans = fmax(ans, fmin(i - left2 + 1, numOperations));
//
//        //在数组中的点，同向三指针
//        cnt++;
//        //循环到末尾，相同数组值仅增加累计数cnt
//        if (i < numsSize - 1 && x == nums[i + 1])
//            continue;
//
//        //得到最小的在[x - k, x + k]的元素
//        while (nums[left] < x - k)
//            left++;
//
//        //得到最小的不在[x - k, x + k]的元素
//        while (right < numsSize && nums[right] <= x + k)
//            right++;
//
//        ans = fmax(ans, fmin(cnt + numOperations, right - left));
//        cnt = 0;
//    }
//
//    return ans;
//}
//
////343. 整数拆分
//
//int integerBreak(int n)
//{
//    if (n < 4)
//        return n - 1;
//    int div = n / 3;
//    int remainder = n % 3;
//    if (remainder == 1)
//    {
//        div--;
//        remainder = 4;
//    }
//    else if (!remainder)
//        remainder = 1;
//    return pow(3, div) * remainder;
//}
//
////334. 递增的三元子序列
//
//bool increasingTriplet(int* nums, int numsSize)
//{
//    int pre[numsSize], suf[numsSize];
//    pre[0] = nums[0], suf[numsSize - 1] = nums[numsSize - 1];
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        pre[i] = fmin(pre[i - 1], nums[i]);
//    }
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        suf[i] = fmax(suf[i + 1], nums[i]);
//    }
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        if (nums[i] > pre[i] && nums[i] < suf[i])
//            return true;
//    }
//    return false;
//}
//
//bool increasingTriplet(int* nums, int numsSize)
//{
//    if (numsSize < 3)
//        return false;
//    int first = INT_MAX, second = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] <= first)
//            first = nums[i];
//        else if (nums[i] <= second)
//            second = nums[i];
//        else
//            return true;
//    }
//    return false;
//}
//
