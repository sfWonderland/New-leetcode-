////443. 压缩字符串
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
//void get_len(char* s, int* i, int n)
//{
//    int idx = *i;
//    if (n == 1)
//        return;
//    while (n)
//    {
//        s[(*i)++] = n % 10 + '0';
//        n /= 10;
//    }
//    reverse(s, idx, (*i) - 1);
//}
//int compress(char* chars, int charsSize)
//{
//    char ch = chars[0];
//    int n = 1, idx = 1;
//    for (int i = 1; i < charsSize; i++)
//    {
//        if (ch == chars[i])
//            n++;
//        else
//        {
//            get_len(chars, &idx, n);
//            //printf("%d ", idx);
//            ch = chars[i];
//            chars[idx++] = ch;
//            n = 1;
//        }
//    }
//    get_len(chars, &idx, n);
//    //printf("%d ", idx);
//    return fmin(idx, charsSize);
//}
//
////1161. 最大层内元素和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxLevelSum(struct TreeNode* root)
//{
//    struct TreeNode* queue[10000];
//    int top = 0, bottom = 0;
//    int ans = 0, max = INT_MIN, rank = 0;
//    queue[top++] = root;
//    while (top > bottom)
//    {
//        rank++;
//        int start = bottom;
//        bottom = top;
//        int sum = 0;
//        for (int i = start; i < bottom; i++)
//        {
//            sum += queue[i]->val;
//            if (queue[i]->left) queue[top++] = queue[i]->left;
//            if (queue[i]->right) queue[top++] = queue[i]->right;
//        }
//        if (sum > max)
//        {
//            max = sum;
//            ans = rank;
//        }
//    }
//    return ans;
//}
//
////128. 最长连续序列
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int longestConsecutive(int* nums, int numsSize)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(hash, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            HASH_ADD_INT(hash, key, pEntry);
//        }
//    }
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        int x = pEntry->key;
//        int y = x - 1;
//        HASH_FIND_INT(hash, &y, pEntry);
//        if (pEntry)
//            continue;
//
//        y = x;
//        do
//        {
//            y++;
//            HASH_FIND_INT(hash, &y, pEntry);
//        } while (pEntry);
//        ans = fmax(ans, y - x);
//    }
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        HASH_DEL(hash, pEntry);
//        free(pEntry);
//    }
//    return ans;
//}
//
////LCR 187. 破冰游戏
//
//int iceBreakingGame(int num, int target)
//{
//    int ans = 0; //dp[n, m] = 0, n = 1, m = target
//    for (int i = 2; i <= num; i++)
//    {
//        ans = (ans + target) % i; //dp[n, m] = (dp[n - 1, m] + m) % n
//    }
//    return ans;
//}
//
