////955. 删列造序 II
//
//int minDeletionSize(char** strs, int strsSize)
//{
//    int ans = 0;
//    int m = strsSize, n = strlen(strs[0]);
//    char** pre = (char**)malloc(sizeof(char*) * m);
//    int k = 0;
//    for (int i = 0; i < m; i++)
//    {
//        pre[i] = (char*)calloc(sizeof(int), n);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        bool flag = false;
//        int j = 1;
//        for (; j < m; j++)
//        {
//            pre[j - 1][k] = strs[j - 1][i];
//            pre[j][k] = strs[j][i];
//            if (strncmp(pre[j - 1], pre[j], k + 1) > 0)
//            {
//                flag = true;
//                ans++;
//                break;
//            }
//        }
//        if (!flag)
//            k++;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        free(pre[i]);
//    }
//    free(pre);
//    return ans;
//}
//
////100942. 整数的镜像距离
//
//int mirrorDistance(int n)
//{
//    int reverse = 0;
//    int tmp = n;
//    while (tmp)
//    {
//        reverse *= 10;
//        reverse += tmp % 10;
//        tmp /= 10;
//    }
//    return abs(n - reverse);
//}
//
////100913. 使所有字符相等的最小删除代价
//
//long long minCost(char* s, int* cost, int costSize)
//{
//    long long cnt[26] = { 0 };
//    long long sum = 0;
//    long long max = LLONG_MIN;
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a'] += cost[i];
//        max = fmax(max, cnt[s[i] - 'a']);
//        sum += cost[i];
//    }
//
//    return sum - max;
//}
//
////100838. 避免禁用值的最小交换次数
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minSwaps(int* nums, int numsSize, int* forbidden, int forbiddenSize)
//{
//    HashItem* total = NULL;
//    HashItem* pEntry = NULL;
//    int n = numsSize;
//    for (int i = 0; i < n; i++)
//    {
//        HASH_FIND_INT(total, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            pEntry->val = 1;
//            HASH_ADD_INT(total, key, pEntry);
//        }
//        else
//            pEntry->val++;
//    }
//    HashItem* cnt = NULL;
//    int k = 0, mx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        HASH_FIND_INT(total, &forbidden[i], pEntry);
//        if (pEntry)
//        {
//            pEntry->val++;
//            //如果某个数 x 在 nums 和 forbidden 中总出现次数超过 n，那么根据鸽巢原理（抽屉原理），必然有一列都是 x，此时无解。比如示例 3 有 3 个 7，3 > n。
//            if (pEntry->val > n)
//                return -1;
//        }
//
//        if (nums[i] == forbidden[i])
//        {
//            HASH_FIND_INT(cnt, &forbidden[i], pEntry);
//            if (pEntry == NULL)
//            {
//                pEntry = (HashItem*)malloc(sizeof(HashItem));
//                pEntry->key = forbidden[i];
//                pEntry->val = 1;
//                HASH_ADD_INT(cnt, key, pEntry);
//            }
//            else
//                pEntry->val++;
//
//            k++;
//            mx = fmax(mx, pEntry->val);
//        }
//    }
//    return fmax((k + 1) / 2, mx);
//}
//
