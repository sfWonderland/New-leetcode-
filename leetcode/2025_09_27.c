////525. 连续数组
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int findMaxLength(int* nums, int numsSize)
//{
//    HashItem* hash = NULL;
//    HashItem* tmp = (HashItem*)malloc(sizeof(HashItem));
//    tmp->key = 0;
//    tmp->val = -1;
//    HASH_ADD_INT(hash, key, tmp);
//    int sum = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i] ? 1 : -1;
//        HASH_FIND_INT(hash, &sum, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (HashItem*)malloc(sizeof(HashItem));
//            tmp->key = sum;
//            tmp->val = i;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else
//            ans = fmax(ans, i - tmp->val);
//    }
//    HashItem* s = NULL;
//    HASH_ITER(hh, hash, tmp, s)
//    {
//        HASH_DEL(hash, tmp);
//        free(tmp);
//    }
//    return ans;
//}
//
////面试题 17.05. 字母与数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//char** findLongestSubarray(char** array, int arraySize, int* returnSize)
//{
//    HashItem* hash = NULL;
//    HashItem* tmp = (HashItem*)malloc(sizeof(HashItem));
//    tmp->key = 0;
//    tmp->val = -1;
//    HASH_ADD_INT(hash, key, tmp);
//    int sum = 0, start = 0, len = 0;
//    for (int i = 0; i < arraySize; i++)
//    {
//        sum += array[i][0] <= '9' ? 1 : -1;
//        HASH_FIND_INT(hash, &sum, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (HashItem*)malloc(sizeof(HashItem));
//            tmp->key = sum;
//            tmp->val = i;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else
//        {
//            if (i - tmp->val > len)
//            {
//                start = tmp->val + 1;
//                len = i - tmp->val;
//            }
//        }
//    }
//    *returnSize = len;
//    return array + start;
//}
//
////3026. 最大好子数组和
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//long long maximumSubarraySum(int* nums, int numsSize, int k)
//{
//    HashItem* hash = NULL;
//    HashItem* tmp = NULL;
//    long long pre[numsSize + 1];
//    pre[0] = 0;
//    long long ans = LLONG_MIN;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i] - k, y = nums[i] + k;
//        pre[i + 1] = pre[i] + nums[i];
//        HASH_FIND_INT(hash, &x, tmp);
//        if (tmp)
//            ans = fmax(ans, pre[i + 1] - pre[tmp->val]);
//        HASH_FIND_INT(hash, &y, tmp);
//        if (tmp)
//            ans = fmax(ans, pre[i + 1] - pre[tmp->val]);
//        HASH_FIND_INT(hash, &nums[i], tmp);
//        if (tmp == NULL)
//        {
//            HashItem* tmp = (HashItem*)malloc(sizeof(HashItem));
//            tmp->key = nums[i];
//            tmp->val = i;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else if (pre[i] - pre[tmp->val] < 0)
//            tmp->val = i;
//    }
//    HashItem* s = NULL;
//    HASH_ITER(hh, hash, tmp, s)
//    {
//        HASH_DEL(hash, tmp);
//        free(tmp);
//    }
//    return ans == LLONG_MIN ? 0 : ans;
//}
//
////456. 132 模式
//
//bool find132pattern(int* nums, int numsSize)
//{
//    int pre[numsSize];
//    pre[0] = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        pre[i] = fmin(pre[i - 1], nums[i]);
//    }
//    int st[numsSize];
//    int top = -1;
//    for (int i = numsSize - 1; i >= 1; i--)
//    {
//        while (top >= 0 && st[top] < nums[i])
//        {
//            if (st[top--] > pre[i])
//                return true;
//        }
//        st[++top] = nums[i];
//    }
//    return false;
//}
//
