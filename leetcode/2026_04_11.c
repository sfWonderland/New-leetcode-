////LCR 007. 三数之和
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
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = numsSize;
//    qsort(nums, n, sizeof(int), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * n * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n * n);
//    int idx = 0;
//    for (int i = 0; i < n - 2; i++)
//    {
//        if (i > 0 && nums[i] == nums[i - 1]) continue;
//        if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
//        if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;
//        int left = i + 1, right = n - 1;
//        while (left < right)
//        {
//            int sum = nums[i] + nums[left] + nums[right];
//            if (sum < 0)
//                left++;
//            else if (sum > 0)
//                right--;
//            else
//            {
//                ans[idx] = (int*)malloc(sizeof(int) * 3);
//                ans[idx][0] = nums[i], ans[idx][1] = nums[left], ans[idx][2] = nums[right];
//                (*returnColumnSizes)[idx++] = 3;
//
//                for (left++; left < right && nums[left] == nums[left - 1]; left++);
//                for (right--; left < right && nums[right] == nums[right + 1]; right--);
//            }
//        }
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////LCR 008. 长度最小的子数组    
//
//int minSubArrayLen(int target, int* nums, int numsSize)
//{
//    int n = numsSize;
//    int left = 0, sum = 0, ans = INT_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        sum += nums[i];
//        if (sum < target)
//            continue;
//
//        while (sum >= target)
//        {
//            sum -= nums[left++];
//        }
//        ans = fmin(ans, i - left + 2);
//    }
//    return ans == INT_MAX ? 0 : ans;
//}
//
////LCR 009. 乘积小于 K 的子数组
//
//int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int left = 0, multi = 1, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        multi *= nums[i];
//        ans += i - left;
//        while (left <= i && multi >= k)
//        {
//            multi /= nums[left++];
//        }
//    }
//    ans += n - left;
//    return ans;
//}
//
////LCR 010. 和为 K 的子数组
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int subarraySum(int* nums, int numsSize, int k)
//{
//    // 正数负数都有，不能用滑动窗口
//    int n = numsSize;
//    int suf[n + 1];
//    suf[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        suf[i + 1] = suf[i] + nums[i];
//    }
//    int ans = 0;
//    HashItem* cnt = NULL;
//    HashItem* p = (HashItem*)malloc(sizeof(HashItem));
//    p->key = suf[0];
//    p->val = 1;
//    HASH_ADD_INT(cnt, key, p);
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = suf[i + 1] - k;
//        HASH_FIND_INT(cnt, &x, p);
//        if (p) ans += p->val;
//
//        HASH_FIND_INT(cnt, &suf[i + 1], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = suf[i + 1];
//            p->val = 0;
//            HASH_ADD_INT(cnt, key, p);
//        }
//        p->val++;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    return ans;
//}
//
