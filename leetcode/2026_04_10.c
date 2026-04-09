////LCR 002. 二进制求和
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* addBinary(char* a, char* b)
//{
//    int m = strlen(a), n = strlen(b);
//    int len = fmax(m, n) + 1;
//    char* ans = (char*)malloc(sizeof(char) * (len + 1));
//    ans[len] = '\0';
//    int idx = 0;
//    int upgrade = 0, len2 = fmin(m, n);
//    int i = 0;
//    for (; i < len2; i++)
//    {
//        int sum = a[m - 1 - i] + b[n - 1 - i] + upgrade - 96;
//        ans[idx++] = (sum % 2) + '0';
//        upgrade = sum / 2;
//    }
//    int j = i;
//    //printf("%s!\n", ans);
//    while (a[j])
//    {
//        int sum = a[m - 1 - j] + upgrade - '0';
//        ans[idx++] = (sum % 2) + '0';
//        upgrade = sum / 2;
//        j++;
//    }
//    //printf("%s?\n", ans);
//    while (b[i])
//    {
//        int sum = b[n - 1 - i] + upgrade - '0';
//        ans[idx++] = (sum % 2) + '0';
//        upgrade = sum / 2;
//        i++;
//        //printf("%s\n", ans);
//    }
//    if (upgrade)
//        ans[idx++] = upgrade + '0';
//
//    ans[idx] = '\0';
//    reverse(ans, 0, idx - 1);
//    return ans;
//}
//
////LCR 004. 只出现一次的数字 II    
//
//int singleNumber(int* nums, int numsSize)
//{
//    int digits[64] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        int idx = 0;
//        long long x = nums[i];
//        if (nums[i] < 0)
//        {
//            idx += 32;
//            x = -x;
//        }
//        while (x)
//        {
//            digits[idx++] += x % 2;
//            x /= 2;
//        }
//    }
//    long long ans = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        // printf("%d ", digits[i]);
//        ans += (digits[i] % 3) << i;
//    }
//    if (ans) return ans;
//    for (int i = 32; i < 64; i++)
//    {
//        // printf("%d ", digits[i]);
//        ans += 1ll * (digits[i] % 3) << (i - 32);
//    }
//    return -ans;
//}
//
//// LCR 005. 最大单词长度乘积
//
//int maxProduct(char** words, int wordsSize)
//{
//    int n = wordsSize;
//    int map[n][2]; // mask, len
//    for (int i = 0; i < n; i++)
//    {
//        char* s = words[i];
//        int mask = 0, j = 0;
//        for (; s[j]; j++)
//        {
//            mask |= 1 << (s[j] - 'a');
//        }
//        map[i][0] = mask;
//        map[i][1] = j;
//    }
//
//    int ans = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            // printf("%x %x\n", map[i][0], map[j][0]);
//            if (map[i][0] & map[j][0])
//                continue;
//
//            ans = fmax(map[i][1] * map[j][1], ans);
//        }
//    }
//    return ans;
//}
//
//// LCR 006. 两数之和 II - 输入有序数组
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
//int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
//{
//    HashItem* map = NULL;
//    HashItem* p = NULL;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < numbersSize; i++)
//    {
//        int x = target - numbers[i];
//        if (x <= numbers[i])
//        {
//            HASH_FIND_INT(map, &x, p);
//            if (p)
//            {
//                ans[0] = p->val;
//                ans[1] = i;
//                break;
//            }
//        }
//        HASH_FIND_INT(map, &numbers[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = numbers[i];
//            p->val = i;
//            HASH_ADD_INT(map, key, p);
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, map, p, tmp)
//    {
//        HASH_DEL(map, p);
//        free(p);
//    }
//    *returnSize = 2;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
//{
//    int idx[2001];
//    memset(idx, 0x3f, sizeof(idx));
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < numbersSize; i++)
//    {
//        int x = target - numbers[i];
//        if (x <= numbers[i])
//        {
//            if (idx[x + 1000] != 0x3f3f3f3f)
//            {
//                ans[0] = idx[x + 1000];
//                ans[1] = i;
//                break;
//            }
//        }
//        if (idx[numbers[i] + 1000] == 0x3f3f3f3f)
//        {
//            idx[numbers[i] + 1000] = i;
//        }
//    }
//    *returnSize = 2;
//    return ans;
//}
//
