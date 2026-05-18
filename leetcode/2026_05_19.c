//// 面试题 16.21. 交换和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//void free_hash(HashItem** hash)
//{
//    HashItem* nums = *hash;
//    HashItem* p1 = NULL, * tmp = NULL;
//    HASH_ITER(hh, nums, p1, tmp)
//    {
//        HASH_DEL(nums, p1);
//        free(p1);
//    }
//}
//int* findSwapValues(int* array1, int array1Size, int* array2, int array2Size, int* returnSize)
//{
//    int sum = 0;
//    HashItem* nums = NULL;
//    for (int i = 0; i < array1Size; i++)
//    {
//        sum += array1[i];
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(nums, &array1[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = array1[i];
//            HASH_ADD_INT(nums, key, p1);
//        }
//    }
//    for (int i = 0; i < array2Size; i++)
//    {
//        sum -= array2[i];
//    }
//    if (sum & 1)
//    {
//        *returnSize = 0;
//        free_hash(&nums);
//        return NULL;
//    }
//    int d = sum / 2;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    *returnSize = 2;
//    for (int i = 0; i < array2Size; i++)
//    {
//        int x = array2[i] + d;
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(nums, &x, p1);
//        if (p1)
//        {
//            ans[0] = x;
//            ans[1] = array2[i];
//            free_hash(&nums);
//            return ans;
//        }
//    }
//    free_hash(&nums);
//    *returnSize = 0;
//    return NULL;
//}
//
//// 面试题 16.26. 计算器    
//
//int calculate(char* s)
//{
//    int n = strlen(s);
//    int* nums = (int*)malloc(sizeof(int) * n);
//    char* syms = (char*)malloc(sizeof(char) * n);
//    int topN = 0, topS = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        if (s[i] == ' ')
//            continue;
//        else if (s[i] >= '0')
//        {
//            if (i > 0 && s[i - 1] >= '0')
//                nums[topN - 1] = nums[topN - 1] * 10 - '0' + s[i];
//            else
//                nums[topN++] = s[i] - '0';
//        }
//        else
//        {
//            if ((s[i] == '\0' || s[i] == '+' || s[i] == '-') && topS > 0)
//            {
//                while (topS > 0)
//                {
//                    if (syms[topS - 1] == '*')
//                        nums[topN - 2] *= nums[topN - 1];
//                    else if (syms[topS - 1] == '/')
//                        nums[topN - 2] /= nums[topN - 1];
//                    else if (syms[topS - 1] == '+')
//                        nums[topN - 2] += nums[topN - 1];
//                    else
//                        nums[topN - 2] -= nums[topN - 1];
//
//                    topN--;
//                    topS--;
//                }
//            }
//            else if (topS > 0 && (syms[topS - 1] == '*' || syms[topS - 1] == '/'))
//            {
//                while (topS > 0 && (syms[topS - 1] == '*' || syms[topS - 1] == '/'))
//                {
//                    if (syms[topS - 1] == '*')
//                        nums[topN - 2] *= nums[topN - 1];
//                    else
//                        nums[topN - 2] /= nums[topN - 1];
//
//                    topN--;
//                    topS--;
//                }
//            }
//            syms[topS++] = s[i];
//        }
//    }
//
//    return nums[0];
//}
//
//// 面试题 17.04. 消失的数字
//
//int missingNumber(int* nums, int numsSize)
//{
//    int sum = numsSize * (numsSize + 1) / 2;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum -= nums[i];
//    }
//    return sum;
//}
//
//// 面试题 17.06. 2出现的次数
//
//int numberOf2sInRange(int n)
//{
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    int memo[m][m];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i, int cnt, bool is_limit)
//    {
//        if (i == m)
//            return cnt;
//        if (!is_limit && memo[i][cnt] != 0x3f3f3f3f)
//            return memo[i][cnt];
//
//        int res = 0;
//        int up = is_limit ? s[i] - '0' : 9;
//        for (int d = 0; d <= up; d++)
//        {
//            res += dfs(i + 1, cnt + (d == 2), is_limit && d == up);
//        }
//        if (!is_limit)
//            memo[i][cnt] = res;
//
//        return res;
//    }
//
//    return dfs(0, 0, true);
//}
//
