////2023. 连接后等于目标字符串的字符串对
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int numOfPairs(char** nums, int numsSize, char* target)
//{
//    HashItem* cnt = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HashItem* p1 = NULL;
//        HASH_FIND_STR(cnt, nums[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = nums[i];
//            p1->val = 0;
//            HASH_ADD_STR(cnt, key, p1);
//        }
//        p1->val++;
//    }
//    int n = strlen(target);
//    char* s = (char*)calloc(sizeof(char), (n + 1));
//    char* t = (char*)malloc(sizeof(char) * (n + 1));
//    int ans = 0;
//    strcpy(t, target);
//    for (int i = 1; i < n; i++)
//    {
//        s[i - 1] = target[i - 1];
//        // printf("%s\n%s\n", s, t + i);
//        HashItem* p1 = NULL;
//        HashItem* p2 = NULL;
//        HASH_FIND_STR(cnt, s, p1);
//        HASH_FIND_STR(cnt, t + i, p2);
//        if (p1 && p2)
//        {
//            if (strcmp(s, t + i) == 0)
//                ans += p1->val * (p1->val - 1);
//            else
//                ans += p1->val * p2->val;
//        }
//    }
//    free(s);
//    free(t);
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    return ans;
//}
//
////2104. 子数组范围和    
//
//long long subArrayRanges(int* nums, int numsSize)
//{
//    long long ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int min = INT_MAX, max = INT_MIN;
//        for (int j = i; j < numsSize; j++)
//        {
//            min = fmin(min, nums[j]);
//            max = fmax(max, nums[j]);
//            ans += max - min;
//        }
//    }
//    return ans;
//}
//
////2150. 找出数组中的所有孤独数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* findLonely(int* nums, int numsSize, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i > 0 && (nums[i - 1] == nums[i] || nums[i - 1] == nums[i] - 1))
//            continue;
//        if (i < numsSize - 1 && (nums[i + 1] == nums[i] || nums[i + 1] == nums[i] + 1))
//            continue;
//        ans[idx++] = nums[i];
//    }
//    *returnSize = idx;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findLonely(int* nums, int numsSize, int* returnSize)
//{
//    int cnt[1000003] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i] + 1]++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (cnt[nums[i] + 1] > 1 || cnt[nums[i]] || cnt[nums[i] + 2])
//            continue;
//        ans[idx++] = nums[i];
//    }
//    *returnSize = idx;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findLonely(int* nums, int numsSize, int* returnSize)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, nums[i]);
//    }
//    int cnt[max + 3];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i] + 1]++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (cnt[nums[i] + 1] > 1 || cnt[nums[i]] || cnt[nums[i] + 2])
//            continue;
//        ans[idx++] = nums[i];
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////2155. 分组得分最高的所有下标
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* maxScoreIndices(int* nums, int numsSize, int* returnSize)
//{
//    int scores[numsSize + 1];
//    int right = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        right += nums[i];
//    }
//    scores[0] = right;
//    int max = right, left = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        left += 1 - nums[i];
//        right -= nums[i];
//        scores[i + 1] = left + right;
//        max = fmax(max, scores[i + 1]);
//    }
//    int* ans = (int*)malloc(sizeof(int) * (numsSize + 1));
//    int idx = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        if (max == scores[i])
//            ans[idx++] = i;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* maxScoreIndices(int* nums, int numsSize, int* returnSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    int max = sum, cnt = 0;
//    int* ans = (int*)malloc(sizeof(int) * (numsSize + 1));
//    ans[cnt++] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i] ? -1 : 1;
//        if (sum > max)
//        {
//            max = sum;
//            cnt = 0;
//            ans[cnt++] = i + 1;
//        }
//        else if (sum == max)
//            ans[cnt++] = i + 1;
//    }
//    *returnSize = cnt;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* maxScoreIndices(int* nums, int numsSize, int* returnSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    int max = sum, cnt = 0;
//    int candidates[numsSize + 1];
//    candidates[cnt++] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i] ? -1 : 1;
//        if (sum > max)
//        {
//            max = sum;
//            cnt = 0;
//            candidates[cnt++] = i + 1;
//        }
//        else if (sum == max)
//            candidates[cnt++] = i + 1;
//    }
//    int* ans = (int*)malloc(sizeof(int) * cnt);
//    for (int i = 0; i < cnt; i++)
//    {
//        ans[i] = candidates[i];
//    }
//    *returnSize = cnt;
//    return ans;
//}
//
