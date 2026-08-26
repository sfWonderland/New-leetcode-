//// 1477. 找两个和为目标值且不重叠的子数组
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minSumOfLengths(int* arr, int arrSize, int target)
//{
//    HashItem* hash = NULL;
//    HashItem* p0 = (HashItem*)malloc(sizeof(HashItem));
//    p0->key = 0;
//    p0->val = -1;
//    HASH_ADD_INT(hash, key, p0);
//
//    int n = arrSize;
//    int pre = 0;
//    int ans = n + 1, minL = n;
//    for (int i = 0; i < n; i++)
//    {
//        pre += arr[i];
//        int x = pre - target;
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(hash, &x, p1);
//        if (p1)
//        {
//            int j = p1->val;
//            int len = i - j;
//            ans = fmin(ans, len + (j == -1 ? n : arr[j]));
//            minL = fmin(minL, len);
//        }
//        arr[i] = minL;
//        // printf("%d %d\n", minL, ans);
//        HashItem* p2 = (HashItem*)malloc(sizeof(HashItem));
//        p2->key = pre;
//        p2->val = i;
//        HASH_ADD_INT(hash, key, p2);
//    }
//
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, p0, tmp)
//    {
//        HASH_DEL(hash, p0);
//        free(p0);
//    }
//
//    return ans == n + 1 ? -1 : ans;
//}
//
//int minSumOfLengths(int* arr, int arrSize, int target)
//{
//    int n = arrSize;
//    int f[n + 1];
//    f[0] = n;
//    int ans = n + 1, sum = 0, left = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += arr[i];
//        while (sum > target)
//            sum -= arr[left++];
//
//        f[i + 1] = f[i];
//        if (sum == target)
//        {
//            int len = i - left + 1;
//            ans = fmin(ans, len + f[left]);
//            f[i + 1] = fmin(f[i + 1], len);
//        }
//    }
//
//    return ans == n + 1 ? -1 : ans;
//}
//
