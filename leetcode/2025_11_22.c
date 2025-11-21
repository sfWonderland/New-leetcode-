////1145. 二叉树着色游戏
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int x, int* lsz, int* rsz)
//{
//    if (node == NULL)
//        return 0;
//    int ls = dfs(node->left, x, lsz, rsz);
//    int rs = dfs(node->right, x, lsz, rsz);
//    if (node->val == x)
//    {
//        *lsz = ls;
//        *rsz = rs;
//    }
//    return ls + rs + 1;
//}
//bool btreeGameWinningMove(struct TreeNode* root, int n, int x)
//{
//    int lsz, rsz;
//    dfs(root, x, &lsz, &rsz);
//    int n2 = fmax(fmax(n - lsz - rsz - 1, lsz), rsz);
//    return 2 * n2 > n;
//}
//
////554. 砖墙
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int leastBricks(int** wall, int wallSize, int* wallColSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < wallSize; i++)
//    {
//        long long left = 0;
//        for (int j = 0; j < wallColSize[i] - 1; j++)
//        {
//            left += wall[i][j];
//            HASH_FIND_INT(cnt, &left, pEntry);
//            if (pEntry == NULL)
//            {
//                pEntry = (HashItem*)malloc(sizeof(HashItem));
//                pEntry->key = left;
//                pEntry->val = 1;
//                HASH_ADD_INT(cnt, key, pEntry);
//            }
//            else
//                pEntry->val++;
//        }
//    }
//    HashItem* tmp = NULL;
//    int slits = 0;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        slits = fmax(pEntry->val, slits);
//        free(pEntry);
//    }
//    return wallSize - slits;
//}
//
////3587. 最小相邻交换至奇偶交替
//
//int minTimes(int* nums, int n, bool flag)
//{
//    int idx = 0, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (nums[i] % 2 == flag)
//        {
//            ans += abs(i - idx);
//            idx += 2;
//        }
//    }
//    return ans;
//}
//int minSwaps(int* nums, int numsSize)
//{
//    int odd = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & 1)
//            odd++;
//    }
//    if (abs(2 * odd - numsSize) > 1)
//        return -1;
//    int a = 2 * odd >= numsSize ? minTimes(nums, numsSize, 1) : INT_MAX;
//    int b = numsSize >= 2 * odd ? minTimes(nums, numsSize, 0) : INT_MAX;
//    //printf("%d %d", a, b);
//    return fmin(a, b);
//}
//
//int minSwaps(int* nums, int numsSize)
//{
//    int* pos = (int*)malloc(sizeof(int) * numsSize);
//    int odd = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & 1)
//            pos[odd++] = i;
//    }
//    if (abs(2 * odd - numsSize) > 1)
//        return -1;
//    int minTimes(bool flag)
//    {
//        int ans = 0;
//        for (int i = 0; i < odd; i++)
//        {
//            ans += abs(2 * i + flag - pos[i]);
//        }
//        return ans;
//    }
//    int a = 2 * odd >= numsSize ? minTimes(0) : INT_MAX;
//    int b = numsSize >= 2 * odd ? minTimes(1) : INT_MAX;
//    free(pos);
//    return fmin(a, b);
//}
//
////3365. 重排子字符串以形成目标字符串
//
//int n;
//int cmp(const void* e1, const void* e2)
//{
//    return strncmp((char*)e1, (char*)e2, n);
//}
//bool isPossibleToRearrange(char* s, char* t, int k)
//{
//    int m = strlen(s);
//    n = m / k;
//    qsort(s, k, sizeof(char) * n, cmp);
//    qsort(t, k, sizeof(char) * n, cmp);
//    return strcmp(s, t) == 0;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return strcmp((*(char**)e1), (*(char**)e2));
//}
//bool isPossibleToRearrange(char* s, char* t, int k)
//{
//    int m = strlen(s);
//    int n = m / k;
//    char** s1 = (char**)malloc(sizeof(char*) * k);
//    char** s2 = (char**)malloc(sizeof(char*) * k);
//    for (int i = 0; i < k; i++)
//    {
//        s1[i] = &s[i * n];
//        s2[i] = &t[i * n];
//    }
//    qsort(s1, k, sizeof(char*), cmp);
//    qsort(s2, k, sizeof(char*), cmp);
//    for (int i = 0; i < k; i++)
//    {
//        if (strncmp(s1[i], s2[i], n))
//            return false;
//    }
//    return true;
//}
//
