////3349. 检测相邻递增子数组 I
//
//bool hasIncreasingSubarrays(int* nums, int numsSize, int k)
//{
//    if (k == 1 && numsSize >= 2)
//        return true;
//    int start[2] = { 0, -1 }, n = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (i - start[n] == 2 * k)
//            return true;
//        if (nums[i] <= nums[i - 1])
//        {
//            if (i - start[n] >= k)
//            {
//                if (n == 1)
//                    return true;
//                start[n++] = i - k;
//                start[n] = i;
//            }
//            else
//            {
//                n = 0;
//                start[n] = i;
//            }
//        }
//    }
//    return n == 1 && numsSize >= start[1] + k || numsSize - start[0] == 2 * k;
//}
//
//bool hasIncreasingSubarrays(int* nums, int numsSize, int k)
//{
//    int len = 0, cnt = 0, pre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt++;
//        if (i == numsSize - 1 || nums[i] >= nums[i + 1])
//        {
//            len = fmax(len, fmax(cnt / 2, fmin(pre, cnt)));
//            pre = cnt;
//            cnt = 0;
//        }
//    }
//    return len >= k;
//}
//
////3350. 检测相邻递增子数组 II
//
//int maxIncreasingSubarrays(int* nums, int numsSize)
//{
//    int ans = 0, cnt = 0, pre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt++;
//        if (i == numsSize - 1 || nums[i] >= nums[i + 1])
//        {
//            ans = fmax(ans, fmax(cnt / 2, fmin(pre, cnt)));
//            pre = cnt;
//            cnt = 0;
//        }
//    }
//    return ans;
//}
//
////2788. 按分隔符拆分字符串
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** splitWordsBySeparator(char** words, int wordsSize, char separator, int* returnSize)
//{
//    char** ans = (char**)malloc(sizeof(char*) * 1000);
//    int n = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int left = 0, m = strlen(words[i]);
//        while (left < m && words[i][left] == separator)
//            left++;
//        for (int j = 0; j <= m; j++)
//        {
//            if ((words[i][j] == separator || words[i][j] == '\0') && j > left)
//            {
//                ans[n] = (char*)malloc(sizeof(char) * (j - left + 1));
//                strncpy(ans[n], &words[i][left], j - left);
//                ans[n][j - left] = '\0';
//                left = j + 1;
//                while (left < m && words[i][left] == separator)
//                    left++;
//                n++;
//            }
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////2085. 统计出现过一次的公共字符串
//
//typedef struct
//{
//    char* key;
//    int val1;
//    int val2;
//    UT_hash_handle hh;
//}HashItem;
//
//int countWords(char** words1, int words1Size, char** words2, int words2Size)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < words1Size; i++)
//    {
//        HASH_FIND_STR(hash, words1[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (strlen(words1[i]) + 1));
//            strcpy(pEntry->key, words1[i]);
//            pEntry->val1 = 1;
//            pEntry->val2 = 0;
//            HASH_ADD_STR(hash, key, pEntry);
//        }
//        else
//            pEntry->val1++;
//    }
//    for (int i = 0; i < words2Size; i++)
//    {
//        HASH_FIND_STR(hash, words2[i], pEntry);
//        if (pEntry)
//            pEntry->val2++;
//    }
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        if (pEntry->val1 == 1 && pEntry->val2 == 1)
//            ans++;
//        HASH_DEL(hash, pEntry);
//        free(pEntry);
//    }
//    return ans;
//}
//
