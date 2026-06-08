//// 3959. 判定好整数
//
//bool checkGoodInteger(int n)
//{
//    int digitSum = 0, squareSum = 0;
//    while (n)
//    {
//        int x = n % 10;
//        digitSum += x;
//        squareSum += x * x;
//        n /= 10;
//    }
//    return squareSum - digitSum >= 50;
//}
//
//// 3960. 频率平衡子数组    
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int getLongest(int* nums, int n)
//{
//    int* cnt = (int*)calloc(sizeof(int), n + 1);
//    HashItem* freq = NULL;
//    HashItem* p1 = NULL;
//    int ans = 0, mx = 0, diff = 0;
//    for (int i = 0; i < n; i++)
//    {
//        HASH_FIND_INT(freq, &nums[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = nums[i];
//            p1->val = 0;
//            HASH_ADD_INT(freq, key, p1);
//            diff++;
//        }
//        cnt[p1->val]--;
//        p1->val++;
//        cnt[p1->val]++;
//        mx = fmax(mx, p1->val);
//        if (diff == 1)
//            ans = i + 1;
//
//        if (mx % 2)
//            continue;
//        if (cnt[mx / 2] && cnt[mx] * mx + cnt[mx / 2] * mx / 2 == i + 1)
//            ans = i + 1;
//    }
//    free(cnt);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, freq, p1, tmp)
//    {
//        HASH_DEL(freq, p1);
//        free(p1);
//    }
//    return ans;
//}
//int getLength(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans = fmax(getLongest(nums + i, numsSize - i), ans);
//    }
//    return ans;
//}
//
//// 100783. 设备评分的最大和
//
//long long maxRatings(int** units, int unitsSize, int* unitsColSize)
//{
//    long long ans = 0;
//    bool flag = false;
//    int total_min = INT_MAX, total_inferior = INT_MAX;
//    for (int i = 0; i < unitsSize; i++)
//    {
//        int m = unitsColSize[i];
//        if (m == 1)
//        {
//            if (units[i][0] < total_min)
//            {
//                total_min = units[i][0];
//                flag = true;
//            }
//            if (units[i][0] < total_inferior)
//                total_inferior = units[i][0];
//
//            ans += units[i][0];
//            continue;
//        }
//        int min = INT_MAX, inferior = INT_MAX;
//        for (int j = 0; j < m; j++)
//        {
//            if (units[i][j] < min)
//            {
//                inferior = min;
//                min = units[i][j];
//            }
//            else if (units[i][j] < inferior)
//                inferior = units[i][j];
//        }
//        if (min < total_min)
//        {
//            total_min = min;
//            flag = false;
//        }
//        if (inferior < total_inferior)
//            total_inferior = inferior;
//
//        ans += inferior;
//    }
//
//    return flag ? ans : ans - total_inferior + total_min;
//}
//
