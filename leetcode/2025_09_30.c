////2221. 数组的三角和
//
//int triangularSum(int* nums, int numsSize)
//{
//    while (numsSize > 1)
//    {
//        for (int i = 0; i < numsSize - 1; i++)
//        {
//            nums[i] = (nums[i] + nums[i + 1]) % 10;
//        }
//        numsSize--;
//    }
//    return nums[0];
//}
//
////151. 反转字符串中的单词
//
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//char* reverseWords(char* s)
//{
//    int i = 0, n = 0;
//    while (s[i] == ' ')
//        i++;
//    bool repeat = false;
//    for (; s[i]; i++)
//    {
//        if (s[i] == ' ')
//        {
//            if (!repeat)
//            {
//                s[n++] = s[i];
//                repeat = true;
//            }
//        }
//        else
//        {
//            s[n++] = s[i];
//            repeat = false;
//        }
//    }
//    if (s[n - 1] == ' ')
//        n--;
//    s[n] = '\0';
//    reverse(s, 0, n - 1);
//    int left = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == ' ')
//        {
//            reverse(s, left, i - 1);
//            left = i + 1;
//        }
//    }
//    reverse(s, left, n - 1);
//    return s;
//}
//
////290. 单词规律
//
//bool wordPattern(char* pattern, char* s)
//{
//    char* hash[26] = { NULL };
//    int left = 0;
//    for (int i = 0; pattern[i]; i++)
//    {
//        if (!s[left])
//            return false;
//        int x = pattern[i] - 'a';
//        if (hash[x] == NULL)
//        {
//            hash[x] = s + left;
//            int j = left;
//            for (; s[j]; j++)
//            {
//                if (s[j] == ' ')
//                {
//                    break;
//                }
//            }
//            left = j;
//            if (s[j])
//            {
//                s[j] = '\0';
//                left++;
//            }
//        }
//        else
//        {
//            char* sub = s + left;
//            int j = left;
//            for (; s[j]; j++)
//            {
//                if (s[j] == ' ')
//                {
//                    break;
//                }
//            }
//            left = j;
//            if (s[j])
//            {
//                s[j] = '\0';
//                left++;
//            }
//            if (strcmp(hash[x], sub) != 0)
//                return false;
//        }
//    }
//    if (s[left])
//        return false;
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash[i] == NULL)
//            continue;
//        for (int j = 0; j < 26; j++)
//        {
//            if (i == j || hash[j] == NULL)
//                continue;
//
//            if (strcmp(hash[i], hash[j]) == 0)
//                return false;
//        }
//    }
//    return true;
//}
//
////2215. 找出两数组的不同
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    bool val;
//    UT_hash_handle hh;
//}HashItem;
//int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes)
//{
//    HashItem* hash1 = NULL;
//    HashItem* hash2 = NULL;
//    HashItem* tmp = NULL;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        HASH_FIND_INT(hash1, &nums1[i], tmp);
//        if (tmp == NULL)
//        {
//            tmp = (HashItem*)malloc(sizeof(HashItem));
//            tmp->key = nums1[i];
//            tmp->val = true;
//            HASH_ADD_INT(hash1, key, tmp);
//        }
//    }
//    for (int i = 0; i < nums2Size; i++)
//    {
//        HASH_FIND_INT(hash1, &nums2[i], tmp);
//        if (tmp == NULL)
//        {
//            HASH_FIND_INT(hash2, &nums2[i], tmp);
//            if (tmp == NULL)
//            {
//                tmp = (HashItem*)malloc(sizeof(HashItem));
//                tmp->key = nums2[i];
//                tmp->val = true;
//                HASH_ADD_INT(hash2, key, tmp);
//            }
//        }
//        else
//            tmp->val = false;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * 2);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
//    ans[0] = (int*)malloc(sizeof(int) * nums1Size);
//    int idx1 = 0;
//    ans[1] = (int*)malloc(sizeof(int) * nums2Size);
//    int idx2 = 0;
//    HashItem* s = NULL;
//    HASH_ITER(hh, hash1, tmp, s)
//    {
//        if (tmp->val)
//            ans[0][idx1++] = tmp->key;
//        HASH_DEL(hash1, tmp);
//        free(tmp);
//    }
//    HASH_ITER(hh, hash2, tmp, s)
//    {
//        ans[1][idx2++] = tmp->key;
//        HASH_DEL(hash2, tmp);
//        free(tmp);
//    }
//    (*returnColumnSizes)[0] = idx1;
//    (*returnColumnSizes)[1] = idx2;
//    *returnSize = 2;
//    return ans;
//}
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes)
//{
//    int hash1[2001] = { 0 };
//    bool hash2[2001] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        hash1[nums1[i] + 1000] = 1;
//    }
//    for (int i = 0; i < nums2Size; i++)
//    {
//        if (hash1[nums2[i] + 1000])
//        {
//            hash1[nums2[i] + 1000] = -1;
//        }
//        else
//            hash2[nums2[i] + 1000] = true;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * 2);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
//    ans[0] = (int*)malloc(sizeof(int) * nums1Size);
//    ans[1] = (int*)malloc(sizeof(int) * nums2Size);
//    int idx1 = 0, idx2 = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        if (hash1[nums1[i] + 1000] > 0)
//        {
//            ans[0][idx1++] = nums1[i];
//            hash1[nums1[i] + 1000] = 0;
//        }
//    }
//    (*returnColumnSizes)[0] = idx1;
//    for (int i = 0; i < nums2Size; i++)
//    {
//        if (hash2[nums2[i] + 1000])
//        {
//            ans[1][idx2++] = nums2[i];
//            hash2[nums2[i] + 1000] = 0;
//        }
//    }
//    (*returnColumnSizes)[1] = idx2;
//    *returnSize = 2;
//    return ans;
//}
//
