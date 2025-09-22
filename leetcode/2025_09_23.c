////165. 比较版本号
//
//int compareVersion(char* version1, char* version2)
//{
//    char* saveptr1 = NULL;
//    char* saveptr2 = NULL;
//    char* token1 = strtok_r(version1, ".", &saveptr1);
//    char* token2 = strtok_r(version2, ".", &saveptr2);
//    while (token1 != NULL || token2 != NULL)
//    {
//        int ver1 = token1 ? atoi(token1) : 0;
//        int ver2 = token2 ? atoi(token2) : 0;
//        if (ver1 != ver2)
//        {
//            return ver1 > ver2 ? 1 : -1;
//        }
//        token1 = strtok_r(NULL, ".", &saveptr1);
//        token2 = strtok_r(NULL, ".", &saveptr2);
//    }
//    return 0;
//}
//
////447. 回旋镖的数量
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize)
//{
//    if (pointsSize < 3)
//        return 0;
//    int ans = 0;
//    Hash* cnt = NULL;
//    Hash* tmp = NULL;
//    Hash* s = NULL;
//    for (int i = 0; i < pointsSize; i++)
//    {
//        HASH_ITER(hh, cnt, tmp, s)
//        {
//            HASH_DEL(cnt, tmp);
//        }
//        for (int j = 0; j < pointsSize; j++)
//        {
//            if (j == i)
//                continue;
//            int dx = points[i][0] - points[j][0];
//            int dy = points[i][1] - points[j][1];
//            int d2 = dx * dx + dy * dy;
//            HASH_FIND_INT(cnt, &d2, tmp);
//            if (tmp == NULL)
//            {
//                tmp = (Hash*)malloc(sizeof(Hash));
//                tmp->key = d2;
//                tmp->val = 1;
//                HASH_ADD_INT(cnt, key, tmp);
//            }
//            else
//                ans += (tmp->val++) * 2;
//        }
//    }
//    HASH_ITER(hh, cnt, tmp, s)
//    {
//        HASH_DEL(cnt, tmp);
//        free(tmp);
//    }
//    return ans;
//}
//
////560. 和为 K 的子数组
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//int subarraySum(int* nums, int numsSize, int k)
//{
//    int suf[numsSize + 1];
//    suf[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        suf[i + 1] = suf[i] + nums[i];
//    }
//    Hash* hash = NULL;
//    Hash* tmp = (Hash*)malloc(sizeof(Hash));
//    tmp->key = suf[0];
//    tmp->val = 1;
//    HASH_ADD_INT(hash, key, tmp);
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = suf[i + 1] - k;
//        HASH_FIND_INT(hash, &x, tmp);
//        if (tmp)
//        {
//            ans += tmp->val;
//        }
//
//        HASH_FIND_INT(hash, &suf[i + 1], tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = suf[i + 1];
//            tmp->val = 1;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else
//            tmp->val++;
//    }
//    Hash* s = NULL;
//    HASH_ITER(hh, hash, tmp, s)
//    {
//        HASH_DEL(hash, tmp);
//        free(tmp);
//    }
//    return ans;
//}
//
////1524. 和为奇数的子数组数目
//
//int numOfSubarrays(int* arr, int arrSize)
//{
//    const int MOD = 1e9 + 7;
//    int sum = 0;
//    int odd = 0, even = 1;
//    int ans = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        sum += arr[i];
//        if (sum & 1)
//        {
//            ans = (ans + even) % MOD;
//            odd++;
//        }
//        else
//        {
//            ans = (ans + odd) % MOD;
//            even++;
//        }
//    }
//    return ans;
//
//}
//
