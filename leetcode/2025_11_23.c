////100910. 连接非零数字并乘以其数字和 I
//
//long long sumAndMultiply(int n)
//{
//    long long ans = 0;
//    long long base = 1;
//    int sum = 0;
//    while (n)
//    {
//        int x = n % 10;
//        if (x)
//        {
//            sum += x;
//            ans += base * x;
//            base *= 10;
//        }
//        n /= 10;
//    }
//    return ans * sum;
//}
//
////3755. 最大平衡异或子数组的长度
//
//typedef struct
//{
//    long long key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int maxBalancedSubarray(int* nums, int numsSize)
//{
//    int n = numsSize;
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    pEntry = (HashItem*)malloc(sizeof(HashItem));
//    int xor = 0, diff = n, ans = 0; // 保证diff非负
//    pEntry->key = 1ll * xor << 32 | diff;
//    pEntry->val = -1;
//    HASH_ADD(hh, cnt, key, sizeof(long long), pEntry);
//    for (int i = 0; i < n; i++)
//    {
//        xor = xor ^nums[i];
//        diff += nums[i] % 2 ? 1 : -1;
//        long long key = (1ll * xor << 32) | diff;
//        HASH_FIND(hh, cnt, &key, sizeof(long long), pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = key;
//            pEntry->val = i;
//            HASH_ADD(hh, cnt, key, sizeof(long long), pEntry);
//        }
//        else
//            ans = fmax(ans, i - pEntry->val);
//    }
//    return ans;
//}
//
////3728. 边界与内部和相等的稳定子数组
//
//struct Node
//{
//    long long sum;
//    int first;
//};
//typedef struct
//{
//    struct Node key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//long long countStableSubarrays(int* capacity, int capacitySize)
//{
//    int n = capacitySize;
//    long long sum = capacity[0];
//    long long ans = 0;
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    for (int r = 1; r < n; r++)
//    {
//        struct Node findKey = { sum, capacity[r] };
//        HASH_FIND(hh, cnt, &findKey, sizeof(struct Node), pEntry);
//        if (pEntry)
//            ans += pEntry->val;
//
//        struct Node addKey = { capacity[r - 1] + sum, capacity[r - 1] };
//        HASH_FIND(hh, cnt, &addKey, sizeof(struct Node), pEntry);
//        if (pEntry)
//            pEntry->val++;
//        else
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = addKey;
//            pEntry->val = 1;
//            HASH_ADD(hh, cnt, key, sizeof(struct Node), pEntry);
//        }
//        sum += capacity[r];
//    }
//    return ans;
//}
//
////面试题 05.01. 插入
//
//// int insertBits(int N, int M, int i, int j) 
//// {
////     int t = 0xfffffffff;
////     for(int k = i; k <= j; k++)
////     {
////         t &= ~((unsigned int)1 << k);
////     }    
////     N &= t;
////     N |= M << i;
////     return N;
//// }
//
//int insertBits(int N, int M, int i, int j)
//{
//    return (N & ~(((1ul << (j - i + 1)) - 1) << i)) | (M << i);
//}
//
