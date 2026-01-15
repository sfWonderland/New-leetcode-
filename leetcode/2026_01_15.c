////2943. 最大化网格图中正方形空洞的面积
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int f(int* nums, int n)
//{
//    qsort(nums, n, sizeof(int), cmp);
//    int cnt = 1, max = 1;
//    for (int i = 1; i < n; i++)
//    {
//        if (nums[i] == nums[i - 1] + 1)
//        {
//            cnt++;
//            max = fmax(max, cnt);
//        }
//        else
//            cnt = 1;
//    }
//    return max;
//}
//int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize)
//{
//    int len = fmin(f(hBars, hBarsSize), f(vBars, vBarsSize)) + 1;
//    return len * len;
//}
//
//int f(int* nums, int numsSize, int n)
//{
//    bool* map = (bool*)calloc(sizeof(bool), (n + 3));
//    for (int i = 0; i < numsSize; i++)
//    {
//        map[nums[i]] = true;
//    }
//    int max = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        if (map[x - 1])
//            continue;
//
//        int y = x + 1;
//        while (map[y])
//        {
//            y++;
//        }
//        max = fmax(max, y - x);
//    }
//    free(map);
//    return max;
//}
//int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize)
//{
//    int len = fmin(f(hBars, hBarsSize, n), f(vBars, vBarsSize, m)) + 1;
//    return len * len;
//}
//
////2028. 找出缺失的观测数据    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize)
//{
//    int tot = mean * (rollsSize + n);
//    for (int i = 0; i < rollsSize && tot >= n; i++)
//    {
//        tot -= rolls[i];
//    }
//    if (tot < n || tot > 6 * n)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int ave = tot / n, mod = tot % n;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = ave + (i < mod);
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3223. 操作后字符串的最短长度
//
//int minimumLength(char* s)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i])
//            ans += 2 - cnt[i] % 2;
//    }
//    return ans;
//}
//
////2526. 找到数据流中的连续整数
//
//typedef struct
//{
//    int value;
//    int k;
//    int cnt;
//} DataStream;
//
//
//DataStream* dataStreamCreate(int value, int k)
//{
//    DataStream* obj = (DataStream*)malloc(sizeof(DataStream));
//    obj->value = value;
//    obj->k = k;
//    obj->cnt = 0;
//    return obj;
//}
//
//bool dataStreamConsec(DataStream* obj, int num)
//{
//    obj->cnt = num != obj->value ? 0 : obj->cnt + 1;
//    return obj->cnt >= obj->k;
//}
//
//void dataStreamFree(DataStream* obj)
//{
//    free(obj);
//}
//
///**
// * Your DataStream struct will be instantiated and called as such:
// * DataStream* obj = dataStreamCreate(value, k);
// * bool param_1 = dataStreamConsec(obj, num);
//
// * dataStreamFree(obj);
//*/
//
