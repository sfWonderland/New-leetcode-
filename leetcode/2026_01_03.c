////1411. 给 N x 3 网格图涂色的方案数
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//const int MOD = 1e9 + 7;
//int numOfWays(int n)
//{
//    HashItem* memo = NULL;
//    // (i, j)：当前位置 
//    // pre_row：上一行（i+1 行）的颜色
//    // cur_row：当前这一行已填入的颜色
//    // 每种颜色用两个二进制位映射
//    int dfs(int i, int j, int pre_row, int cur_row)
//    {
//        if (i == 0)
//            return 1;
//
//        if (j == 3)
//            return dfs(i - 1, 0, cur_row, 0);
//
//        int key = (i << 14) | (j << 12) | (pre_row << 6) | cur_row;
//        HashItem* pEntry = NULL;
//        HASH_FIND_INT(memo, &key, pEntry);
//        if (pEntry) return pEntry->val;
//
//        int res = 0;
//        for (int color = 0; color < 3; color++)
//        {
//            if (pre_row > 0 && color == (pre_row >> (j * 2) & 3)
//                || j > 0 && color == (cur_row >> ((j - 1) * 2) & 3))
//                continue;
//            res = (res + dfs(i, j + 1, pre_row, cur_row | (color << (2 * j)))) % MOD;
//        }
//
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = key;
//        pEntry->val = res;
//        HASH_ADD_INT(memo, key, pEntry);
//        return res;
//    }
//    return dfs(n, 0, 0, 0);
//}
//
//// Berlekamp-Massey 算法
//// 由方法一得f(1) = 12, f(2) = 54, f(3) = 246, f(4) = 1122, f(5) = 5118;
//// 由f(1) = 12, f(2) = 54，设f(n) = 4.5 * f(n - 1)
//// 发现f(3) = 4.5 * f(2) + 3, 代入f(1) = 12, 得f(3) = 4.5 * f(2) + 0.25 * f(1);
//// 发现f(4) = 4.5 * f(3) + 0.25 * f(2) + 1.5, 代入 f(3) - 4.5 * f(2) = 3
//// 得f(4) = 5 * f(3) - 2 * f(2); 代入f(5)该式子仍成立
//// 故f[n] = 5 * f[n - 1] - 2 * f[n - 2];
//const int MOD = 1e9 + 7;
//int numOfWays(int n)
//{
//    int f[n + 1];
//    f[0] = 3; f[1] = 12;
//    for (int i = 2; i <= n; i++)
//    {
//        f[i] = (5ll * f[i - 1] - 2ll * f[i - 2]) % MOD;
//    }
//    return (f[n] + MOD) % MOD;
//}
//
////1540. K 次操作转变字符串    
//
//bool canConvertString(char* s, char* t, int k)
//{
//    int n = strlen(s);
//    if (strlen(t) != n)
//        return false;
//    int cnt[26] = { 0 };
//    int max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int turns = (t[i] - s[i] + 26) % 26;
//        cnt[turns]++;
//        if (turns)
//            max = fmax(max, cnt[turns] * 26 - 26 + turns);
//    }
//    return max <= k;
//}
//
////916. 单词子集
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; i < words2Size; i++)
//    {
//        int cnt1[26] = { 0 };
//        for (int j = 0; words2[i][j]; j++)
//        {
//            cnt1[words2[i][j] - 'a']++;
//        }
//        for (int j = 0; j < 25; j++)
//        {
//            if (cnt[j] < cnt1[j])
//                cnt[j] = cnt1[j];
//        }
//    }
//    char** ans = (char**)malloc(sizeof(char*) * words1Size);
//    int k = 0; // ansSize
//    for (int i = 0; i < words1Size; i++)
//    {
//        int cnt1[26];
//        memcpy(cnt1, cnt, sizeof(int) * 26);
//        for (int j = 0; words1[i][j]; j++)
//        {
//            cnt1[words1[i][j] - 'a']--;
//        }
//        int j;
//        for (j = 0; j < 26; j++)
//        {
//            if (cnt1[j] > 0)
//                break;
//        }
//        if (j == 26)
//            ans[k++] = words1[i];
//    }
//    *returnSize = k;
//    return ans;
//}
//
////1300. 转变数组后最接近目标值的数组和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findBestValue(int* arr, int arrSize, int target)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int pre = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        if (i > 0 && arr[i] == arr[i - 1])
//        {
//            pre += arr[i];
//            continue;
//        }
//        int ave = (target - pre) / (arrSize - i);
//        if (ave < arr[i])
//        {
//            return 2 * (target - pre) > (2 * ave + 1) * (arrSize - i) ? ave + 1 : ave;
//        }
//        pre += arr[i];
//    }
//    return arr[arrSize - 1];
//}
//
