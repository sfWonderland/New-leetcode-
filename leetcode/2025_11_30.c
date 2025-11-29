////1590. 使数组和能被 P 整除
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minSubarray(int* nums, int numsSize, int p)
//{
//    int x = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        x = (x + nums[i]) % p;
//    }
//    if (x == 0)
//        return 0;
//
//    int s = 0, ans = numsSize;
//    HashItem* map = NULL;
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = s;
//    pEntry->val = -1;
//    HASH_ADD_INT(map, key, pEntry);
//    for (int i = 0; i < numsSize; i++)
//    {
//        s = (s + nums[i]) % p;
//        HASH_FIND_INT(map, &s, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = s;
//            pEntry->val = i;
//            HASH_ADD_INT(map, key, pEntry);
//        }
//        else
//            pEntry->val = i;
//
//        int key_s = (s - x + p) % p;
//        HASH_FIND_INT(map, &key_s, pEntry);
//        if (pEntry)
//            ans = fmin(ans, i - pEntry->val);
//    }
//    return ans < numsSize ? ans : -1;
//}
//
////100916. 统计合格元素的数目
//
//int binary_search(int* nums, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (nums[mid] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int countElements(int* nums, int numsSize, int k)
//{
//    if (k == 0)
//        return numsSize;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int x = nums[numsSize - k];
//    return binary_search(nums, numsSize, x);
//}
//
////100864. 不同首字母的子字符串数目
//
//int maxDistinct(char* s)
//{
//    bool alpha[26] = { 0 };
//    int ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        ans += alpha[s[i] - 'a'] == 0;
//        alpha[s[i] - 'a'] = 1;
//    }
//    return ans;
//}
//
////100914. 镜像对之间最小绝对距离
//
//int reverse(int x)
//{
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", x);
//    int left = 0, right = strlen(s) - 1;
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//    return atoi(s);
//}
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minMirrorPairDistance(int* nums, int numsSize)
//{
//    int ans = numsSize;
//    HashItem* map = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        int x = reverse(nums[i]);
//        HASH_FIND_INT(map, &x, pEntry);
//        if (pEntry)
//            ans = fmin(ans, pEntry->val - i);
//        HASH_FIND_INT(map, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            pEntry->val = i;
//            HASH_ADD_INT(map, key, pEntry);
//        }
//        else
//            pEntry->val = i;
//    }
//    return ans < numsSize ? ans : -1;
//}
//
